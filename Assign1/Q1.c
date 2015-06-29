/* CS261- Assignment 1 - Q.1*/
/* Name:  Brian Smith
 * Date:  04/08/15
 * Solution description:  A pointer to a student type is declared null in main.  Memory is then allocated for ten students.
 * The array is then filled with 10 student types with random id's between 1-10 and scores between 0-100.  The id's and
 * scores of the students are output.  The summary function finds he maximum and minimum scores as well as the average of
 * all the scores.  Finally, the last function deallocates the memory from the array.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student
{
	int id;
	int score;
};

struct student* allocate()
{
     /*Allocate memory for ten students*/
     struct student *s = (struct student*) malloc(sizeof(struct student) * 10);
     /*return the pointer*/
     return s;
}

void generate(struct student* students)
{
    /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        (students + i) -> id = rand() % 20 + 1;
        (students + i) -> score = rand() % 101;
    }
}

void output(struct student* students)
{
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for (int i = 0; i < 10; i++)
    {
        printf("%d %d\n", (students + i) -> id, (students + i) -> score);
    }
}

void summary(struct student* students)
{
    /*Compute and print the minimum, maximum and average scores of the ten students*/
    int minimum = 100;
    int maximum = 0;
    int total = 0;
    int average = 0;

    for (int i = 0; i < 10; i++)
    {
        if (minimum > (students + i) -> score)
        {
            minimum = (students + i) -> score;
        }
        if (maximum < (students + i) -> score)
        {
            maximum = (students + i) -> score;
        }
        total += (students + i) -> score;
    }
    average = total / 10;
    printf("Maximum: %d\n", maximum);
    printf("Minimum: %d\n", minimum);
    printf("Average: %d\n", average);
}

void deallocate(struct student* stud)
{
    /*Deallocate memory from stud*/
    if (stud != NULL)
    {
        free(stud);
        stud = 0;
    }
}

int main()
{
    struct student* stud = NULL;
    /*call allocate*/
    stud = allocate(stud);
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
