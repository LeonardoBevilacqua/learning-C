#include <stdio.h>

int main()
{
	int num, resp, cont;
	for (cont = 1; cont <= 5; cont++)
	{
		scanf("%d", &num);
		resp = num * 3;
		printf("\n%d\n", resp);
	}
}