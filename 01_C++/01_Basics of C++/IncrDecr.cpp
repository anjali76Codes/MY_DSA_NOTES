#include <iostream>
using namespace std;
int main(){
//     int a = 10;
//    int b= a++;
//     cout<<b<<endl;
// b= ++a;
// cout<<a<<endl;
int a= 1;
int b=1;
int c = a|| --b;
int d = a-- && --b;
cout<<a<<b<<c<<d<<endl;
    return 0;
}

