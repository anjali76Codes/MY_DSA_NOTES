# Combination Sum Problems

## 1. Combination Sum

### Time Complexity: **O(2^t * k)**  
Where `t` is the target and `k` is the average length.  

**Reason**:  
- Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick, which results in `2^n` different recursion calls.  
- Additionally, assuming that the average length of every combination generated is `k` (to put length `k` data structure into another data structure).  

**Why not `2^n` but `2^t` (where `n` is the size of the array)?**  
- Assume that there is `1`, and the target you want to reach is `10`. So, 10 times you can “pick or not pick” an element.  

### Space Complexity: **O(k * x)**  
- `k` is the average length.  
- `x` is the number of combinations.  

---

## 2. Combination Sum II (No Duplicates Allowed)

### Time Complexity: **O(2^n * k)**  

**Reason**:  
- Assume if all the elements in the array are unique, then the number of subsequences you will get is `O(2^n)`.  
- We also add the `ds` to our answer when we reach the base case, which will take `k` (average space for the `ds`).  

### Space Complexity: **O(k * x)**  
**Reason**:  
- If we have `x` combinations, then the space will be `x * k` where `k` is the average length of the combination.  



3. Subset Sum 
power set that have the formula that finds all possible subsets - 2^n * n(Brute force)