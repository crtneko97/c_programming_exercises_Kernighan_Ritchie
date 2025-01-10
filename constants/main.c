#include <stdio.h>




int str_len(char s[]);

int main()
{

	char name[] = "Simon";
	char str[] = "hello\0world";

	printf("\n%d",str_len(name));
	
	printf("\n%s", str);



	return 0;
}


int str_len(char s[])
{
	int i;

	while(s[i] != '\0')
	{
		++i;
	}
	return i;


}
