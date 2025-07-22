# Recursion in Programming

## What is Recursion?

Recursion is a programming technique where a function calls itself to solve smaller sub-problems of the original problem. It continues until a specified **base condition** is met, ensuring the recursion stops and avoids infinite calls.

---

## Key Characteristics of Recursion
1. **Function Calls Itself**: The recursive function keeps calling itself repeatedly.
2. **Base Condition**: To prevent infinite recursion, a base condition is defined that terminates the recursive process.
3. **Recursive Tree**: A diagrammatic representation of recursion showcasing the sequence of function calls.

---

## Why Use Recursion?
- Solves problems by breaking them into smaller sub-problems.
- Makes code cleaner and easier to understand for problems like factorial, Fibonacci sequence, and tree traversals.

---

## Risks of Recursion
- **Infinite Recursion**: If no base condition is specified, the function will continue to call itself infinitely, causing a **stack overflow** error.
- **Performance**: Recursion can be inefficient for problems with overlapping sub-problems. Consider using dynamic programming in such cases.

---

## Example: Factorial Calculation

### Problem
Calculate the factorial of a number \( n \) using recursion.  
The factorial of \( n \), denoted as \( n! \), is the product of all positive integers up to \( n \):  
\[ n! = n \times (n-1) \times (n-2) \times ... \times 1 \]  

### Base Condition
- \( 0! = 1 \)
- \( 1! = 1 \)

### Recursive Formula
- \( n! = n \times (n-1)! \)

---

### Implementation in C++
```cpp
#include <iostream>
using namespace std;

// Function to calculate factorial using recursion
int factorial(int n) {
    // Base condition: If n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive call
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Enter a number to calculate its factorial: ";
    cin >> number;

    // Calculate factorial
    int result = factorial(number);

    // Output the result
    cout << "The factorial of " << number << " is: " << result << endl;

    return 0;
}

```
## Complexity :
            time complexity :O(n)
            space complexity : O(n)

# To print first N sum
- Parameterized Way: Pass sum as a parameter.
- Functional Way: Return the computed sum.


# Fibonacci Series Using Multiple Recursion

## What is Fibonacci Series?

The Fibonacci series is a sequence of numbers where each number is the sum of the two preceding ones. The sequence starts with 0 and 1:

[ F(0) = 0,  F(1) = 1,  F(n) = F(n-1) + F(n-2) ]