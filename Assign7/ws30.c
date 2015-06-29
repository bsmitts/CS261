struct BSTIterator 
{
    struct DynArr *stk;
    struct BSTree *tree;
};

void BSTIteratorInit (struct BSTree *tree, struct BSTIterator *itr) 
{
    itr -> tree = tree;

    itr -> stk = newDynArray();
}

int BSTIteratorHasNext (struct BSTIterator * itr)
{
    Bnode *n;

    if(isEmptyDynArr(itr -> stk))
    {
        _slideLeft(itr -> tree -> root)
    }
    else
    {
        n = topDynArr(itr -> stk);
        popDynArr(itr -> stk);
        _slideLeft(n -> right);
    }
} 

TYPE BSTIteratorNext (struct BSTIterator *itr)
{
    TYPE next = topDynArr(itr -> stk) -> val;

    return next;
}

void _slideLeft(struct Node *cur, struct BSTIterator *itr) 
{ 
    While(cur != null) 
    { 
        dynArrayPush(Itr->stk, cur->val); 
        cur = cur->left;
    } 
} 

