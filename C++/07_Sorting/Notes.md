# Sorting Algorithms

## Selection Sort
- Get the minimum and swap it.
- Repeat until sorted.
- **Complexity**:  
  In all cases: **O(n²)**

---

## Bubble Sort
- Iterate from 0 to n-1.
- Compare adjacent elements.
- Push the maximum element to the last position by swapping.
- **Complexity**:  
  - Worst case: **O(n²)**  
  - Best/Average case: **O(n)**

---

## Insertion Sort
- Iterate from 0 to n-1.
- Compare and place the element in its correct order.
- **Complexity**:  
  - Best case: **O(n)**  
  - Average/Worst case: **O(n²)**

---

## Merge Sort
- It is a much more optimized sorting algorithm.  
- **Steps**:
  1. Divide the array into two halves.
  2. Sort each half recursively.
  3. Merge the two sorted halves.
- **Complexity**:  
  - Time complexity: **O(n log n)**  
  - Space complexity: **O(n)**

---

## Quick Sort
- **Steps**:
  1. Pick an element as the pivot (by your choice).
  2. Place smaller elements on the left and larger on the right.
- **Complexity**:  
  - Time complexity: **O(n log n)**  
  - Space complexity: **O(1)**
