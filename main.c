#include<stdlib.h>
#include<omp.h>
#include<string.h>


#include<stdio.h>

float area(void) {
    float y = 0, steps = 500, area = 0, x2 = 0;
#pragma omp parallel
    {    int i;
        double localarea = 0;
        int tnum = omp_get_thread_num();
        int numt = omp_get_num_threads();
        for (i = tnum; i < 500; i+= numt) {
            x2 = i / (steps);
            /* printf("%f  %f\n", x2, i/(steps));*/
            y = 4.0 / (1 + (x2 * x2));
            localarea += (y * (0.002));

        }
#pragma omp critical
        {
            area += localarea;
        }
    }
    return area;
}

int main(void) {
    printf("%f", area());
    return 0;
}
