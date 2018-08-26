/**
 * 1-15: test out creating a function
 */
#include <stdio.h>

void printRangeFahrAndCelsius(int lower, int upper, int step);

int main() {
	int lower, upper, step;
	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	printRangeFahrAndCelsius(lower, upper, step);
	return 0;
}

void printRangeFahrAndCelsius(int lower, int upper, int step) {
	int fahr, celsius;
	fahr = lower;
	celsius = 0;
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
