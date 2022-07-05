/* Question No. 2
Write a C program that finds the intersection of two sets and also displays a list of perfect numbers in the
intersection set */

#include<stdio.h>
#define N 5

int main(){
    int a[N], b[N], c[N], i, j;

    // make set 1
    printf("first set: ");
    for (i=0; i<N; i++){
        scanf("%d", &a[i]);
    }

    // make set 2
    printf("second set: ");
    for (i=0; i<N; i++){
        scanf("%d", &b[i]);
    }

    // intersection
    int idx = 0;


    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            if (a[i] == b[j]){ 
                c[idx] = a[i]; 
                idx++; 
            }
        }
    }

    // c result
    printf("\nthe c : \n");
    for (i=0; i<idx; i++){
        printf("%d\n", c[i]);
    }


    // perfect number
    printf("\nthe perfect number : \n");
    for (i=0; i<=idx; i++){ // set c loop
        int sum = 0;
        for (j=1; j<c[i]; j++){
            if (c[i]%j==0) sum += j;
        }
        if (sum == c[i]) printf("%d ", c[i]);
    }

    return 0;

}