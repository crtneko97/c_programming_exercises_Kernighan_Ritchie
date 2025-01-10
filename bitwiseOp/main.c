#include <stdio.h>




/* getbits: get n bits from position p*/

unsigned getbits(unsigned x, int p, int n);

int main()
{

	unsigned int u;
	int i, j;

	for(u = 0; u <= 10; ++u)
		for(i = 0; i <= 4; ++i)
			for(j = 1; j <= 4; ++j)
				printf("\nInput: u = %d, p = %d, n = %d, result = %d",u, i, j, getbits(u, i, j));

	return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
return (x >> (p + 1 - n)) & ~(~0 << n);
}
