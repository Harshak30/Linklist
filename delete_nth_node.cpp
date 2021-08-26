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
}                               // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

void delete_node(int n)
{
    if(first->data == n)
    {
        temp = first ;
        first = first->next ;
        free(temp) ;
    }

    Node* temp = first;
    while(temp->next!=NULL && temp->next->data!=n)  // n = 3
        temp = temp->next ;

    if(temp->next == NULL)
        cout << "Element not Found\n" ;

    else
    {
        Node *temp1 ;
        temp1 = temp -> next ;
        temp->next = temp1->next ;
        free(temp1) ;
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
    //cout << "NULL\n" ;
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
    display() ;
    int delete_value ;
    cin >> delete_value ;
    delete_node(delete_value) ;
    cout << "After deletion:\n" ;
    display() ;
    return 0 ;
}
