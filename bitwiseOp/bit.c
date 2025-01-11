#include <stdio.h>



int main()

{
	char x = 1, y = 2;
	if(x&y)
		printf("result of x&y is 1");
	if(x&&y)
		printf("result of x&&y is 1");


	char var = 3;
	printf("\n%d", var<<3);

	char var2 = 32;
	printf("\n%d", var2>>4);


	int a = 4, b = 3;
	a = a ^ b;
	printf("\nA after first xor= %d",a);
	b = a ^ b;
	printf("\nB after first xor= %d",b);
	a = a ^ b;

	printf("\n then setting a = a ^ b again  XOR, a = %d and b = %d", a, b);







	return 0;
}
