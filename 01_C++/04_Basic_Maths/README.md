# Mathematical Algorithms

This document provides an overview of various mathematical algorithms, their logic, implementation details, and complexities. These algorithms are fundamental for solving common problems efficiently.

---

## 1. Extracting the Digits
Extract individual digits of a number.

### Input
- **Number**: 345

### Output
- **Digits**: 3, 4, 5

### Complexity
- **Time Complexity**: O(log10(N))

### Note
- If the number of iterations depends on division, the complexity is logarithmic.

---

## 2. Count Digits
Calculate the total number of digits in a number.

### Example
- Input: **345**
- Output: **3**

---

## 3. Palindrome
Check if a number is a palindrome (reads the same forward and backward).

### Example
- Input: **121**
- Output: **True**

---

## 4. Print All Divisors
Print all divisors of a given number.

### Example
- Input: **12**
- Output: **1, 2, 3, 4, 6, 12**

### Complexity
- **Time Complexity**: O(√N)

---

## 5. Mathematical Observation for Divisibility
Identify divisibility rules or properties for a given number.

### Example
- For divisibility by **3**, the sum of the digits must be divisible by **3**.

---

## 6. Prime Number
Determine if a number is prime.

### Example
- Input: **7**
- Output: **True**

### Logic
1. Check divisibility from **2** to √N.
2. If no divisors are found, the number is prime.

### Complexity
- **Time Complexity**: O(√N)

---

## 7. Armstrong Number
Check if a number is an Armstrong number (the sum of its digits raised to the power of the number of digits equals the number itself).

### Example
- Input: **153**
- Output: **True**

### Logic
- \( 1^3 + 5^3 + 3^3 = 153 \)

---

## 8. GCD/HCF
Find the greatest common divisor (GCD) or highest common factor (HCF) using the **Euclidean Algorithm**.

### Logic
1. \( gcd(a, b) = gcd(a - b, b) \), where \( a > b \).
2. Optimized: \( gcd(a, b) = gcd(a \% b, b) \).
3. If one value becomes zero, the other value is the GCD.

### Example
- Input: \( a = 54, b = 24 \)
- Output: \( GCD = 6 \)

### Complexity
- **Time Complexity**: O(log(min(a, b)))

---

### Notes
- These algorithms form the basis of many problem-solving approaches.
- Each algorithm is optimized to ensure efficient computation for large inputs.
