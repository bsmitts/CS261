/* CS261- Assignment 1 - Q.5*/
/* Name:  Brian Smith
 * Date:  04/09/15
 * Solution description:  A char word is declared in main and the user is prompted to enter a word.  The uer enters a word which is then passed to sticky,
 * and the word is printed again.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch)
{
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch)
{
     return ch-'A'+'a';
}

void sticky(char* word)
{
    /*Convert to sticky caps*/
    for (int i = 0; i < strlen(word); i++)
    {
        if ((i % 2) == 0)
        {
            if(!isupper(*(word + i)))
            {
                *(word + i) = toUpperCase(*(word + i));
            }
            else if ((i % 2) == 1)
            {
                *(word + i) = toLowerCase(*(word + i));
            }
        }
    }
}

int main()
{
    /*Read word from the keyboard using scanf*/
    char word[100];

    printf("Please enter a word: \n");
    scanf("%s", word);

    /*Call sticky*/
    sticky(word);
    /*Print the new word*/
    printf("Your word in sticky caps is: %s\n", word);

    return 0;
}
