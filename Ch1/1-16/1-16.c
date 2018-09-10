/**
 * 1-16: getLenOfLine function that prints longest line + line count
 */

#include <stdio.h>

#define MAXLINE 1000
#define ERROR -1
#define OK 0

int openFile(FILE **fp);
int getLenOfLine(FILE *fp, char line[], int maxline);
void copyLongest(char to[], char from[]);

int main() {
	int len, max;
	int fileError;
	char line[MAXLINE];
	char longest[MAXLINE];
	FILE *fp;
	len = max = 0;
	fileError = 0;
	for (int i = 0; i < MAXLINE; i++) {
		line[i] = 0;
		longest[i] = 0;
	}

	fileError = openFile(&fp);
	if (fileError == ERROR)
		return ERROR;
	while ((len = getLenOfLine(fp, line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copyLongest(longest, line);
		}
	if (max > 0)
		printf("max leng = %d: %s", max, longest); //max - 1 due to \n
	fclose(fp);
	return 0;
}

int openFile(FILE **fp) {
	*fp = fopen("T:\\Take\\CProgrammingLanguageRnK2ndEd\\Ch1\\1-16\\test.txt", "r");
	if (*fp == NULL) {
		perror("wow!");
		return ERROR;
	}
	return OK;
}

int getLenOfLine(FILE *fp, char s[], int lim) {
	int c, i;
	c = i = 0;

	for (i = 0; (i < lim - 1) && ((c = fgetc(fp)) != EOF) && (c != '\n'); ++i) {
		s[i] = c;
	}

	s[i] = '\0';
	return i;
}


void copyLongest(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
