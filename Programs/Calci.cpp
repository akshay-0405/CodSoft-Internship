#include <iostream>
using namespace std;

int main()
{
    double num1, num2;
    char operation;

    cout << "\n->->->->- Simple Calculator -<-<-<-<-\n";
    cout << "\nEnter first number: ";
    cin >> num1;

    cout << "-------------------------";
    cout << "\nEnter second number: ";
    cin >> num2;

    cout << "-------------------------\n";
    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    switch (operation)
    {
    case '+':
        cout << "Result: " << num1 + num2 << '\n';
        break;
    case '-':
        cout << "Result: " << num1 - num2 << '\n';
        break;
    case '*':
        cout << "Result: " << num1 * num2 << '\n';
        break;
    case '/':
        if (num2 != 0)
        {
            cout << "Result: " << num1 / num2 << '\n';
        }
        else
        {
            cout << "Error: Cannot divide by zero.\n";
        }
        break;
    default:
        cout << "Error: Invalid operation.\n";
    }

    return 0;
}
