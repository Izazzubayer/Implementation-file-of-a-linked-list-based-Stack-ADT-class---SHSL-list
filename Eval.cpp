/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Izaz Zubayer (301386899) and Zoe Stanley (301427509)
 * Modified on: February 2024
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;

// Exception handling for divison by zero, user-defined class to
// avoid using std functions. 
class DivisionByZeroError {
    private:
        const char * message;   // avoiding <string> in case not allowed

    public: 
        DivisionByZeroError(const char * message) : message(message) {}

        const char * what() const {
            return message;
        }

};

// Function for arithmetic
int performOperation(int num1, int num2, char symbol) {
    switch (symbol) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                throw DivisionByZeroError("Division by zero, computation error.");
            }
            return num1 / num2;
        default:
            throw DivisionByZeroError("Invalid operator found.");  // Invalid operator
    }
}


int main() {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token

    t = S.getnext();

    try {

        while (t.tt != eof || !opstack.isEmpty()) {
            if (t.tt == integer) {
                numstack.push(t);
                t = S.getnext();
            } else if (t.tt == lptok) {
                opstack.push(t);
                t = S.getnext();
            } else if (t.tt == rptok) {
                while (opstack.peek().tt != lptok) {
                    Token symbol = opstack.pop();
                    int num2 = numstack.pop().val;
                    int num1 = numstack.pop().val;
                    int result = performOperation(num1, num2, symbol.text[0]);
                    numstack.push(Token{integer, "", result});
                }
                opstack.pop();  // Pop the left parenthesis
                t = S.getnext();
            } else if (t.tt == pltok || t.tt == mitok || t.tt == asttok || t.tt == slashtok || t.tt == eof) {
                while (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok ||
                                           opstack.peek().tt == asttok || opstack.peek().tt == slashtok)) {
                    Token symbol = opstack.pop();
                    int num2 = numstack.pop().val;
                    int num1 = numstack.pop().val;
                    int result = performOperation(num1, num2, symbol.text[0]);
                    numstack.push(Token{integer, "", result});
                }
                if (t.tt != eof) {
                    opstack.push(t);
                    t = S.getnext();
                }
            } if (t.tt == asttok || t.tt == slashtok) {
                while (!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)) {
                    Token symbol = opstack.pop();
                    int num2 = numstack.pop().val;
                    int num1 = numstack.pop().val;
                    int result = performOperation(num1, num2, symbol.text[0]);
                    numstack.push(Token{integer, "", result});
                }
                opstack.push(t);
                t = S.getnext();
            }
        }

        cout << numstack.pop().val << endl;


    } catch (const DivisionByZeroError& anException) {
        
        cout << "Error: " << anException.what() << endl;
    }

    return 0;
}