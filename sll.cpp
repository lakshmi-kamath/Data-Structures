#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value=value;
        next=nullptr;     //next is not a parameter for Node class 
    }
};

class LinkedList{
    private:
        Node *head;
        Node *tail;
        int length;
    public:
    LinkedList(int value){                  //constructor
        Node *newnode=new Node(value);
        head=newnode; 
        tail=newnode;
        length=1;
    }

};
