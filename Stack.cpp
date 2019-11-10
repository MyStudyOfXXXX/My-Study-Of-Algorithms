#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node* top = NULL;

void Push(int value) {
    struct Node* p = ( struct Node* )malloc( sizeof( struct Node ) );
    p->data = value;
    p->next = top;
    top = p;
}

void Pop() {
    if( top == NULL ) cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}

void Display() {
   struct Node* ptr;
   if( top == NULL ) cout << "stack is empty";
   else {
       ptr = top; 
       cout << "Stack elements are: ";
       while (ptr != NULL) { 
           cout << ptr->data << " "; 
           ptr = ptr->next;
        }
    }
    cout << endl;
}

int main() {
    int n;
    int i = 0, j = 0;

    cin >> n;

    Display();

    for( i = 0; i < n; i++ ) {
        Push(i);
        Display();
        if ( i % 3 == 0 ) Pop();
    }

    Display();
    
    return 0;
}