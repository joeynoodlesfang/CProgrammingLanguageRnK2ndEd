/**
 * horizontal histogram of length of words
 */

#include <stdio.h>
#define FALSE 0
#define TRUE 1

int main() {
	int arrSizeWordLengths = 10;
	int wordLengths[arrSizeWordLengths];
	for (int i = 0; i < arrSizeWordLengths; i++) {
		wordLengths[i] = 0;
	}
	int c = 0;
	int length = 0;
	int inAWord = FALSE;
	FILE *fp = fopen("test.txt", "r");
	if (fp == NULL) {
		perror("cannot open file");
		getchar();
		return -1;
	}

	while ( (c=fgetc(fp)) != EOF) {
		if ( (((c-'A') >= 0) && ((c-'Z') <= 0)) ||
			 (((c-'a') >= 0) && ((c-'z') <= 0)) ||
			 (((c-'0') >= 0) && ((c-'9') <= 0)) ) {
			length++;
			if (inAWord == FALSE) {
				inAWord = TRUE;
			}
		}
		else {
			if (inAWord == TRUE) {
				if (length > arrSizeWordLengths) {
					length = arrSizeWordLengths;
				}
				inAWord = FALSE;
				wordLengths[length-1]++;
				length = 0;
			}
		}
	}

	printf("\nhistogram of word lengths in test.txt\n\n");
	for (int i = 0; i < arrSizeWordLengths; i++) {
		if (i == arrSizeWordLengths - 1)
			printf("\n%2d+:", i + 1);
		else
			printf("\n %2d:", i + 1);
		for (int j = 0; j < wordLengths[i]; j++) {
			printf("-");
		}
		printf(" (%d)", wordLengths[i]);
	}

	return 0;
}
