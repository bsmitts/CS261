#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink
{
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */
struct linkedList
{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/
void _initList (struct linkedList *lst)
{
    assert(lst != 0);

    lst -> size = 0;

    lst -> firstLink = (struct DLink*)malloc(sizeof(struct DLink));

    lst -> lastLink = (struct DLink*)malloc(sizeof(struct DLink));

    assert(lst -> firstLink != 0);

    assert(lst -> lastLink != 0);

    lst -> firstLink -> next = lst -> lastLink;

    lst -> lastLink -> prev = lst -> firstLink;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */
struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */
void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
    assert(lst != 0);

    assert(l != 0);

    struct DLink* link;
    link = (struct DLink*)malloc(sizeof(struct DLink));

    assert(link != 0);

    link -> value = v;

    link -> next = l;

    link -> prev = l -> prev;

    l -> prev -> next = link;

    l -> prev = link;

    lst -> size++;
}

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addFrontList(struct linkedList *lst, TYPE e)
{
    assert(lst != 0);

    _addLinkBefore(lst, lst -> firstLink -> next, e);
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/
void addBackList(struct linkedList *lst, TYPE e)
{
    assert(lst != 0);

    _addLinkBefore(lst, lst -> lastLink, e);
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/
TYPE frontList (struct linkedList *lst)
{
    assert(lst != 0);

    assert(lst -> size != 0);

    return (lst -> firstLink -> next -> value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/
TYPE backList(struct linkedList *lst)
{
    assert(lst != 0);

    assert(lst -> size != 0);

    return (lst -> firstLink -> prev -> value);
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{
    assert(lst != 0);

    assert(l != 0);

    l -> prev -> next = l -> next;

    l -> next -> prev = l -> prev;

    lst -> size--;

    free(l);
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/
void removeFrontList(struct linkedList *lst)
{
    assert(lst != 0);

    assert(lst -> size != 0);

    _removeLink(lst, lst -> firstLink -> next);
}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/
void removeBackList(struct linkedList *lst)
{
    assert(lst != 0);

    assert(lst -> size != 0);

    _removeLink(lst, lst -> lastLink -> prev);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/
int isEmptyList(struct linkedList *lst)
{
    assert(lst != 0);

    if(lst -> size > 0)
        return 1;

    return 0;
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
    assert(lst != 0);

    struct DLink* link;
    link = (struct DLink*)malloc(sizeof(struct DLink));

    link = lst -> firstLink;

    while(link -> next != lst -> lastLink)
    {
        link = link -> next;
        printf("%d\n", link -> value);
    }

    free(link);
}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
    assert(lst != 0);

    _addLinkBefore(lst, lst -> firstLink -> next, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e)
{
    assert(lst != 0);

    assert(lst -> size != 0);

    struct DLink* link;
    link = (struct DLink*)malloc(sizeof(struct DLink));

    link = lst -> firstLink;

    while(link -> next != lst -> lastLink)
    {
        link = link -> next;

        if(link -> value == e)
        {
            free(link);
            return 1;
        }
    }

    free(link);

    return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e)
{
    assert(lst != 0);

    assert(lst -> size != 0);

    struct DLink* link;
    link = (struct DLink*)malloc(sizeof(struct DLink));

    link = lst -> firstLink;

    while(link -> next != lst -> lastLink)
    {
        link = link -> next;

        if(link -> value == e)
        {
            _removeLink(lst, link);
            free(link);
        }
    }
    free(link);
}
