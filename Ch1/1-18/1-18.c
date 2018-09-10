/**
 * 1-18: 	remove trailing blanks and tabs from each line, and delete entire blank lines.
 * 			Will also print output into new file instead of correcting original file.
 */

#include <stdio.h>

#define ERROR 1
#define SUCCESS 0
#define MAXLINE 1000
int openFile(FILE **fp, char fileName[], char* format);
void readLine(FILE **fp, char currLine[]);
void editLine(char currLine[]);
void writeLine(FILE **fp, char currLine[]);
int main () {
	int fileError = 0;
	char currLine[MAXLINE];
	char fileNameOriginal = "test.txt";
	char fileNameNew = "test2.txt";
	FILE *fp = NULL;
	if ((fileError = openFile(&fp, fileNameOriginal, 'r'))==ERROR){
		return ERROR;
	}
	return 0;
}

int openFile(FILE **fp, char fileName[], char* format) {
	*fp = fopen(fileName, format);
	if (*fp == NULL) {
		perror('cannot open file %s', fileName);
		return ERROR;
	} else {
		return SUCCESS;
	}
}

void readLine(FILE **fp, char currLine[]) {
	int c = 0;
	for ( int i = 0; i < MAXLINE-1 && ((c = fgetc(*fp)) != '\n') && (c != EOF); i++ ) {
		currLine[i] = c;
	}
	currLine[i+1] =
}
