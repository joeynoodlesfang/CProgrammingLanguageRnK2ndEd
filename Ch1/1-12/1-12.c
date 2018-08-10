#include <stdio.h>
#include <stdlib.h>
int main() {



	FILE *fp = fopen("T:\\take\\CProgrammingLanguageRnK2ndEd\\Ch1\\1-12\\text.txt", "r");
	if (fp == NULL) {
		perror("Error in opening file - taking keyboard inputs instead: ");
		int c = 0;
		while ((c = getchar()) != EOF) {
			printf("%c", c);
			if (c == '\t' || c == ' ') {
				printf("\n");
			}
			fflush(stdout);
		}
		printf("\n\nwe done!");
		getchar();
		return 0;
	}
	char buff[255];
	while (fscanf(fp, "%s", buff) != EOF) {
		printf("%s\n", buff);
	}
	printf("\n\nwe done!");
	fclose(fp);
	getchar();
	return 0;
}
