/*====================================================================
 * Description: Generate the random number, create a file and store 
 * the number, if the file exist, delete it first.
 * The range of random file from [1 - specified by argument]
 * Read and write the file by line.
 * TODO: all number read and write from the same line.
 * DATE: 2014/06/03
 * Modify:
 * Conclusion:
===================================================================*/
/* include */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/* Macro definition */
#define false           0
#define true            1

/* file name in current directory to store the random number */
#define RANDOM_STORE    "random.number"
#define RANDOM_LOW      1

int
print_random_number(char *name)
{
    FILE* fp = NULL;
    char line[32];

    fp = fopen(name, "r");
    if (fp == NULL) {
        fprintf(stderr, "Fail to open file %s\n", name);
        exit(1);
    }
    else {
        while(fgets(line, sizeof(line), fp) != NULL) {
            printf("%d ", atoi(line));
        }
        fclose(fp);
    }
    printf("\n");
    return 0;
}

/* get from ../system/A_random.c */
unsigned int
get_random_number(unsigned int low_limit, unsigned int up_limit)
{
    char *random_byte;
    unsigned int random;
    static int random_fd = -1;
    size_t size = sizeof(random);

    /* just use open and read it as it is a file */
    /* use /dev/random to generate random based on the input interval(key board or mouse)
     * so it may blocked if there no input. */
    random_fd = open("/dev/random", O_RDONLY);
    if (random_fd == -1) {
        /* /dev/urandom also generate random number, but not so 'random' as this one */
        fprintf(stderr, "Open /dev/random failed\n");
        return 0;
    }
    else {
        random_byte = (char*)&random;
        do {
            int read_byte;
            read_byte = read(random_fd, random_byte, size);
            size -= read_byte;
            random_byte += read_byte;
        }
        while(size >0);
    }
    random = low_limit + (random % (up_limit-low_limit+1));
//    printf("Get random between %d-%d is %d\n", up_limit, low_limit, random);
    return random;
}


int
main(int argc, char **argv)
{
    int fd = -1;
    char *random_byte;
    unsigned int random, up_num;
    size_t size = sizeof(random);
    int i,n;
    char buf[32];

    if (argc < 2) {
        fprintf(stderr, "Please specified the up limit of the random number.\n");
        exit(1);
    }
    up_num = atoi(argv[1]);

    for (i=0; i<up_num; i++) {   
        if ((random = get_random_number(RANDOM_LOW, up_num)) == 0) {
            fprintf(stderr, "Get random number failed\n");
            exit(1);
        }
        fd = open(RANDOM_STORE, O_RDWR|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
        if (fd == -1) {
            fprintf(stderr, "Fail to open file %s\n", RANDOM_STORE);
            exit(1);
        }
        else {
            sprintf(buf, "%d\n", random);
            n = strlen(buf);
            write(fd, buf, n); 
        }
    }
    close(fd);

    print_random_number(RANDOM_STORE);

    return 0;
}

