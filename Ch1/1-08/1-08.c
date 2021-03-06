/**
 * count blanks, tabs, nl.
 */

#include <stdio.h>

int main () {
	int c = 0;
	int nb, nt, nl;
	nb = nt = nl = 0;
	FILE *fp = fopen("T:\\take\\CProgrammingLanguageRnK2ndEd\\Ch1\\1-08\\test.txt", "r");
	if(fp == NULL) {
		perror("Error in opening file");
		getchar();
		return(-1);
	}
	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
		if (c == ' ')
			++nb;
		else if (c == '\t')
			++nt;
		else if (c == '\n')
			++nl;
	}
	printf("blanks: %d\ntabs: %d\nnewlines: %d", nb, nt, nl);
	getchar();
	fclose(fp);
	return 0;
}
