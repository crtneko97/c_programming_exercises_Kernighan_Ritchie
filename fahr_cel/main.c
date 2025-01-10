#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);

int main(){


	for(int i = LOWER; i <= UPPER; i +=STEP)
	{
		float f = celsius_to_fahrenheit(i);
		printf("%d\t%6.1f\n", i, f );
	}

return 0;
}

float celsius_to_fahrenheit(float celsius)
{
	return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit)
{
	return (fahrenheit - 32 ) * 5.0 / 9.0;
}

