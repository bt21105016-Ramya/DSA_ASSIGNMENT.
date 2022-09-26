// Question 1
#include <iostream>
using namespace std;

class Node{
   public:
    int data;
    Node*next;
    
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void append(Node*&head,int data){
    Node*temp=head;
    Node*new_node=new Node(data);
    if(temp==NULL){head=new_node;new_node->next=head;return;}
    while(temp->next!=head){temp=temp->next;}   
    temp->next=new_node;
    new_node->next=head;
}

void pfun(Node*&head){
    Node*temp=head;
    do{cout<<temp->data<<"->";temp=temp->next;}
    while(temp!=head);
}

int main(){
    Node*head=NULL;
    append(head,1);
    append(head,2);
    append(head,3);
    pfun(head);
}


/*Question 2
1)Multiplayer Games: All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.
2)Computing Resources: Circular Linked Lists is used to manage the computing resources of the computer.
3)Fionacci Heap: Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.
4)Computer Networking:Circular linked list is also used in computer networking for token scheduling.
5)Implementation of Data Structure: Data structures such as stacks and queues are implemented with the help of the circular linked lists.
6)Audio/Video Streaming: Circular linked list is also used in audio and video streaming,for ex. when one copmlete audio list finishes playing in music player then it again starts playing from start.
*/