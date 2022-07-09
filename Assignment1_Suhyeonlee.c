/* 
Assignment 1 
201902592 Suhyeon Lee
*/

#include<stdio.h>
#include<stdbool.h>
#define N 100

int main(void){
    int opt, a[N], i, n, value, pos, flag;
    int count = 0; 
    bool found = false;

    do {
        /* Menu Selection */
        printf("\nSelct Menu: \n");
        printf("1) Add a Student ID \n");
        printf("2) Delete Student ID \n");
        printf("3) Insert Student ID at a given position or index \n");
        printf("4) Search Student ID \n");
        printf("5) Update Student ID \n");
        printf("6) Display Student IDs \n");
        printf("7) Exit\n\n");
        scanf("%d", &opt);

        switch (opt) {
        /* Add Student ID */
        case 1: printf("Enter Student ID: ");
                scanf("%d", &value);

                /* if ID already exists prgram dosen't work */    
                flag = 0;
                for (i=0; i < count; i++)
                    if (value == a[i]) {
                        flag = 1;
                        break;}    
                    
                if (flag == 1) printf("Already exists.\n");
                
                else
                {
                    a[count] = value;  // add value at last array  
                    count++;
                }

                break;

        /* Delete Student ID */         
        case 2: printf("Enter a given position or index: ");
                scanf("%d", &pos);
                if (pos<0 || pos>count-1)
                    printf("Invalid position");
                else {
                    for (i = pos; i < count - 1; i++)
                    a[i] = a[i + 1];
                    count--; 
                }
                break;

        /* Insert Student ID at a given position or index */
        case 3: printf("Enter the position: ");
                scanf("%d", &pos);

                if (pos < 0)
                    printf("Invalid position");

                else if (pos >= count) // if postion is last array
                {
                    printf("Enter the new element: ");
                    scanf("%d", &value);
                    
                    flag = 0;
                    for (i=0; i < count; i++)
                        if (value == a[i]) {
                            flag = 1;
                            break;}    
                    
                    if (flag == 1) printf("Already exists.\n");
                    else
                    {
                        a[count] = value; // add value like program 1
                        count++;
                    }
                }    

                else // if pos is in middle of array
                { 
                    for (i = count-1; i >= pos; i--)
                        a[i+1] = a[i]; // move back to make space
                    printf("Enter the new element: ");
                    scanf("%d", &value);

                    flag = 0;
                    for (i=0; i < count; i++)
                        if (value == a[i]) {
                            flag = 1;
                            break;}    
                    
                    if (flag == 1) printf("Already exists.\n");
                    else
                    {
                        a[pos] = value; // add value at certain position
                        count++;  
                    }             
                }
                break;

        /* Search Student ID */
        case 4: printf("Enter value to search: ");
                scanf("%d", &value);

                for (i = 0; i < count; i++)
                    if (a[i] == value) found = true;
                if (found == true)
                    printf("\n%d is student ID.\n", value);
                else
                    printf("\n%d is not stduent ID.\n", value);

                break;

        /* Update Student ID */           
        case 5: printf("Enter the position: ");
                scanf("%d", &pos);
                if (pos<0 || pos>count-1)
                    printf("Invalid position");
                else
                {
                    printf("Enter the new element: ");
                    scanf("%d", &value);
                    flag = 0;
                    for (i=0; i < count; i++)
                        if (value == a[i]) {
                            flag = 1;
                            break;}    
                    
                    if (flag == 1) printf("Already exists.\n");
                    else
                    {
                        a[pos] = value; // just replace
                    }    
                }

                break;
        
        /* Display Student IDs */
        case 6: for (i=0; i<count; i++)
                    printf("%d\n", a[i]);
                break;

        case 7: return 0;

        default: printf("Invalid Option\n");
                break;
        }
   
    } while (opt != 7);
}

