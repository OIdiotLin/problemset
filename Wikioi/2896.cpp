#include <stdio.h>
int main()
{
	double input, result;
	int number;
		scanf("%lf", &input);
		number = (int)input;
		result = input - (double)number;
		if(!result)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	return 0;
}
