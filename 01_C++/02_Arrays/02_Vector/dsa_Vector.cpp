#include <bits/stdc++.h>
using namespace std;

int main()
{

    // 1. initialize
    vector<int> v;




    // 2.inserting elements from the last
    // push_back()  is take care of capacity and size 
    v.push_back(10);
    v.push_back(100);
    v.push_back(110);
    v.push_back(310);




// if we are inserting the elements like this so there is  no surety that this elements get stored in same location if space is not available then it will stored in different address location
// don't use [] for inserting elements
    v[2] = 30;
    v[4] = 30;
    v[5] = 30;




 // 3. printing the elements
    cout << v[0] << endl
         << v[1] << endl
         << v[2] << endl
         << v[3] << endl
         << v[4] << endl
         << v[5] << endl


         // index 6 is not present but still when we try to access it return us garbage value instead of showing the error
         << v[6] << endl;



//  get the size 
     cout<<v.size()<<endl;     // size -> 4


//   to access the elements by its index :
      cout<< v.at(2)<<endl; 

//this show  the error : out of bound   
       cout<< v.at(5)<<endl;   
       cout<< v.at(6)<<endl;  



// printing all the elements
        for (int i = 0 ;  i  < v.size(); i++) {
        cout << v[i] << endl;
    }




// delete elements form the last 
 v.pop_back();
 cout<<v.size();  // size -3




// vector methods
    for(int i =0 ; i< 10 ; i++){
   v.push_back(i+1);
   cout<<v[i]<<endl;
   cout<<"cap:" <<v.capacity()<<endl;    // increase  multiples of 2 
   cout<<"size:"<< v.size()<<endl;
}



    return 0;
    
}

