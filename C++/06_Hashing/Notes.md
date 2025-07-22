# Hashing: Pre-storing and Fetching

Hashing is a fast way to store and retrieve data using keys. This guide explains the basics of hashing, including how to handle numbers and characters, and when to use different types of data structures like arrays, maps, or unordered maps.

---

## Number Hashing

### What is Number Hashing?
- It’s a way to store numeric data in an array or table for quick access.

### Key Points:
1. **Hash Size:**
   - Inside `main` function: Maximum size is \(10^6\).
   - Globally: Maximum size is \(10^7\) (because global memory is larger than local memory).

2. **Why Use Number Hashing?**
   - To count how many times a number appears.
   - For quick lookups when speed is important.

3. **Tips for Usage:**
   - Use **global variables** for large hash tables to prevent stack overflow.
   - Hash indices automatically convert to integer values (e.g., characters get converted to their ASCII values).

---

## Character Hashing

### What is Character Hashing?
- Character hashing stores the frequency of characters using an array.

### Key Points:
- Use an **array of size 256** to cover all ASCII characters.
- Example: `hash[s[i]]++` automatically converts the character `s[i]` into its ASCII value and updates the count.
- For larger sizes (beyond array limits), use **STL containers** like `map` or `unordered_map`.

---

## Arrays vs Maps in Hashing

### Arrays
- To access a specific element (e.g., 12th element), the array must have at least 12 elements.
- Arrays are simple but consume more memory if the size is too large.

### Maps
- **Map** stores only the elements you need in a key-value pair format. 
- **Benefits of Maps:**
  - Saves memory by storing only required elements.
  - Allows complex keys (e.g., `pair<int, int>`).
  - Complexity: \(O(\log N)\) for both storing and fetching.

### Unordered Maps
- Faster than maps in most cases because they use a hash table.
- Complexity:
  - Best/Average Case: \(O(1)\)
  - Worst Case: \(O(N)\) (due to rare collisions).
- Use unordered maps unless frequent collisions cause performance issues, then switch to maps.

---

## Hashing Techniques

### Division Method
- This is a common way to calculate hash indices using:
  \[
  \text{index} = n \% \text{size}
  \]
- If a **collision** occurs (when multiple elements are hashed to the same index), it uses techniques like **linear chaining** to resolve it.

### What are Collisions?
- When multiple keys are assigned to the same hash space.
- This increases retrieval time, but modern algorithms minimize the impact.

---

## Important Notes

1. **Array Limitations:**
   - Arrays require predefined sizes. For example, accessing the 12th element needs an array of size 12.
   - Maps store only the elements you need, saving memory.

2. **Key Types in Maps:**
   - In `map`: Keys can be of any data type (e.g., `pair<int, int>`).
   - In `unordered_map`: Keys must be simple data types like `int` or `string`.

3. **Performance Recommendations:**
   - Use `unordered_map` for most cases due to its faster average-case performance.
   - Switch to `map` if collisions lead to TLE (Time Limit Exceeded).

---

## Summary

Hashing is an essential tool for efficiently storing and retrieving data. Choose arrays, maps, or unordered maps depending on the size and complexity of your data:
- Use arrays for simple and small data sizes.
- Use maps for memory-efficient storage with complex keys.
- Use unordered maps for the fastest average-case performance.
