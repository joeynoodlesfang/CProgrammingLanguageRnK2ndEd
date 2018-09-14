/**
 * 1-21:	use program entab to replace a large chunk of spaces by the min num tabs and spaces to achieve same spacing.
 * 			tab spacing used is 8 here.
 *
 * 			"When either a tab or a single blank would suffice to reach a tab stop, which should be given
 *			preference?" I'm guessing space because (hopefully I'll code it this way), anything less than 8 will not
 *			trigger a tab replacement (ie slightly less of the code to go through)
 *
 * notables			getchar, structs,
 * modifications	will not write entab, since short single-purpose code can be used
 * 					not accounting for a trillion spaces
 */

#include <stdio.h>

struct spaceTabs {
	int spaces, tabs;
};

struct spaceTabs calcNumSpacesAndTabs (int currPos, int spaceCounter);

int main(void) {
	int posCounter = 0;
	int spaceCounter = 0;
	struct spaceTabs spaceTab = {0};
	int c = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == EOF) {
			printf("%c", c);
			posCounter = 0;
			spaceCounter = 0;
		} else if (c == ' ') {
			spaceCounter++;
		} else {
			if (spaceCounter != 0) {
				spaceTab = calcNumSpacesAndTabs(posCounter, spaceCounter);
				posCounter+=spaceCounter;
				for (int i = 0; i < spaceTab.tabs; i++) {
					printf("\t");
				}
				for (int i = 0; i < spaceTab.spaces; i++) {
					printf(" ");
				}
			}
			printf("%c", c);
			posCounter++;
			spaceCounter = 0;
		}
		fflush(stdout);
	}
	return 0;
}

struct spaceTabs calcNumSpacesAndTabs (int currPos, int _spaceCounter) {
	struct spaceTabs _spaceTab = {0};
	int numSpacesIfTab = 8-currPos%8;
	if (_spaceCounter < numSpacesIfTab) {
		_spaceTab.spaces = _spaceCounter;
	} else if (_spaceCounter == numSpacesIfTab) {
		_spaceTab.tabs = 1;
	} else {
		_spaceCounter = _spaceCounter - numSpacesIfTab;
		_spaceTab.tabs = 1;
		_spaceTab.tabs += _spaceCounter/8;
		_spaceTab.spaces = _spaceCounter%8;
	}
	return _spaceTab;
}
