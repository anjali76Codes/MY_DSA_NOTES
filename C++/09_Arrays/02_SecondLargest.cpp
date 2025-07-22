/*
// Second largest element in the array without sorting

1. Brute force
- sort the array and check the n-2 index
- cannot directly tell that it is second largest as there can be same elements as well so it will become the largest
- so when we have n-2 index check if it is same as the previous index
- if yes then compare with the next index
- so the loop will go from n-2 to 0 and if arr[i] != largest then we can say that arr[i] is the second largest
- Here the complexity will be O(Nlog2N)

2. Better Approach
- find the largest element as we have done previously
- then after that add a for loop and consider max_element as -1
- then compare if (arr[i] > max_element && arr[i] != largest)
- if yes then update max_element with arr[i]
- so with this we will get the second largest element
- so the time complexity will be O(2N)


3. Optimal Approach
- we will consider the largest as a[0] and the second_largest as -1
- now if the element is larger than largest then second_largest = largest and largest = element
- but if the element is smaller than largest but it is greater than second_largest then second_largest = element
- so the time complexity will be O(N) as we are doing just one pass

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // // largest - O(n)
    //     int largest = arr[0];
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] > largest)
    //         {
    //             largest = arr[i];
    //         }
    //     }

    //     cout << largest;
    //     cout << endl;

    // // second largest - O(n)
    //     int slargest = -1;

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (arr[i] != largest && arr[i] > slargest)
    //         {
    //             slargest = arr[i];
    //         }
    //     }

    //     cout << slargest;

    // optimal solution - O(n)
    int largest = arr[0];
    int secondLargest = -1;

    // for(int i = 1 ; i<n ; i++){
    //     if(arr[i]>secondLargest && arr[i] !=largest ){
    //     secondLargest = largest ;
    //     largest = arr[i];
    //     }

    // }

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }


cout << secondLargest << endl;
return 0;
}
