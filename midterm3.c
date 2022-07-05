/*
Question No. 3
Write a C program to solve Quadratic equation.
*/

#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c, rool1, rool2;
    
    printf("Enter value: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    if (a==0 && b == 0) printf("Not a valid equation. \n");

    else {
        if ((b*b - 4*a*c) < 0) printf("Not a Real Solution. \n");
        else if ((b*b - 4*a*c) >= 0) { // in question, b² -4ac > 0 but i think it should be b² -4ac >= 0 
            rool1 = (-b+sqrt(b*b-4*a*c)) / 2*a ;
            rool2 = (-b-sqrt(b*b-4*a*c)) / 2*a ;
        }
    }

    printf("The answer is : %0.1f and %0.1f", rool1, rool2);

}