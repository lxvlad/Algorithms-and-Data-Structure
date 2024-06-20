#include "Stack.cpp"
#include <iostream>
#include <stack>

int main()
{
    // STL stack
    std::stack<int> STLStack;

    STLStack.push(1);
    STLStack.push(2);

    std::cout << "STL Stack:" << std::endl;
    std::cout << "Top element: " << STLStack.top() << std::endl;

    STLStack.pop();
    std::cout << "Top element after pop: " << STLStack.top() << std::endl;
    std::cout << "Is empty: " << std::boolalpha << STLStack.empty() << std::endl;

    STLStack.pop();
    std::cout << "Top element after again pop: " << STLStack.top() << std::endl;
    std::cout << "Is empty: " << std::boolalpha << STLStack.empty() << std::endl;


    std::cout << "\n***********\n";


    // My stack
    Stack MyStack;

    MyStack.push(1);
    MyStack.push(2);

    std::cout << "My Stack:" << std::endl;
    std::cout << "Top element: " << MyStack.top() << std::endl;

    MyStack.pop();
    std::cout << "Top element after pop: " << MyStack.top() << std::endl;
    std::cout << "Is empty: " << std::boolalpha << MyStack.empty() << std::endl;

    MyStack.pop();
    std::cout << "Top element after again pop: " << MyStack.top() << std::endl;
    std::cout << "Is empty: " << std::boolalpha << MyStack.empty() << std::endl;


    return 0;
}
