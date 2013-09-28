/* The Effective programming said most programmer 
 * cannot write the simplest code, and give the
 * example of FizzBuzz... then I have a try,
 * unfortunely, the first submit lose a ';',
 * and the second submit get incorrect result,
 * this is the 3rd submit, 7 minutes has passed.
 */
int
main(void)
{
    int i;
    for (i=1; i<=100; i++){
        if (!(i%3) && !(i%5))
            printf("%s\n", "FizzBuzz");
        else if (!(i%3))
            printf("%s\n", "Fizz");
        else if (!(i%5))
            printf("%s\n", "Buzz");
        else
            printf("%d\n", i);

    }
    return 0;
}
