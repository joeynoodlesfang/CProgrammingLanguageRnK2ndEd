/**
 * corresponding c->f conversion from 1-03
 * celsius = (5.0 / 9.0) * (fahr - 32.0);
 */

#include <stdio.h>


int main(){
	float celsius, fahr;
	int lower, upper, step;
	celsius = lower = 0;
	upper = 300;
	step = 20;
	printf("cel fahrenheit\n");
	printf("--------------\n");
	while(celsius <= upper){
		fahr = celsius * (9.0 / 5.0) + 32.0;
		printf("%3.0f %10.1f\n", celsius, fahr);

		celsius+=step;
	}
	return 0;
}
