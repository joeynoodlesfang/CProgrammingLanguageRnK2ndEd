/*
 * printing fahr celsius from 300 to 0 instead of 0 to 300
 */

#include <stdio.h>

main() {
	int fahr;
	for (fahr = 300; fahr >= 0; fahr -= 20)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
