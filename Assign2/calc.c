#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
    char *end;
    double num2;

    if(strcmp(s, "0") == 0)
    {
        *num = 0;
		return 1;
	}
	else 
	{
		num2 = strtod(s, &end);

		if((num2 != 0.0) && (strcmp(end, "") == 0))
		{
			*num = num2;
			return 1;
		}
	}
	return 0;
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 2)
    {
        printf("The stack does not contain two elements.\n\n");

        return;
    }
    
    double x;
    double y;
    double sum;

    x = topDynArr(stack);
    popDynArr(stack);

    y = topDynArr(stack);
    popDynArr(stack);

    sum = x + y;

    pushDynArr(stack, sum);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 2)
    {
        printf("The stack does not contain two elements.\n\n");

        return;
    }
    
    double x;
    double y;
    double difference;

    x = topDynArr(stack);
    popDynArr(stack);

    y = topDynArr(stack);
    popDynArr(stack);

    difference = x - y;

    pushDynArr(stack, difference);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 2)
    {
        printf("The stack does not contain two elements.\n\n");

        return;
    }

	double x;
    double y;
    double quotient;

    x = topDynArr(stack);
    popDynArr(stack);

    y = topDynArr(stack);
    popDynArr(stack);

    quotient = x / y;

    pushDynArr(stack, quotient);
}

void multiply(struct DynArr *stack)
{ 
    if(sizeDynArr(stack) < 2)
    {
        printf("The stack does not contain two elements.\n\n");

        return;
    }

    double x;
    double y;
    double product;

    x = topDynArr(stack);
    popDynArr(stack);

    y = topDynArr(stack);
    popDynArr(stack);

    product = x * y;

    pushDynArr(stack, product);
}

void power(struct DynArr *stack)
{ 
    if(sizeDynArr(stack) < 2)
    {
        printf("The stack does not contain two elements.\n\n");

        return;
    }

    double x;
    double y;
    double p;

    x = topDynArr(stack);
    popDynArr(stack);

    y = topDynArr(stack);
    popDynArr(stack);

    p = pow(x, y);

    pushDynArr(stack, p);
}

void square(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1)
    {
        printf("The stack has nothing to square.\n\n");

        return;
    }
    
    double x;
    double s;

    x = topDynArr(stack);
    popDynArr(stack);

    s = pow(x, 2);

    pushDynArr(stack, s);
}

void cube(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1)
    {
        printf("The stack has nothing to cube.\n\n");

        return;
    }

    double x;
    double c;

    x = topDynArr(stack);
    popDynArr(stack);

    c = pow(x, 3);

    pushDynArr(stack, c);
}

void absolute(struct DynArr *stack)
{ 
    if(sizeDynArr(stack) < 1)
    {
        printf("The stack has nothing to get the absolute value of.\n\n");

        return;
    }

    double x;
    double a;
    
    x = topDynArr(stack);
    popDynArr(stack);

    a = abs(x);

    pushDynArr(stack, a);
}

void squarert(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1)
    {
        printf("The stack has nothing to get the square root of.\n\n");
        return;
    }
    
    double x;
    double s;

    x = topDynArr(stack);
    popDynArr(stack);

    s = sqrt(x);

    pushDynArr(stack, s);

}

void exponential(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1)
    {
        printf("The stack has nothing to get the exponent of.\n\n");  

        return;
    }

    double x;
    double e;

    x = topDynArr(stack);
    popDynArr(stack);

    e = exp(x);

    pushDynArr(stack, e);
}

void naturalLog(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1)
    {
        printf("The stack has nothing to get the natural log of.\n\n");  

        return;
    }

    double x;
    double nL;

    x = topDynArr(stack);
    popDynArr(stack);

    nL = log(x);

    pushDynArr(stack, nL);
}

void tenthLog(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1)
    {
        printf("The stack has nothing to get the natural log of.\n\n");  

        return;
    }

    double x;
    double tL;

    x = topDynArr(stack);
    popDynArr(stack);

    tL = log10(x);

    pushDynArr(stack, tL);
}

double calculate(int numInputTokens, char **inputString)
{
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	double num;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(int i = 1;i < numInputTokens; i++) 
	{
		if(strcmp(s, "+") == 0)
		    add(stack);
		else if(strcmp(s,"-") == 0)
		    subtract(stack);
		else if(strcmp(s, "/") == 0)
		    divide(stack);
		else if(strcmp(s, "x") == 0)
		    multiply(stack);
		else if(strcmp(s, "^") == 0)
	        power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
            cube(stack);
		else if(strcmp(s, "abs") == 0)
            absolute(stack);
		else if(strcmp(s, "sqrt") == 0)
            squarert(stack);
		else if(strcmp(s, "exp") == 0)
            exponential(stack);
		else if(strcmp(s, "ln") == 0)
            naturalLog(stack);
		else if(strcmp(s, "log") == 0)
            tenthLog(stack);
		else if(isNumber(s, &num))
            pushDynArr(stack, num);
        else if(strcmp(s, "PI") == 0)
            pushDynArr(stack, 3.14);
        else if(strcmp(s, "E") == 0)
            pushDynArr(stack, 2.718);
	}

    if(sizeDynArr(stack) == 1)
    {
        printf("Final value = %f\n", topDynArr(stack));
	    return result;
    }
    else 
    {
        printf("Error... \n");
        return 0;
    }
	
	return result;
}

int main(int argc , char** argv)
{
    if (argc == 1)
        return 0;

    calculate(argc,argv);

    return 0;
}
