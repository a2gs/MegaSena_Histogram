/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	FILE *f = NULL;
	char buff[100] = {0};
	unsigned int num[61] = {0}, i = 0;
	unsigned int x1, x2, x3, x4, x5, x6;

	f = fopen(argv[1], "r");
	if(f == NULL)
		return(-1);

	memset(num, 0, sizeof(int) * 60);

	for(; fgets(buff, 100, f) != NULL; ){
		x1 = x2 = x3 = x4 = x5 = x6 = 0;

		sscanf(buff, "%u\t%u\t%u\t%u\t%u\t%u", &x1, &x2, &x3, &x4, &x5, &x6);

		num[x1]++; num[x2]++; num[x3]++;
		num[x4]++; num[x5]++; num[x6]++;
	}

	fclose(f);

	for(i = 1; i <= 60; i++){
		printf("%u\t%u\n", i, num[i]);
	}

	return(0);
}
