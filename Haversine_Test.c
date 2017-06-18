#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R 6371 //radius of the Earth
#define TO_RAD (3.1415926536 / 180) //radians

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

int main()
{
    for (int i=0; i++; i< 10){
        double val1 = random_number(0,180);
        double val2 = random_number(0,180);
        double val3 = random_number(0,180);
        double val4 = random_number(0,180);
	    double d = dist(val1,val2,val3,val4);
	    /* Americans don't know kilometers */
        printf("val1: %lf, val2: %lf, val3: %lf, val4: %lf", val1, val2, val3, val4);
	    printf("dist: %.1f km (%.1f mi.)\n", d, d / 1.609344);
    }
	return 0;
    }
}

double random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (double)(rand() % (hi_num - low_num)) + low_num;
    return result;
}
