#include <iostream>                  
using namespace std;                

//Node Class:
class Node{
    public:
    string name;
    int age;
    Node*next; 
    Node*prev; 
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; 
        prev=NULL; 
    }
};

//Add data at start of the list
void insert_at_head(Node*&head,string name,int age){
    Node*new_node=new Node(name,age);
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//Add data at end of the list
void append(Node* &head,string name,int age){
    Node*temp=head;
    Node*new_node=new Node(name,age);
    if(temp==NULL){
        head=new_node;
    }
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//Display data from start of the list
void display_from_start(Node*head){
    Node*temp=head;
    while(temp!=NULL){cout<<"[Name: "<<temp->name<<" Age: "<<temp->age<<"]"<<"||";temp=temp->next;}
    cout<<endl;
}

//display data from end if the list
void display_from_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name: "<<temp->name<<" Age: "<<temp->age<<"]"<<"||";temp=temp->prev;}
    cout<<endl;
}

//Delete index
void delete_ind(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//Delete last element from the list
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    Node*head=NULL;
	int no_of_family_mem;
	cout<<"Enter number of members in family:";cin>>no_of_family_mem;
	for(int i=1;i<=no_of_family_mem;i++){
		string name;
		int age;
		cout<<"Enter family Member "<<i<<" name: ";cin.ignore();getline(cin,name);
		cout<<"Enter family Member "<<i<<" age: ";cin>>age;
		append(head,name,age);
	}
    cout<<endl;
    cout<<"A doubly linked list with my family members as elements"<<endl;
    cout<<endl;
    display_from_start(head);
}


/*BONUS QUESTION
Q.Try to find a way to link the family members' doubly-linked list based on
 their relationship.
Ans.We can sort the doubly linked list according to age in ascending order.
By doing so we will get a doubly linked list in which older generation people
will be close to tail in double linked list and new generation people will be 
close to head in doubly linked list.
*/