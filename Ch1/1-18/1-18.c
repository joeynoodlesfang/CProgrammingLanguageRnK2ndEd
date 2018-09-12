/**
 * 1-18: 	remove trailing blanks and tabs from each line, and delete entire blank lines.
 * 			Will also print output into new file instead of correcting original file.
 * 			(i know that does not need double pointer for things other than fopen, just testings)
 */

#include <stdio.h>

#define SUCCESS 0
#define ERROR 1

#define TRUE 1
#define FALSE -1

#define NOTEMPTY 0
#define EMPTY 1
#define ERROR_EDITLINE 2

#define NOT_ENDING_WITH_SPACE_OR_TAB 0

#define MAXLINE 1000
int openFile(FILE **fp, char fileName[], char* mode);
int readLine(FILE **fp, char currLine[]);
int editLine(char currLine[]);
void writeLine(FILE **fp, char currLine[], int flagFirstLine);
int main () {
	int len = 0;
	int fileError = 0;
	int lineStatus = 0;
	int writingFirstLine = TRUE;
	char currLine[MAXLINE] = {};
	char fileNameOriginal[MAXLINE] = "test.txt";
	char fileNameNew[MAXLINE] = "test2.txt";
	FILE *fp, *fp2;
	fp = fp2 = NULL;
	if ( (fileError = openFile(&fp, fileNameOriginal, "r")) == ERROR ){
		return ERROR;
	}
	if ( (fileError = openFile(&fp2, fileNameNew, "w")) == ERROR ) {
		return ERROR;
	}
	while ( (len = readLine(&fp, currLine)) > 0 ) {
		if ( (lineStatus = editLine(currLine)) == ERROR_EDITLINE ){
			return ERROR;
		} else if (lineStatus == NOTEMPTY) {
			writeLine(&fp2, currLine, writingFirstLine);
			if (writingFirstLine == TRUE) {
				writingFirstLine = FALSE;
			}
		}
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}

int openFile(FILE **fp, char fileName[], char* mode) {
	*fp = fopen(fileName, mode);
	if (*fp == NULL) {
		printf("cannot open file %s", fileName);
		return ERROR;
	} else {
		return SUCCESS;
	}
}

int readLine(FILE **fp, char currLine[]) {
	int i, c;
	i = c = 0;
	for ( i = 0; i < MAXLINE-1 && ((c = fgetc(*fp)) != '\n') && (c != EOF); i++ ) {
		currLine[i] = c;
	}
	currLine[i] = '\0';
	return i;
}

int editLine(char currLine[]) {
	int c = 0;
	int markerFirstTerminatingSpaceTab = NOT_ENDING_WITH_SPACE_OR_TAB;
	int flagEmptyLine = EMPTY;
	for (int i = 0; i < MAXLINE; i++) {
		c = currLine[i];
		if (c == '\0') {
			if (flagEmptyLine == EMPTY) {
				//empty line
				return EMPTY;
			} else if (markerFirstTerminatingSpaceTab == NOT_ENDING_WITH_SPACE_OR_TAB) {
				//no trailings
				return NOTEMPTY;
			} else {
				//some trailings
				currLine[markerFirstTerminatingSpaceTab] = '\0';
				for (int j = markerFirstTerminatingSpaceTab+1; j < MAXLINE; j++) {
					//emptyline
					currLine[j] = 0;
				}
				return NOTEMPTY;
			}
		} else if (c == ' ' || c == '\t') {
			if (markerFirstTerminatingSpaceTab == NOT_ENDING_WITH_SPACE_OR_TAB) {
				markerFirstTerminatingSpaceTab = i;
			}
		} else {
			if (flagEmptyLine == EMPTY) {
				flagEmptyLine = NOTEMPTY;
			}
			markerFirstTerminatingSpaceTab = NOT_ENDING_WITH_SPACE_OR_TAB;
		}
	}
	return ERROR_EDITLINE;
}

void writeLine(FILE **fp, char currLine[], int flagFirstLine) {
	if (flagFirstLine == TRUE) {
		fprintf(*fp, "%s", currLine);
	} else {
		fprintf(*fp, "\n%s", currLine);
	}
}
