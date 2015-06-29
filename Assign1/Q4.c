/* CS261- Assignment 1 - Q.4*/
/* Name:  Brian Smith
 * Date:  04/09/15
 * Solution description:  An integer n is declared in main with a value of 5.  Memory is allocated for n students using malloc.
 * Random IDs and scores are then generated using rand().  The contents of the array are printed, sort is called, and the
 * contents of the array are printed again.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student
{
	int id;
	int score;
};

void sort(struct student* students, int n)
{
    /*Sort the n students based on their score*/
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n- i; j++)
        {
            if(students[j].score > students[j + 1].score)
            {
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main()
{
    /*Declare an integer n and assign it a value.*/
    int n = 5;
    /*Allocate memory for n students using malloc.*/
    struct student *array = (struct student*)malloc(sizeof(struct student) * n);
    /*Generate random IDs and scores for the n students, using rand().*/
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        (array + i) -> id = rand() % 20 + 1;
        (array + i) -> score = rand() % 101;
    }
    /*Print the contents of the array of n students.*/
    for (int i = 0; i < n; i++)
    {
        printf("%d  %d\n", (array + i) -> id, (array + i) -> score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(array, n);
    /*Print the contents of the array of n students.*/
    for (int i = 0; i < n; i++)
    {
        printf("%d  %d\n", (array + i) -> id, (array + i) -> score);
    }

    return 0;
}
