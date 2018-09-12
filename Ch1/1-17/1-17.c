/**
 * prints all input line (from file) that are longer than 80 characters.
 */

#include <stdio.h>

#define MAXLINE 1000
#define ERROR -1
#define OK 0

int openFile(FILE **fp);
int determineLineLen(FILE **fp, char currLine[]);
void printLineLen(int len, char currLine[]);

int main() {
	int len = 0;
	int fileError = 0;
	FILE *fp = NULL;
	char currLine[MAXLINE];
	for (int i = 0; i < MAXLINE; i++)
		currLine[i] = 0;

	fileError = openFile(&fp);
	if (fileError == ERROR) {
		return ERROR;
	}
	while ((len = determineLineLen(&fp, currLine)) > 0) {
		if (len > 80) {
			printLineLen(len, currLine);
		}
	}
	fclose(fp);
	return OK;
}

int openFile(FILE **fp) {
	*fp = fopen("T:\\Take\\CProgrammingLanguageRnK2ndEd\\Ch1\\1-17\\test.txt", "r");
	if (*fp == NULL) {
		perror("ROLO");
		getchar();
		return ERROR;
	}
	return OK;
}

int determineLineLen(FILE **fp, char currLine[]) {
	int len, c;
	len = c = 0;
	for (len = 0; ((c = fgetc(*fp)) != EOF) && (c != '\n') && (len < MAXLINE-1); len++) {
		currLine[len] = (char)c;
	}
	currLine[len] = '\0';
	return len;
}

void printLineLen(int len, char currLine[]) {
	fflush(stdout);
	printf("\nlen=%d: %s", len, currLine);
	return;
}
