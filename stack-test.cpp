#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

int main(int argc, char* argv[])
{
    Stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    cout << "Top: " << myStack.top() << endl;
    
    myStack.pop();

    cout << "Top: " << myStack.top() << endl;
    cout << "Size: " << myStack.size() << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    
    return 0;
}
