#include <iostream>
using namespace std;

struct Node {
   int data;
   struct Node *next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
struct Node* temp;

void Insert() {
    int value;
    cout << "Insert the element in queue : " <<endl;
    cin >> value;
    if ( rear == NULL ) {
        rear = ( struct Node* )malloc( sizeof( struct Node ) );
        rear->next = NULL;
        rear->data = value;
        front = rear;
    } 
    else {
        temp = ( struct Node* )malloc( sizeof( struct Node ) );
        rear->next = temp;
        temp->data = value;
        temp->next = NULL;
        rear = temp;
    }
}

void Delete() {
    temp = front;
    if ( front == NULL ) {
        cout << "Underflow" << endl;
        return;
    }
    else
    if ( temp->next != NULL ) {
        temp = temp->next;
        cout << "Element deleted from queue is : " << front->data << endl;
        free(front);
        front = temp;
    } 
    else {
        cout << "Element deleted from queue is : " << front->data << endl;
        free(front);
        front = NULL;
        rear = NULL;
    }
}

void Display() {
    temp = front;
    if ( ( front == NULL ) && ( rear == NULL ) ) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main () {
    int n;
    int i = 0, j = 0;

    cin >> n;

    Display();

    for( i = 0; i < n; i++ ) {
        Insert();
        Display();
        if ( i % 3 == 0 ) Delete();
    }

    Display();
    return 0;
}