#include <bits/stdc++.h>
using namespace std;

int main()

{

int rows = 6; 

// Upper half  
for(int i  = 1 ; i<=rows ; i++){

    for(int j = 1; j<=rows- i ; j++){
 cout<<" ";
    }
for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    




// Bottom half of the diamond
    for (int i = rows - 1; i >= 1; i--) {
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}