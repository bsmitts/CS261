/* CS261- Assignment 1 - Q.3*/
/* Name:  Brian Smith
 * Date:  04/09/15
 * Solution description:  An integer n is declared and assigned a value of 20.  Memory is then allocated for an array for n integers
 * using malloc.  The array is then filled with random numbers using rand().  The contents of the array are printed, sort is called,
 * and the contents of the array are pronted again.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n)
{
    /*Sort the given array number , of length n*/
    int index;
    for (int i = 0; i < n; i++)
    {
        index = *(number + i);

        for (int j = (i + 1); j < n; j++)
        {
            if (*(number + j) < index)
            {
                *(number + i) = *(number + j);
                *(number + j) = index;
                index = *(number + i);
            }
        }
    }
}

int main()
{
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = (int*)malloc(sizeof(int) * n);
    /*Fill this array with random numbers, using rand().*/
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        *(array + i) = rand() % 21;
    }
    /*Print the contents of the array.*/
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *(array + i));
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    /*Print the contents of the array.*/
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *(array + i));
    }

    return 0;
}
