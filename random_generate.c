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
    size_t n;
    ssize_t read;
    char *line = NULL;
    unsigned int num;

    fp = fopen(name, "r");
    if (fp == -1) {
        fprintf("Fail to open file %s\n");
        exit(1);
    }
    else {
        while((read = getline(&line, &n, fp)) != -1) {
            printf("%s ", line);
        }
        if (line)
            free(&line);
    }
    printf("\n");
}

int
main(int argc, char **argv)
{
    int fd = -1;
    unsigned int random, up_num;
    int n;
    char buf[32];

    if (argc < 2) {
        fprintf(stderr, "Please specified the up limit of the random number.\n");
        exit(1);
    }
    up_num = argv[1];

    fd = open("/dev/random", O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Open /dev/random fialed\n");
        exit(1);
    }
    else {
        n = read(fd, (char*)&random, sizeof(random));
        random = RANDOM_LOW + (random%(up_num-RANDOM_LOW+1));
        fd = open(RANDOM_STORE, O_RDWR|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
        if (fd == -1) {
            fprintf(stderr, "Fail to open file %s\n", RANDOM_STORE);
            exit(1);
        }
        else {
            sprintf(buf, "%d\n", random);
            n = sizeof(buf);
            write(fd, buf, n); 
        }
    }

    return 0;
}

