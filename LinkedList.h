#include<iostream>
using namespace std;


//Forward Declaration
class LinkedList;

// Node
class Node{
private:
    int data;
    Node* next;
public:
    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    int getData(){
        return this->data;
    }

    // Deleting a node using destructor
    ~Node(){
        // This if block is like a recursive call
        // This will make a recursive call till next!=NULL
        // And when next==NULL, then it will deletes nodes from last
        if(next!=NULL){
            delete next;
        }
        // cout<<"Deleting node with data "<<data<<endl;
        
    }

    // using this, LinkedList class can access
    // the private data member of node class.
    friend class LinkedList;
};

// Linked List
class LinkedList{
private:
    Node* head;
    Node* tail;
public:
    //Constructor
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    //Methods
    // Print/Travese Linked List
    void print(){
        Node*ptr = head;
        while(ptr!=NULL){
            cout<<ptr->data<<"->";
            ptr = ptr->next;
        }
        
        cout<<"NULL\n";
    }

    // Insert at beginning
    void push_front(int data){
        // we have two cases,
        // 1. if head == NULL or Tail == NULL, means you have to create a new linked list,
        // create a new node and point head and tail to new node.

        if(head==NULL){
            //create new node
            Node* newNode = new Node(data);
            head = tail = newNode;
        }
        //2. if head != NULL or Tail != NULL, means there is an existing linked list,
        // and you have to insert new node in the beinning.
        else{
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
    }

    // Insert at end
    // we have two cases,
        // 1. if head == NULL or Tail == NULL, means you have to create a new linked list,
        // create a new node and point head and tail to new node.
    void push_back(int data){
        if(head==NULL){
            Node* newNode = new Node(data);
            head = tail = newNode;
        }
        //2. if head != NULL or Tail != NULL, means there is an existing linked list,
        // and you have to insert new node at the end.
        else{
            Node* newNode = new Node(data);
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert at given position
    void insert(int data, int pos){
        if(pos==0){
            //Insert at beginning
            push_front(data);
        }
        else{
            Node* temp = head;
            for (int jump=1; jump <= pos-1; jump++)
            {
                temp = temp->next;
            }

            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
            
        }
    }

    //Deletion entire linked list using destructor
    ~LinkedList(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
    }

    //Deleting Front node
    void pop_front(){
        if(head==NULL){
            cout<<"Linked List is already Empty\n";
        }
        else if(head->next==NULL){
            head = NULL;
            delete head;
        }
        else{
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    //Deleting Last node
    void pop_back(){
        if(head==NULL){
            cout<<"Linked List is already Empty\n";
        }
        else if(head->next==NULL){
            head = NULL;
            delete head;
        }
        else{
            Node* temp = head;
            //after this loop temp will reach to second last element
            while(temp->next->next!=NULL){
                temp = temp->next;
            }

            Node* last = tail;
            tail = temp;
            tail->next = NULL;
            delete last;
        }
    }

    // Deleting node at given position
    void deleteAtPos(int pos){
        // assume that pos <= len
        if(pos==0){
            // head node delete krna hai
            pop_front();
            return;

        }
        Node*  temp = head;
        Node*  prev_temp = head;
        for (int i = 1; i <= pos-1; i++)
        {
            prev_temp = temp;
            temp = temp->next;
        }
        // jo node delete krna hai us pr point
        // krega temp.
        // jo node delete krna hai us se just phele
        // waale nod pe point kreha prev_temp.
        prev_temp->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
   

};