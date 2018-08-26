/**
 * vertical histogram of word lengths
 */

#include <stdio.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

int main() {
	int numEleWordLen = 10;
	int wordLen[numEleWordLen];
	for (int i = 0; i < numEleWordLen; i++) {
		wordLen[i] = 0;
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
				if (length > numEleWordLen) {
					length = numEleWordLen;
				}
				inAWord = FALSE;
				wordLen[length-1]++;
				length = 0;
			}
		}
	}

	int largestValWordLen = 0;
	for (int i = 0; i < numEleWordLen; i++) {
		if (largestValWordLen < wordLen[i])
			largestValWordLen = wordLen[i];
	}

	printf("%d", largestValWordLen);
	//2. +1 to longest
	int lineCount, totalRowsWordLen;
	lineCount = totalRowsWordLen = largestValWordLen + 1;
	//3. for int i < longest+1:
	printf("\nHISTOGRAM OF WORD LENGTHS IN test.txt\n\n");
	for (int row = 0; row < totalRowsWordLen; row++) {
		printf("\n");
		lineCount--;
		for (int col = 0; col < numEleWordLen; col++) {
			if (lineCount > wordLen[col])
				printf("     ");
			else if (lineCount == wordLen[col])
				printf("%5d", wordLen[col]);
			else
				printf("    |");
		}

	}
	printf("\n");
	for (int col = 0; col < numEleWordLen; col++) {
		printf("-----");
	}
	printf("\n");
	for (int col = 0; col < numEleWordLen; col++) {
		printf("%5d", col+1);
	}
	printf("\n");
	for (int i=0 ; i < ((numEleWordLen*5/2)-(12 / 2)); i++)
		printf(" ");
	printf("word lengths");
	return 0;
}
