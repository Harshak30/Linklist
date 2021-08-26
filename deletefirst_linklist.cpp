#include <bits/stdc++.h>
using namespace std ;

class Node
{
    public:
    int data ;
    Node *next ;

    Node(int x)
    {
        data = x ;
        next = NULL ;
    }
}*first, *last, *temp ;

void create(int input)  // creates the node
{
    Node *new_node ;
    new_node = new Node(input) ;

    // connection part
    if(first == NULL)
        first = new_node ;

    else
        last -> next = new_node ;

    last = new_node ;
}

void delete_first()
{
 if(first != NULL)
    {
     temp = first ;
       first = first -> next ;
       free(temp) ;
    }
}

void display()
{
    temp = first ;
    while(temp != NULL)
    {
        cout << temp -> data << endl ;
        temp = temp -> next ;
    }
    //cout << "NULL" ;
}

main()
{
    first = last = NULL ;

    // 1 2 3 4 5 6 ...... -7
    int input ;

    while(true)
    {
        cin >> input ;
        if(input < 0)
            break ;
        create(input) ;
    }
   delete_first() ;
    display() ;

    return 0 ;
}
