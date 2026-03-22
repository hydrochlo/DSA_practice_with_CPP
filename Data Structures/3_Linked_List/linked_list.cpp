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

    void push_front(int val){ // O(1)
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

    void push_back(int val){ // using "tail" -> O(1)
                            // Not using "taile" -> O(n)
        Node *newNode = new Node(val);
        if(head == tail){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int get_length(){ // O(n)
        Node *itr = this->head;
        int count = 0;
        while(itr){
            count++;
            itr = itr->next;
        }
        return count;
    }

    void pop_front(){ // O(1)

        if(!head){
            cout << "Empty LinkedList\n";
        }

        Node *itr = this->head;
        this->head = itr->next;
        itr->next = NULL;
        delete itr;
    }

    void pop_back(){ // O(n)
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

    void insert_at(int pos, int val){ //O(n)
        Node *newNode = new Node(val);
        if(pos < 0 || pos > this->get_length()){
            cout << "Invalid position" << "\n";
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        int count = 0;
        Node *itr = this->head;
        while(itr){
            if(count == pos-1){
                newNode->next = itr->next;
                itr->next = newNode;
                break;
            }
            itr = itr->next;
            count++;
        }

    }

    int search(int val){ // O(n)
        Node *itr = this->head;
        int count = 0;

        while(itr){
            if(itr->data == val){
                return count+1;
            } 
            itr = itr->next;
            count++;
        }
        return -1;
    }

    void print(){ // O(n)
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
    ll.get_length();
    cout << endl;
    
    ll.pop_front();

    ll.print();

    ll.pop_back();
    ll.print();

    ll.insert_at(1, 10);
    ll.print();

    cout << ll.search(50) << endl;
    return 0;
}