#include <iostream>
using namespace std;

struct Node {
    char data;
    struct Node *next;
};

class Stack {
    struct Node* top;

    public:
    Stack();
    void push(char value);
    void pop();
};

Stack::Stack() {
    top == NULL;
}

void Stack::push(char value) {
    struct Node* p = ( struct Node* )malloc( sizeof( struct Node ) );
    p->data = value;
    p->next = top;
    top = p;
}

void Stack::pop() {
    if( top == NULL ) cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}

int main() {
    Stack s1, s2;
    int i;

    s1.push('a');
    s2.push('b');
    s1.push('c');
    s2.push('d');
    s1.push('e');
    s2.push('f');

    for( i = 0; i < 3; i++ ) {
        cout << "s1: ";
        s1.pop();
    }
    for( i = 0; i < 3; i++ ) {
        cout << "s2: "; 
        s2.pop();
    }

    return 0;
}