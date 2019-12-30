#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define SIZE 10000

/**************************************************************
 * Hibbard : 1, 3, 7, 15, ..., 2 **(k+1) -1
 * Knuth : 1, 4, 13, 40, ..., 0.5 * (3 ** (k+1) - 1)
 * Sedgewick : 1, 8,  23, 77, ... 4 ** k + 3 * 2 ** (k-1) + 1, gap[0] = 1
 *************************************************************/
#define K 3

class Sort {
    public:
    void bubble ( int array[SIZE] );
    void selection ( int array[SIZE] );
    void insertion ( int array[SIZE] );
    void shell ( int array[SIZE] );
};

void Sort::bubble ( int array[SIZE] ) {
    for ( int i = 0; i < SIZE-1; i++ ) {
        for ( int j = SIZE-1; j > i; j-- ) {
            if ( array[j-1] > array[j] ) {
                int trade = array[j-1];
                array[j-1] = array[j];
                array[j] = trade;
            }
        }
    }
}

void Sort::selection ( int array[] ) {
    for ( int i = 0; i < SIZE-1; i++ ) {
        int min = i;
        for ( int j = i+1; j < SIZE; j++ ) {
            if ( array[j] < array[min] ) min = j;
        }
        int trade = array[i];
        array[i] = array[min];
        array[min] = trade;
    }
}

void Sort::insertion ( int array[] ) {
    for ( int i = 0; i < SIZE; i++ ) {
        int insert = array[i];
        int j = i - 1;
        while ( j >= 0 && insert < array[j] ) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = insert;
    }
}

void Sort::shell ( int array[] ) {
    int gap[K];
    int Two( int );

    for ( int k = 0; k < K; k++ ) {
        gap[k] = Two(k) - 1;
    }

    for ( int k = K; k >= 0; k-- ) {
        for ( int i = gap[k]; i < SIZE; i++ ) {
            int shell = array[i];
            int j = i - gap[k];
            while ( j >= 0 && shell < array[j] ) {
                array[ j + gap[k] ] = array[j];
                j = j - gap[k];
            }
            array[ j + gap[k] ] = shell;
        }
    }
}

int main ( int argc, char** argv ) {
    char cmd;
    int a[SIZE];
    Sort sort;

    while ( 1 ) {
        
        srand((unsigned)time(NULL));
        for ( int i = 0; i < SIZE; i++ ) {
            a[i] = rand();
        }
        
        cout << "----------------------------------------\nBefore ---> ";
        for ( int i = 0; i < SIZE; i++ ) {
            cout << a[i] << " ";
        }
        cout << "\n";

        cin >> cmd;

        if ( cmd == 'q' ) break;
        else if ( cmd == 'b' ) sort.bubble(a);
        else if ( cmd == 's' ) sort.selection(a);
        else if ( cmd == 'i' ) sort.insertion(a);
        else if ( cmd == 'l' ) sort.shell(a);

        cout << "After  ---> ";
        for ( int i = 0; i < SIZE; i++ ) {
            cout << a[i] << " ";
        }
        cout << "\n----------------------------------------\n" ;

    }
    
    return 0;
}

int Two ( int x ) {
    int two = 1;
    for ( int i = 1; i <= x; i++ ) two *= 2;
    return two;
}