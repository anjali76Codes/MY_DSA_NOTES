// parametrized way
// #include <bits/stdc++.h>
// using namespace std;

// int sum_of_nums(int i, int sum)
// {

//     if (i < 1)
//     {
//         cout << sum;
//         return 0;
//     }

//     sum_of_nums(i - 1, sum + i);
// }

// int main()
// {

//     int n;
//     cin >> n;
//     sum_of_nums(n, 0);

//     return 0;
// }



// functional way 
#include<bits/stdc++.h>
using namespace std;

int sum_of_firstN(int n ){
    if(n== 0){
        return 0;
    }
    return n+sum_of_firstN(n-1);
}


int main()
{

int n ;
cin>>n;
int total = sum_of_firstN(n);
cout<<total;


return 0;
}