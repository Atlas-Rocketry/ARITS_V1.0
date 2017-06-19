#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R 6371 //radius of the Earth
#define TO_RAD (3.1415926536 / 180) //radians

void tab(double tabs){
	for(int i = 0; i < tabs; i++){
		printf("");
	}
}
double newtonSecondLaw (double force, double massGram){
	//F = (m1v1 - m0V0)/(t1-t0)
	double mass = massGram / 1000;
	double acceleration = force / mass;
	double totalTime = 5; //seconds
	double V1 = totalTime * acceleration;
	return V1;
}

double dist(double th1, double ph1, double th2, double ph2)
{
	double dx, dy, dz;
	ph1 -= ph2;
	ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;

	dz = sin(th1) - sin(th2);
	dx = cos(ph1) * cos(th1) - cos(th2);
	dy = sin(ph1) * cos(th1);
	return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}
float launchTH = 35.4897;
float launchPH = -85.9594;

float touchDownTH = 35.484;
float touchDownPH = -85.975;
int main()
{
	tab(1);
	double a = newtonSecondLaw(128, 453.592); //calculates acceleration based on force and mass
	printf("The rocket's max velocity will be %.3f V1 m/s\n", a);
	tab(1);
	double d = dist(launchTH, launchPH, touchDownTH, touchDownPH);
	/* Americans don't know kilometers */
	printf("dist: %.3f km (%.3f mi.) %.2f m %.2f ft\n", d, d / 1.609344, d*1000, d*1000*3.2808);
	return 0;
}
