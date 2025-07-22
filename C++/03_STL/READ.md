# Containers Overview

This document provides an overview of various container types and their functionality, including **Pair**, **Vector**, **List**, **Stack**, **Queue**, **Priority Queue**, **Set**, **Multiset**, **Unordered Set**, **Map**, **Multimap**, and **Unordered Map**.

## Pair
A **Pair** is a container that stores multiple values together in a single entity. It can handle integers, arrays, or any data type. Values are stored in curly braces `{}`.

### Features
- **Flexible**: Can store multiple related values in one container.
- **Data Types**: Can contain integers, arrays, or other data types.
- **Syntax**:
  ```cpp
  pair<int, int> p1 = {1, 2};
  pair<int, string> p2 = {1, "example"};
  ```

---

## Vector
A **Vector** is a dynamic array that can grow and shrink in size. It supports various methods for adding, removing, and accessing elements.

### Features
- **Dynamic Size**: Automatically adjusts its size when elements are added or removed.
- **Data Storage**: Can store integers, pairs, or other complex data types.
- **Methods**:

#### Adding Elements
1. **push_back**: Adds elements to the end of the vector.
   ```cpp
   vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back({1, 2}); // For pairs, explicitly use {}
   ```
2. **emplace_back**: Similar to `push_back`, but it constructs the value in place (more efficient for complex objects).
   ```cpp
   vector<pair<int, int>> vp;
   vp.emplace_back(1, 2); // No need for {}
   ```

#### Iterators
- **v.begin()**: Points to the first element.
- **v.end()**: Points to the element next to the last.
- **v.rbegin()**: Points to the last element (reverse begin).
- **v.rend()**: Points to the element before the first (reverse end).
- **v.back()**: Points to the last element.
- **v.erase()**: Removes elements from the vector.
  
#### Example
```cpp
vector<int> v = {1, 2, 3, 4};
auto it = v.begin();
cout << *it; // Outputs: 1

v.erase(it); // Removes the first element
cout << v.front(); // Outputs: 2
```

#### Auto Keyword
- Automatically detects the data type of the container elements.
  ```cpp
  for (auto x : v) {
      cout << x << " ";
  }
  ```

---

## List
A **List** is a collection of items stored in a single variable. It is more efficient than a vector for insertions and deletions at the front.

### Features
- **Ordered and Changeable**: Elements are stored in a specific order and can be modified.
- **Dynamic**: Automatically adjusts its size.
- **Data Types**: Can store values of any data type.
- **Duplicate Values**: Allows duplicate elements.
- **Operations**:
  - **push_front()**: Inserts an element at the front (more efficient than `vector::insert`).
  - **push_back()**: Inserts an element at the end.
  - **insert()**: Inserts elements at specific positions.
  - **sort()**: Sorts the list.
  - **reverse()**: Reverses the list.
  - **pop()**: Removes the last element.
  - **clear()**: Removes all elements.

#### Example
```cpp
list<int> l;
l.push_front(10);
l.push_back(20);
cout << l.front(); // Outputs: 10
```

---

## Stack
A **Stack** is a container that follows the Last In, First Out (LIFO) principle.

### Features
- **push()**: Adds an element to the top of the stack.
- **pop()**: Removes the top element from the stack.
- **top()**: Accesses the top element.
- **empty()**: Checks if the stack is empty.

#### Example
```cpp
stack<int> s;
s.push(10);
s.push(20);
cout << s.top(); // Outputs: 20
s.pop();
cout << s.top(); // Outputs: 10
```

---

## Queue
A **Queue** is a container that follows the First In, First Out (FIFO) principle.

### Features
- **push()**: Adds an element to the back of the queue.
- **pop()**: Removes the front element from the queue.
- **front()**: Accesses the front element.
- **back()**: Accesses the last element.
- **empty()**: Checks if the queue is empty.

#### Example
```cpp
queue<int> q;
q.push(10);
q.push(20);
cout << q.front(); // Outputs: 10
q.pop();
cout << q.front(); // Outputs: 20
```

---

## Priority Queue
A **Priority Queue** is a specialized container that provides sorted access to its elements. By default, it implements a max heap.

### Types
1. **Max Heap** (default): The largest element is at the top.
   ```cpp
   priority_queue<int> pq;
   pq.push(10);
   pq.push(20);
   cout << pq.top(); // Outputs: 20
   ```

2. **Min Heap**: The smallest element is at the top.
   ```cpp
   priority_queue<int, vector<int>, greater<int>> pq;
   pq.push(10);
   pq.push(20);
   cout << pq.top(); // Outputs: 10
   ```

---

## Set
A **Set** is a container that stores unique elements in a sorted order.

### Features
- **Unique Elements**: Does not allow duplicate values.
- **Sorted Order**: Elements are stored in ascending order by default.
- **Operations**:
  - **insert()**: Adds elements to the set.
  - **erase()**: Removes elements from the set.
  - **find()**: Searches for an element. Returns `s.end()` if not found.
  - **count()**: Returns 1 if the element exists, otherwise 0.
  - **empty()**: Checks if the set is empty.

#### Example
```cpp
set<int> s;
s.insert(10);
s.insert(20);
s.insert(10); // Duplicate, will not be added
cout << s.size(); // Outputs: 2
s.erase(10);
cout << s.size(); // Outputs: 1

// Check if an element exists
if (s.find(30) == s.end()) {
    cout << "Element not found" << endl; // Outputs: Element not found
} else {
    cout << "Element found" << endl;
}
```

---

## Multiset
A **Multiset** is a container that allows duplicate elements and stores them in sorted order.

### Features
- **Duplicates**: Allows multiple instances of the same value.
- **Sorted Order**: Stores elements in ascending order by default.
- **Operations**:
  - **insert()**: Adds an element to the multiset.
  - **erase()**: Removes all instances or a specific instance of an element.
  - **count()**: Returns the number of instances of an element.
  - **find()**: Searches for an element.

#### Example
```cpp
multiset<int> ms;
ms.insert(10);
ms.insert(20);
ms.insert(10); // Allows duplicates
cout << ms.count(10); // Outputs: 2
ms.erase(10); // Removes all instances of 10
cout << ms.count(10); // Outputs: 0
```

---

## Unordered Set
An **Unordered Set** is a container that stores unique elements in no particular order.

### Features
- **Unique Elements**: Does not allow duplicate values.
- **Unordered**: Elements are not stored in a specific order.
- **Operations**:
  - **insert()**: Adds elements to the set.
  - **erase()**: Removes elements from the set.
  - **find()**: Searches for an element.
  - **count()**: Returns 1 if the element exists, otherwise 0.
  - **empty()**: Checks if the set is empty.

#### Example
```cpp
unordered_set<int> us;
us.insert(10);
us.insert(20);
us.insert(10); // Duplicate, will not be added
cout << us.size(); // Outputs


```
## Summary Table
| Container         | Features                                                                 |
|-------------------|-------------------------------------------------------------------------|
| **Pair**          | Stores multiple values together; supports various data types.          |
| **Vector**        | Dynamic size; supports `push_back`, `emplace_back`, and iterators.      |
| **List**          | Ordered, dynamic, efficient for front insertions, supports duplicates. |
| **Stack**         | LIFO structure; supports `push`, `pop`, and `top`.                     |
| **Queue**         | FIFO structure; supports `push`, `pop`, `front`, and `back`.           |
| **Priority Queue**| Sorted access; supports max heap and min heap.                         |
| **Set**           | Stores unique elements in sorted order; supports various operations.   |

---



# C++ Containers: `map`, `multimap`, `unordered_map`

This README provides an overview of the `map`, `multimap`, and `unordered_map` containers in C++, with explanations, key methods, examples, and their time complexities.

## Table of Contents
1. [map](#map)
2. [multimap](#multimap)
3. [unordered_map](#unordered_map)

---


## `map`

A `map` is an associative container that stores key-value pairs, where each key is unique.

### Important Methods

- **insert(key, value)**: Adds a new key-value pair.  
  *Time Complexity*: O(log n)
  
- **find(key)**: Searches for a key and returns an iterator to the key-value pair if found.  
  *Time Complexity*: O(log n)
  
- **erase(key)**: Removes the element with the specified key.  
  *Time Complexity*: O(log n)
  
- **operator[]**: Accesses the value associated with a key. If the key does not exist, a new pair is inserted.  
  *Time Complexity*: O(log n)



### Example
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> m;
    m[1] = "One";
    m[2] = "Two";
    m.insert({3, "Three"});
    
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}


```

# Time Complexity Summary
##  Insertion, deletion, and search: O(log n)
- **multimap**
- A multimap is similar to a map, but allows multiple elements with the same key.

## Important Methods
- insert(key, value): Adds a key-value pair.
**Time Complexity: O(log n)**

- find(key): Finds the first element with the given key.
**Time Complexity: O(log n)**

- erase(key): Removes elements with the specified key.
**Time Complexity: O(log n)**



## Example
```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm;
    mm.insert({1, "One"});
    mm.insert({1, "Uno"});
    mm.insert({2, "Two"});

    for (const auto& pair : mm) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}


```
## Time Complexity Summary
**Insertion, deletion, and search: O(log n)**



## unordered_map
- An unordered_map is an associative container that stores key-value pairs, where the keys are hashed. It does not guarantee the order of elements.

## Important Methods

- **insert(key, value)**: Adds a new key-value pair.
  - **Time Complexity**: O(1) on average, O(n) in worst case.

- **find(key)**: Searches for a key.
  - **Time Complexity**: O(1) on average, O(n) in worst case.

- **erase(key)**: Removes the element with the specified key.
  - **Time Complexity**: O(1) on average, O(n) in worst case.

- **operator[]**: Accesses the value associated with a key. If the key does not exist, a new pair is inserted.
  - **Time Complexity**: O(1) on average, O(n) in worst case.


## Example
``` cpp

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> um;
    um[1] = "One";
    um[2] = "Two";
    um.insert({3, "Three"});
    
    for (const auto& pair : um) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

```
# Time Complexity Summary

| Container        | Key Uniqueness   | Insertion Time Complexity         | Deletion Time Complexity          | Search Time Complexity            |
|------------------|------------------|-----------------------------------|-----------------------------------|-----------------------------------|
| `map`            | Unique           | O(log n)                          | O(log n)                          | O(log n)                          |
| `multimap`       | Allows duplicates| O(log n)                          | O(log n)                          | O(log n)                          |
| `unordered_map`  | Unique           | O(1) on average, O(n) worst case  | O(1) on average, O(n) worst case  | O(1) on average, O(n) worst case  |



