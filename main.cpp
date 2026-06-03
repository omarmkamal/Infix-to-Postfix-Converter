#include <windows.h>
#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>

#define MAX 100

// --- Your Original Logic Functions (Same as before) ---
char stack[MAX];
int top = -1;
void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    top = -1;
    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) { postfix[j++] = infix[i++]; }
            postfix[j++] = ' ';
            continue;
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') { postfix[j++] = pop(); postfix[j++] = ' '; }
            pop();
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (!isEmpty() && ((infix[i] != '^' && priority(peek()) >= priority(infix[i])) || (infix[i] == '^' && priority(peek()) > priority(infix[i])))) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(infix[i]);
        }
        i++;
    }
    while (!isEmpty()) { postfix[j++] = pop(); postfix[j++] = ' '; }
    postfix[j] = '\0';
}

int numStack[MAX];
int numTop = -1;
void pushNum(int x) { numStack[++numTop] = x; }
int popNum() { return numStack[numTop--]; }

int evaluatePostfix(char postfix[]) {
    int i = 0;
    numTop = -1;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) { num = num * 10 + (postfix[i] - '0'); i++; }
            pushNum(num);
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            int op2 = popNum(); int op1 = popNum();
            int res = 0;
            if (postfix[i] == '+') res = op1 + op2;
            else if (postfix[i] == '-') res = op1 - op2;
            else if (postfix[i] == '*') res = op1 * op2;
            else if (postfix[i] == '/') res = (op2 != 0) ? op1 / op2 : 0;
            else if (postfix[i] == '^') res = (int)pow(op1, op2);
            pushNum(res);
        }
        i++;
    }
    return popNum();
}

// --- GUI INPUT BOX HELPER ---
// This function mimics Java's JOptionPane.showInputDialog
std::string showInputBox() {
    char buffer[MAX] = {0};
    // We use a small VBScript snippet via the command line to get a GUI input box
    FILE* pipe = _popen("powershell -Command \"Add-Type -AssemblyName Microsoft.VisualBasic; [Microsoft.VisualBasic.Interaction]::InputBox('Enter Infix Expression:', 'Calculator Input')\"", "r");
    if (pipe) {
        fgets(buffer, MAX, pipe);
        _pclose(pipe);
    }
    std::string s = buffer;
    return s.substr(0, s.find_last_not_of(" \n\r\t") + 1); // trim whitespace
}

int main() {
    // 1. POP UP THE INPUT BOX (Like JOptionPane)
    std::string input = showInputBox();

    if (input.empty()) {
        MessageBox(NULL, "No input detected!", "Error", MB_OK | MB_ICONERROR);
        return 0;
    }

    char infix[MAX], postfix[MAX];
    strcpy(infix, input.c_str());

    // 2. DO THE CONVERSION & MATH
    infixToPostfix(infix, postfix);
    int result = evaluatePostfix(postfix);

    // 3. POP UP THE RESULT BOX (Like JOptionPane)
    char resultMsg[300];
    sprintf(resultMsg, "Postfix: %s\n\nResult = %d", postfix, result);
    MessageBox(NULL, resultMsg, "Calculation Done", MB_OK | MB_ICONINFORMATION);

    return 0;
}
