#include <iostream>
using namespace std;
int main()
{
    int arr[20];
    int n;

    cout << "Enter the range:\n";
    cin >> n;
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "the elements are:";
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }

    // for (int i = 0; i < n-1; i++)
    // {
    //     for (int j = 0; j < n-1-i; j++)
    //     {
    //         if (arr[j] > arr[j + 1])
    //         {
    //             int temp = arr[j];
    //             arr[j] = arr[j + 1];
    //             arr[j + 1] = temp;
    //         }
    //     }
    // }

    cout << "The reverse elements are:";
    for (int i = n; i >= 0; i--)
    {
        cout << " " << arr[i];
    }

    return 0;
}