//
// Created by Vladyslav Lishchynskyi on 21.06.2024.
//

#include "ReverseEntry.h"
int priority(char c)
{
    switch (c)
    {
    case '^': return 3;
    case '*': case '/': return 2;
    case '+': case '-': return 1;
    case '#': case '(': case ')': return 0;
    default: return -1;
    }
}

bool isDigital(char c)
{
    return '0' <= c && c <= '9';
}

bool isOperand(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '^');
}

double applyOperator(double op1, double op2, char op)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    case '^':
        return pow(op1, op2);
    default:
        return 0;
    }
}

string toPostfix(string infix)
{
    string postfix;
    stack <char> Stack;
    Stack.push('#');
    for (char c : infix)
    {
        if (isdigit(c))
            postfix += c;
        else
        {
            int p = priority(c);
            switch (c)
            {
            case '+': case '-': case '*': case '/': case'^':
                while (priority(Stack.top()) >= p)
                {
                    postfix += Stack.top(); Stack.pop();
                }
                Stack.push(c); break;
            case '(':
                Stack.push(c); break;
            case ')':
                while (Stack.top() != '(')
                {
                    postfix += Stack.top();
                    Stack.pop();
                }
                Stack.pop(); break;
            }
        }
    }
    while (Stack.top() != '#')
    {
        postfix += Stack.top(); Stack.pop();
    }
    return postfix;
}

int calculate(string expr)
{
    stack <int> Stack;
    for (char c : expr)
    {
        if (isdigit(c))
        {
            Stack.push(c - '0');
        }
        else
        {
            int right = Stack.top(); Stack.pop();
            int left = Stack.top(); Stack.pop();
            switch (c)
            {
            case '+': Stack.push(left + right); break;
            case '-': Stack.push(left - right); break;
            case '*': Stack.push(left * right); break;
            case '/':
                if (right != 0) {
                    Stack.push(left / right);
                }
                else {
                    cout << "Error: Division by zero!\n";
                    return -1;
                }
                break;
            case '^': Stack.push(pow(left, right)); break;
            }
        }
    }
    return Stack.top();
}

string toInfix(string postfix)
{
    stack<string> Stack;
    for (char c : postfix)
    {
        if (isOperand(c))
        {
            string op2 = Stack.top(); Stack.pop();
            string op1 = Stack.top(); Stack.pop();
            string exp = "(" + op1 + c + op2 + ")";
            Stack.push(exp);
        }
        else
        {
            string operand(1, c);
            Stack.push(operand);
        }
    }
    return Stack.top();
}

void choice()
{
    string expression, notation;
    int choice;

    do
    {
        cout << "1. Enter infix notation\n";
        cout << "2. Enter postfix notation\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << '\n';

        switch (choice)
        {
        case 1:
            cout << "Enter infix notation: ";
            cin.ignore();
            getline(cin, expression);
            if (!expression.empty())
            {
                notation = toPostfix(expression);
                cout << "Postfix notation: " << notation << '\n';
                cout << "Result: " << calculate(notation) << "\n\n";
            }
            break;
        case 2:
            cout << "Enter postfix notation: ";
            cin.ignore();
            getline(cin, expression);
            if (!expression.empty())
            {
                notation = toInfix(expression);
                cout << "Infix notation: " << notation << '\n';
                cout << "Result: " << calculate(expression) << "\n\n";
            }
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 3);
}
