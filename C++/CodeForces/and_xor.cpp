#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases
    

    while (t--) {
        int a, b;
        long long x, y;
        cin >> a >> b >> x >> y;

        int costA = 0 ;
        int costB = 0 ; 
        int minC = 0 ;

        while (a!=b){
        if(a<b & x<y){
            int diff = b-a ;
            while(diff){
                 a+=1;
                costA +=x;
            }

        }

        else{
            if(a %2==0){
                a= a^1;
                costB +=y ; 
            }
            else{
                a +=1 ;
                costA +=x;
            }
        }

       minC = min(minC , costA+costB) 
    }

    
    

        


        if (a == b) {
            cout << 0 << endl;
        }
        else if (a > b) {
            // You can't reduce a with +1 or ⊕1 in most cases
            if ((a ^ 1) == b) {
                cout << y << endl;  // Only possible if XOR helps
            } else {
                cout << -1 << endl;
            }
        }
        else {
            // a < b — Try best way to reach b
            // One way: just do (b - a) * x
            long long min_cost = (b - a) * x;

            // Try combining XOR + +1 steps (if it helps)
            // Try XOR first, then calculate cost if it gets closer
            int xor_a = a ^ 1;
            if (xor_a <= b) {
                long long combo_cost = y + (b - xor_a) * x;
                min_cost = min(min_cost, combo_cost);
            }

            cout << min_cost << endl;
        }
    }

    return 0;
}
