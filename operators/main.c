#include <stdio.h>



int main()
{

	int lim = 100;
	char s[lim];
	int i, c;


	for(i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
	{
		s[i] = c;
	}
	s[i] = '\0';

	printf("input: %s\n", s);




return 0;
}


