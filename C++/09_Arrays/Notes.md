# Basics of array 
- array have maximum size locally - 10^6
- array have maximum size globally - 10^7
- when we initialize the array inside the main function somehow it has garbage value that we can't determined so better is to create array globally because globally when we create it assign 0 element at each location and after getting the input it replace this value 





Brute method - normal solution 
better 
optimal solution 

first we have to tell the brute and come to the optimal way 
1. Largest element :
 brute :
    - first sort the array then n-1 (last element ) is a largest ele.
    - time complexity : O(n log n)
optimal :
    -Assign largest initially - arr[0]
    -iterate from 0 to n 
    -check condition(if(arr[i]>largest))  largest = arr[i]
    - print largest
    - time complexity : O(n)
    - space complexity : O(1)


2.Second Largest :
brute :
    - first sort the array then n-2 (second last element ) is a second largest ele. but if it is satisfied this condition (if(arr[i] !=largest)).
    - time complexity : O(n log n)
    optimal :
    complexity : O(n)


3.Check sorted or not 
time complexity : O(n)


4. Remove duplicates 
brute: 
time complexity : nlogn+n
space complexity : O(n)


optimal :
time complexity : O(n)
space complexity : O(1)



5. Left rotate by one place 
time complexity : O(n)
space complexity : O(n) (due to using array for this algorithm) and extra space O(1)


6. left rotate by D place 
brute :
time complexity : O(n+d)
space complexity : O(n) (due to using array for this algorithm) and extra space O(d)

optimal :
here instead of doing shifting and storing back into the array we are reversing the array here 
reverse(a , a+d)   - O(d)
reverse(a+d , a+n)  - O(n-d)
reverse(a , a+n)   - O(n)
time complexity : O(2n)
space complexity : O(1)


7. Moves all Zeros at the end



