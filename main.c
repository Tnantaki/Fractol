#include <stdio.h>
#include <math.h>
int main(void)
{
	// int r = 10;
	// int tan;
	// int sin2;
	// int cos2;
	// int r2;
	// r2 = r * r;
	// for (int i = 0; i < r; i++)
	// {
	// 	for (int j = 0; j < r; j++)
	// 	{
	// 		cos2 = (j / r) * (j / r);
	// 		sin2 = (i / r) * (i / r);
	// 		if (sin2 + cos2 <= r2)
	// 			printf("*");
	// 		else
	// 			printf(" ");
	// 	}
	// 	printf("\n");
	// }
	// int r = 2;
	// for (int i = 0; i < 2 * r; i++)
	// {
	// 	for (int j = 0; j < 2 * r; j++)
	// 	{
	// 		if (i <= (int)sqrt(r*r - j*j))
	// 		{
	// 			printf("*");
	// 		}
	// 		else
	// 		{
	// 			printf(" ");
	// 		}
	// 	}
	// 	printf("\n");
	//}


	// int	r = 3;
	// int range = r + r - 1;
	// for (int i = 0 ; i < range ; i++)
	// {
	// 	for (int j = 0 ; j < range ; j++)
	// 	{
	// 		if (i - j < r)
	// 			printf("*");
	//  		else
	//  			printf(" ");
	// 	}
	// 	printf("\n");

	// }


	int r = 10;
	for (int y = r; y >= -r ; y--)
	{
		for (int x = -r; x <= r; x++)
		{
			if ((r * r) >= (y * y) + (x * x))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
