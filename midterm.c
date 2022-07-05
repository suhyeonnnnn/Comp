/* 
Question No. 1
Write a C program that reads a 5 x 5 array of integers and then prints the row sums and the coloumn
sums:
*/


#include<stdio.h>
int main(void){
    int a[5][5], row_sum[5], col_sum[5], sum, i, j;

    for (i=0; i<5; i++){
        printf("Enter row %d: ", i+1);
        for (j=0; j<5; j++){
            scanf("%d", &a[i][j]);
        }
    }

    //  row total
    for (i=0; i<5; i++){
        sum = 0;
        for (j=0; j<5; j++){
            sum += a[i][j];
        }
        row_sum[i] = sum;
    }

    // col total
    for (i=0; i<5; i++){
        sum = 0;
        for (j=0; j<5; j++){
            sum += a[j][i];
        }
        col_sum[i] = sum;
    }


    printf("Row totals: ");
    for (i=0; i<5; i++){
        printf("%d ", row_sum[i]);
    }

    printf("\nColumn totals: ");
    for (i=0; i<5; i++){
        printf("%d ", col_sum[i]);
    }

    return 0;
}
