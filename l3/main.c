#include <stdio.h>

int f(int x, int y, int z);

int main(int argc, char** argv)
{
	int x, y, z, rez;
	printf("\nInput X, Y, Z (X Y Z): ");
	scanf("%d %d %d", &x, &y, &z); 

	printf("Result in C: %d\n", ((x<<2)+(y>>2)+(z%3))); /* Предположим именно такой порядок операций 
	(в C приоритет сложения выше приоритета побитового сдвига) */
	rez = f(x, y, z);
	printf("Result in Asm: %d\n", rez);
	return 0;
}



