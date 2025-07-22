#include <iostream>
using namespace std;
int main(){
    int l1 =5;
    int l2 = 10;
    cout<<"Before Swapping:"<<l1<<endl<<l2<<endl;
    int temp = l1;
    l1 = l2;
    l2 = temp;
      cout<<"After Swapping:"<<l1<<endl<<l2<<endl;
    return 0;
}