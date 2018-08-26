/*
 * 1-14.c histogram of frequency of input characters (A-Z, a-z)
 *
 *  Created on: Aug 12, 2018
 *      Author: JoeyNoodles
 */

#include <stdio.h>

int main () {
	int c;
	int totalCharacters = 52;
	int characterList[totalCharacters];

	for (int i = 0; i < totalCharacters; i++) {
		characterList[i] = 0;
	}

	FILE *fp = fopen("T:\\Take\\CProgrammingLanguageRnK2ndEd\\Ch1\\1-14\\test.txt", "r");
	if (fp == NULL) {
		perror("File open error test.txt");
		return -1;
	}
	while ((c=fgetc(fp)) != EOF) {
		if (((c-'A') >= 0) && ((c-'Z') <= 0)) {
			c = c - 'A';
			characterList[c]++;
		}
		else if (((c-'a') >= 0) && ((c-'z') <= 0)) {
			c = c - 'a';
			characterList[c+26]++;
		}
	}

	int maxValCharacterList = 0;
	for (int i = 0; i < totalCharacters; i++) {
		if (maxValCharacterList < characterList[i]) {
			maxValCharacterList = characterList[i];
		}
	}
	int currValCharacterList = maxValCharacterList;

	printf("\nHISTOGRAM OF CHARACTERS IN test.txt\n\n");
	for (int row = 0; row < maxValCharacterList; row++) {
		printf("\n");
		currValCharacterList--;
		for (int col = 0; col < totalCharacters; col++) {
			if (characterList[col] <= currValCharacterList)
				printf("   ");
			else
				printf(" | ");
		}
	}
	printf("\n");
	for (int col = 0; col < totalCharacters; col++) {
		printf("---");
	}
	printf("\n");
	unsigned char charList[totalCharacters];
	for (int i = 0; i < 26; i++) {
		charList[i] = 'A' + i;
	}
	for (int i = 0; i < 26; i++) {
		charList[i+26] = 'a' + i;
	}
	for (int col = 0; col < totalCharacters; col++) {
		printf("%2c ", charList[col]);
	}

	return 0;

}
