#include<stdio.h>

void two_pointer(int *mp)
{
	*mp = 30;
}

void two_pointer2(int **mmp)
{
	*mmp = (int*)0x100;
}
int main()
{
	int a = 10;
	printf("a = %d, &a = %p\n", a, &a);

	int* p = &a;
	*p = 20;
	printf("a = %d, p = %p\n", a, &p);

	two_pointer(p);
	printf("a = %d, p = %p\n", a, p);

	two_pointer2(&p);
	printf("p = %p\n", p);
	return 0;
}

