/**
 * 1-21:	use program entab to replace a large chunk of spaces by the min num tabs and spaces to achieve same spacing.
 * 			tab spacing used is 8 here.
 *
 * 			"When either a tab or a single blank would suffice to reach a tab stop, which should be given
 *			preference?" I'm guessing space because (hopefully I'll code it this way), anything less than 8 will not
 *			trigger a tab replacement (ie slightly less of the code to go through)
 *
 * notables			getchar
 * modifications	will not write entab, since short single-purpose code can be used
 */

#include <stdio.h>

int spaces = 0;
int tabs = 0;

int calcNumSpacesAndTabs (int currPos, int spaceCounter);

int main(void) {
	int posCounter = 0;
	int spaceCounter = 0;
	int c = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			spaceCounter++;
		} else {
			if (spaceCounter != 0) {
				calcNumSpacesAndTabs();

			}
		}
	}
	return 0;
}

void calcNumSpacesAndTabs (int currPos, int spaceCounter) {
	int numSpaces = 8-currPos%8;

}
