#include <iostream>
#include <fstream>
#include "heap.h"

using namespace std;


int main(int argc, char* argv[])
{
    Heap<int> myHeap(3);
    myHeap.push(10000);
    cout << "DATA: ";
    for (auto i: myHeap.data) {
        cout << i << " ";
    }
    cout << endl;

    myHeap.push(2);
    
    cout << "DATA: ";
    for (auto i: myHeap.data) {
        cout << i << " ";
    }
    cout << endl;

    myHeap.push(3);
    myHeap.push(4);
    myHeap.push(5);
    myHeap.push(6);

    cout << "DATA: ";
    for (auto i: myHeap.data) {
        cout << i << " ";
    }
    cout << endl;
    
    myHeap.pop();
    cout << "DATA: ";
    for (auto i: myHeap.data) {
        cout << i << " ";
    }
    cout << endl;

    myHeap.pop();
    myHeap.pop();
    
    return 0;
}
