#include <bits/stdc++.h>
#include <stack>
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
}*head;

stack<int> minstack;
stack<int> maxstack;

void push(int input)  // creates the node
{
    Node *new_Node = new Node(input);
    if(head == NULL)
    {
        head = new_Node;
        minstack.push(input);
        maxstack.push(input);
    }
    else
    {
        new_Node->next = head;
        head = new_Node;
        if(minstack.top()>input)
        {
            minstack.push(input);
        }
        else
        {
            minstack.push(minstack.top());
        }
        if(maxstack.top()<input)
        {
            maxstack.push(input);
        }
        else
        {
            maxstack.push(maxstack.top());
        }

    }

}

void pop()
{
    if(head == NULL)
    {
        cout<<"underflow";
    }
    else
    {
        Node *temp = head;
        cout << head -> data << endl ;
        head = head->next;
        minstack.pop();
        maxstack.pop();
        free(temp);
    }
}

void getmin()
{
    cout<<minstack.top()<<"\n";
}

void getmax()
{
    cout<<maxstack.top()<<"\n";
}
main()
{
    head = NULL;

    // 1 2 3 4 5 6 ...... -7
    int input ;

    while(true)
    {
        cin >> input ;
        if(input < 0)
            break ;
        push(input) ;
    }
    pop();
    getmax();
    getmin();
    return 0 ;
}
