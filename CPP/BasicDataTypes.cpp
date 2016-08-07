//
//  BasicDataTypes.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/08/16.
//
//  https://www.hackerrank.com/challenges/c-tutorial-basic-data-types

#include <stdlib.h>
#include <stdio.h>

int main() {
    
    //Input given: int, long, long long, char, float, and double.
    int a;
    long b;
    long long c;
    char d;
    float e;
    double f;
    
    //Read parameters.
    scanf("%d %ld %lld %c %f %lf", &a, &b, &c, &d, &e, &f);
    
    //Output parameters.
    printf("%d\n", a);
    printf("%ld\n", b);
    printf("%lld\n", c);
    printf("%c\n", d);
    printf("%.3f\n", e);
    printf("%.9lf\n", f);
    
    return 0;
}
