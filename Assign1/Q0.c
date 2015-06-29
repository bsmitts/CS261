/* CS261- Assignment 1 - Q. 0*/
/* Name:  Brian Smith
 * Date:  04/08/15
 * Solution description:  An integer x is declared in main where the address is first printed out.  The address of x is then passed to the
 * fooA method which prints the value pointed to by *iptr, the address pointed to by iptr*, and the address of iptr.  After calling the
 * fooA method, the value of x is then printed.
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr)
{
    /*Print the value pointed to by iptr*/
    printf("The value pointed to by iptr: %d\n",*iptr);
    /*Print the address pointed to by iptr*/
    printf("The address pointed to by iptr: %p\n", iptr);
    /*Print the address of iptr itself*/
    printf("The address of iptr itself: %p\n", &iptr);
}

int main()
{
    /*declare an integer x*/
    int x = 5;
    /*print the address of x*/
    printf("The address of x: %p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("The value of x is: %d\n", x);
    return 0;
}
