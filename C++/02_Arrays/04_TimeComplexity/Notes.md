1.  
n = 10 
for(int i = 0 ; i< n ; i++){
    // print statement
}


In above loop --> no. of operations is 10 times 
complexity : O(n)



2.
n = 10
for(int i = 0 ; i< n ; i+=2){
    // print statement
}


In above loop --> no. of operations is 5 times 
complexity : O(n)


Note : 
1. no. of operations -> k.n  then complexity => O(n) neglect k
2. no. of operations -> k+n  then complexity => O(n) neglect k
3. no. of operations -> 5n3 + n2  then complexity => O(n3) neglect lower degree




3.
for(int i =  0 ; i<n ; i++){
    for(int  j = 0 ; j< m ; j++){
  // code 
    }
}


Time Complexity : O(n*m) 
## In any nested loop if i and j are independent of each other then complexity is O(n*m)


4.
for (int i = 0 ; i<n ; i++){
    i--  // infinite loop
}

if infinite loop exist then show an error TLE -> Time limit exceeded.




5.
for(int i =1 ; i<n ; i*=k){
// code 
}

explanation : 
let  k = 2 , n = 100
then value is incremented like this:
   1, 2 , 4, 8, 16, 32, 64 
   only 7 times total no. of operations

 we can write this :
 1, 2, 2^2 , 2^3 , 2^4 ........2^x  here x is depends on the n 

 so here total no. of operations :
 1+x

 let 2^x <=n
 2^x = n 
 x log2 = logn

 x = log2n

 complexity : 
 O(logn)

  


  ## Space Complexity :

Auxillary space --> extra space used 

during variable -> negligible space occupy
arrays , vector --> then extra spaces are created


1.
int arr[n]
for(int i = 0 ; i<n ; i++)
{
    // code 
}


space Complexity : O(n)


2.
int a = 10;
for(int i = 0 ; i<n ; i++)
{
    // code 
}


space Complexity : O(1)



3.
int arr[n];
int a = 10;
for(int i = 0 ; i<n ; i++)
{
    // code 
}


space Complexity : O(n)



4.
vector<int> a;
vector<int> b
for(int i = 0 ; i<n ; i++)
{
    for(int j = 0 ; j< m ; j++){

    a.push_back(i)
    b.push_back(j)
    }
   
}


in above example vector is define but not define its size so it not occupy any extra spaces at initial but after running of the loop n*m times values are inserted so the overall 
space Complexity : O(n*m)



* 2D matrix having n^2 space complexity 

Examples :
1.
for(int i = 0 ; i<n ; i+=i){
//code
}

Time Complexity : O(log n)


2.

for(int i = 0 ; i<n ; i+=i){  // logn
for(int j = n ; j>=0 ; j--){  // n

//code
}

}

Time Complexity : O(n*logn)


* Imp note : 
log n^1/2 = logn
but n^1/2 != n



