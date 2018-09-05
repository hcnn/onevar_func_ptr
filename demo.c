#include <stdio.h>  //printf
#include <math.h> //exp
#include "onevar_func_ptr.h"

// use continous returns model
double irr_func(double x, const double* time, const double* amount, size_t n){
    double minusx = -x;
    double f = 0.0;
    size_t i;
    for(i=0; i<n; i++){
        f += amount[i] * exp(minusx * time[i]);
    }
    return f;
}

double functest0(double x, const double* param){
    //unpack param, 2 arrays expected
    // 1st element is "n"
    // 1 to n: time durations
    // n+1 to 2*n: amounts
    size_t n = (size_t)param[0];
    return irr_func(x, &param[1], &param[n+1], n);
}

int main(){
    ONEVAR_FUNC_PTR fun0 = &functest0;

    double x = 0.045;

    // 1st element is "n"
    // 1 to n: time durations
    // n+1 to 2*n: amounts
    double param[] = {
        5, 
        .0, .5, 1.25, 1.7, 2.5,
        -1000, 20, 55, 15, 988+33
    };
    
    double f = fun0(x, param);
    printf("%.2f\n", f);
    
}
