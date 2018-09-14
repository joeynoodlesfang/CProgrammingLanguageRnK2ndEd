/**
 * 1-20 write program detab that exchanges tabs for right amount of space
 * notables		getchar, fflush(stdout)
 * 				detab fxn is not used, instead it's just all in main
 */

#include <stdio.h>

int main (void) {
	int posCounter = 0;
	int c;
	while ((c=getchar()) != EOF) {
		if (c == '\t') {
			for (int i = 0; i < 8-posCounter%8;i++) {
				printf(" ");
			}
			posCounter += 8-posCounter%8;
		} else if (c == '\n') {
			posCounter = 0;
			printf("\n");
		} else {
			posCounter++;
			printf("%c", c);
		}
		fflush(stdout);
	}
	return 0;
}
