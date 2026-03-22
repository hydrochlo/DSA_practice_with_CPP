#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node *head;
    Node *tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node *newNode = new Node(val);
        // Node newNode(val); // static
        if(head == NULL) {
            head = tail = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }

    }

    void push_back(int val){
        Node *newNode = new Node(val);
        if(head == tail){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){

        if(!head){
            cout << "Empty LinkedList\n";
        }

        Node *itr = this->head;
        this->head = itr->next;
        itr->next = NULL;
        delete itr;
    }

    void pop_back(){
        if(!head){
            cout << "LL is empyt\n";
        }
        Node *temp = this->head;
        while(temp->next != this->tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        this->tail = temp;
    }

    void print(){
        Node *itr = this->head;
        while (itr){
            cout << itr->data << " -> ";
            itr = itr->next;
        } cout << endl;
    }

};

int main(){
    List ll;

    ll.push_front(5);
    ll.push_front(15);
    ll.push_front(25);
    ll.push_back(60);
    ll.print();
    cout << endl;
    
    ll.pop_front();

    ll.print();

    ll.pop_back();
    ll.print();
    return 0;
}