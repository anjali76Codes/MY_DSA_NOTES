#include <iostream>
using namespace std;
int main(){
    int score;
    cin>>score;

    // determine grade based on student marks
    if(score<=100 && score>80){
        cout<<"Grade: A"<<endl;
    }
      else if(score>50 && score <80){
        cout<<"Grade: B"<<endl;
    }
    else{
        cout<<"The result is fail:"<<endl;
    }





    cout<<"Enter the three numbers first:"<<endl;
    int a ,b,c;
    cin>>a>>b>>c;
if(a>b && a>c){
    cout<<"Greatest is:"<<a<<endl;
}
 else if(b>a && b>c){
    cout<<"Greatest is:"<<b<<endl;
}
else{
    cout<<"Greatest is:"<<c<<endl;
}
    return 0;

}