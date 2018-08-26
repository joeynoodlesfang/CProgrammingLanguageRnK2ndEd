/**
 * 1-16: getLine function that prints longest line + line count
 */

#include <stdio.h>
#define MAXLINE 1000

int getLine(FILE *fp, char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */
int main() {
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;
	FILE *fp = fopen("T:\\Take\\CProgrammingLanguageRnK2ndEd\\Ch1\\1-16\\test.txt", "r");
	if (fp == NULL) {
		perror("wow!");
		return -1;
	}
	while ((len = getLine(fp, line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0) /* there was a line */
		printf("max leng = %d: %s", max, longest);
	fclose(fp);
	return 0;
}

/* getLine: read a line into s, return length */
int getLine(FILE* fp, char s[], int lim) {
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
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}