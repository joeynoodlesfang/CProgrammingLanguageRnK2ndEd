/**
 * 1-19 write fxn reverse(s) that reverses the character string s, and write program
 * that reverses input (I will use text doc and print out on another doc, for practicing fprintf)
 */

#include <stdio.h>

#define SUCCESS 0
#define ERROR 1

#define MAXLINE 1000

int openFile(FILE** fp, char* fileName, char* mode);
int getLine(FILE* fp, char currLine[]);
void reverse(char currLine[], int locTermNull);
int writeLine(FILE* fp, char currLine[], int firstLine);

int main () {
	int len = 0;
	int errorOpenFile;
	int firstLine = 1;
	char s[MAXLINE] = {};
	char fileNameOriginal[MAXLINE] = "test.txt";
	char fileNameNew[MAXLINE] = "test2.txt";
	FILE *fp, *fp2;
	fp = fp2 = NULL;

	errorOpenFile = openFile(&fp, fileNameOriginal, "r");
	if (errorOpenFile == ERROR) {
		return ERROR;
	}

	errorOpenFile = openFile(&fp2, fileNameNew, "w");
	if (errorOpenFile == ERROR) {
		return ERROR;
	}

	while ((len = getLine(fp, s)) > 0) {
		reverse(s, len);
		writeLine(fp2, s, firstLine);
		if (firstLine) {
			firstLine = 0;
		}
	}
	return 0;
}

int openFile(FILE** fp, char* fileName, char* mode) {
	*fp = fopen(fileName, mode);
	if (*fp == NULL) {
		printf("welp on %s", fileName);
		return ERROR;
	} else {
		return SUCCESS;
	}
}

int getLine(FILE* fp, char currLine[]) {
	int i, c;
	i = c = 0;
	for (i = 0; i < MAXLINE && (c = fgetc(fp)) != EOF && c != '\n'; i++) {
		currLine[i] = c;
	}
	currLine[i] = '\0';
	return i;
}

void reverse(char currLine[], int locTermNull) {
	char tempCharArray[MAXLINE] = {};
	for (int i = 0; i < locTermNull; i++) {
		tempCharArray[i] = currLine[i];
	}
	for (int i = 0; i < locTermNull; i++) {
		currLine[i] = tempCharArray[(locTermNull-i)-1];
	}
	currLine[locTermNull] = '\0';
}

int writeLine(FILE* fp, char currLine[], int firstLine) {
	int c = 0;
	if (firstLine) {
		c = fprintf(fp, "%s", currLine);
	} else {
		c = fprintf(fp, "\n%s", currLine);
	}
	if (c < 0) {
		return ERROR;
	} else {
		return SUCCESS;
	}
}
