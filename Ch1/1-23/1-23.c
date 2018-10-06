/**
 * 1-23	Delete all comments from a c program (note, c programs have no nesting comments).
 * Note: skipping situations of backslash splitting quote across multiple program lines.
 */

#include <stdio.h>
#define FALSE 	-1
#define TRUE 	0

int flag_inSingleQuote = FALSE;
int flag_inDoubleQuote = FALSE;
int main () {
	int c = 0;
	//open c program
	FILE *fp = fopen("test.c", "r+");
	if (fp == NULL) {
		perror("ok well");
		return 1;
	}
	//use fseek
	//look for slash.
	while(1) {
		c = fgetc(fp);
		if ( feof(fp) ) {
			break;
		}
		//situations of comments, note that quotes can be a situation too """

		if (c=="/")
		printf("%c",c);
	}
	return 0;
}
