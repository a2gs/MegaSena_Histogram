/* Andre Augusto Giannotti Scota (https://sites.google.com/view/a2gs/) */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

unsigned int scanline(unsigned int line[], unsigned int range[], unsigned int rangeTot)
{
	unsigned int i = 0, tot = 0;

	for(i = 0, tot = 0; i < rangeTot; i++)
		if(line[0] == range[i] || line[1] == range[i] || line[2] == range[i] || line[3] == range[i] || line[4] == range[i] || line[5] == range[i]) tot++;

	return(tot);
}

int main(int argc, char *argv[])
{
	FILE *f = NULL;
	char buff[100] = {0};
	unsigned int i = 0, rangeTot = 0, range[60] = {0}, line[6] = {0};

	rangeTot = atoi(argv[2]);

	f = fopen(argv[1], "r");
	if(f == NULL)
		return(-1);

	for(i = 0; fgets(buff, 100, stdin) != NULL && i < rangeTot; i++){
		sscanf(buff, "%u", &range[i]);
		printf("Topper %u/%u: [%u]\n", i+1, rangeTot, range[i]);
	}

	for(i = 0; fgets(buff, 100, f) != NULL; i++){
		memset(line, 0, sizeof(unsigned int)*6);
		sscanf(buff, "%u\t%u\t%u\t%u\t%u\t%u", &line[0], &line[1], &line[2], &line[3], &line[4], &line[5]);
		printf("%02u %02u %02u %02u %02u %02u\t\t[%02u]\n", line[0], line[1], line[2], line[3], line[4], line[5], scanline(line, range, rangeTot));
	}

	fclose(f);

	return(0);
}
