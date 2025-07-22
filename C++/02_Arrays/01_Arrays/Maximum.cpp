#include <iostream>
using namespace std;
int main() {
    int arr[] = {5, 10, 3, 8, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];
    int smax = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            smax = max;
            max = arr[i];
        }
        else if (arr[i] > smax && arr[i] < max) {
            smax = arr[i];
        }
    }

    cout << "Maximum element in the array is: " << max << std::endl;
    cout << "Second largest element is: " << smax << std::endl;

    return 0;
    
}




