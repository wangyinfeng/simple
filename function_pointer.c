#include <stdio.h>
typedef int (*pf)(int n);

int addone(int n)
{
	return n+1;
}
int subone(int n)
{
	return n-1;
}

int compute(pf oper, int n)
{
	return oper(n);
}

int main(void) {
	// your code goes here
	printf("%d\n", compute(addone, 50));
	printf("%d\n", compute(subone, 50));
	return 0;
}
