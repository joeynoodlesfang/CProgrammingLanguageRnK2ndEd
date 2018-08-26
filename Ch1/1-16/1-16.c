/**
 * 1-16: getLineWithLength function that prints longest line + line count
 */

#include <stdio.h>
#define MAXLINE 1000

int getLineWithLength(FILE *fp, char line[], int maxline);
void copyLongest(char to[], char from[]);

int main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	max = 0;
	FILE *fp = fopen("T:\\Take\\CProgrammingLanguageRnK2ndEd\\Ch1\\1-16\\test.txt", "r");
	if (fp == NULL) {
		perror("wow!");
		return -1;
	}
	while ((len = getLineWithLength(fp, line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copyLongest(longest, line);
		}
	if (max > 0) /* there was a line */
		printf("max leng = %d: %s", max, longest);
	fclose(fp);
	return 0;
}


int getLineWithLength(FILE* fp, char s[], int lim) {
	int c, i;
	c = i = 0;

	for (i = 0; (i < lim - 1) && ((c = fgetc(fp)) != EOF) && (c != '\n'); ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
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
