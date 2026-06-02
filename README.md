# Infix to Postfix Expression Converter & Evaluator

## Stack-Based Expression Parsing and Evaluation System

### Overview

This project implements a complete expression processing system capable of converting mathematical expressions from **Infix Notation** to **Postfix Notation (Reverse Polish Notation)** and evaluating the resulting postfix expression using stack-based algorithms.

The application demonstrates core concepts in **Data Structures**, **Algorithms**, and **Compiler Design**, including expression parsing, operator precedence management, associativity handling, and stack-based computation. A Windows GUI output interface is integrated to provide a user-friendly visualization of the conversion and evaluation process.

---

## Features

* Infix to Postfix Conversion
* Postfix Expression Evaluation
* Stack-Based Parsing Algorithm
* Operator Precedence Handling
* Parentheses Processing
* Exponentiation Support (`^`)
* Multi-Digit Operand Support
* Arithmetic Expression Computation
* Windows GUI Result Display
* Linear-Time Processing Complexity

---

## Supported Operators

| Operator | Operation      |
| -------- | -------------- |
| +        | Addition       |
| -        | Subtraction    |
| *        | Multiplication |
| /        | Division       |
| ^        | Exponentiation |
| ( )      | Parentheses    |

---

## Example

### Input

```text
10 + 2 * 3
```

### Generated Postfix

```text
10 2 3 * +
```

### Result

```text
16
```

---

## Algorithm Workflow

1. Parse the infix expression.
2. Use a stack to manage operators and parentheses.
3. Generate the equivalent postfix expression.
4. Evaluate the postfix expression using a second stack.
5. Display the postfix notation and final result.

---

## Technologies Used

* C Programming Language
* Windows API (WinAPI)
* Stack Data Structure
* Mathematical Libraries
* Expression Parsing Algorithms

---

## Concepts Demonstrated

* Data Structures (Stacks)
* Expression Parsing
* Algorithm Design
* Compiler Fundamentals
* Operator Precedence Parsing
* Postfix Evaluation
* Windows Programming

---

## Time Complexity

| Operation                   | Complexity |
| --------------------------- | ---------- |
| Infix to Postfix Conversion | O(n)       |
| Postfix Evaluation          | O(n)       |
| Overall Processing          | O(n)       |

---

## Author

**Omar Mohamed Kamal**

Artificial Intelligence Student | Software Developer | Cybersecurity Enthusiast
