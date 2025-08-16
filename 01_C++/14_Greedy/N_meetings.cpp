#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a , pair<int,int>b){
    return a.second < b.second;
}

int maxMeetings(vector<int>&start , vector<int>&end){
    // combine start and end 
    vector<pair<int,int>>t ;

for(int i = 0; i<start.size() ; i++){
    pair<int,int> p = make_pair(start[i] , end[i]);
    t.push_back(p);

}


// sort based on the finish time in incresing order 
sort(t.begin() , t.end() , cmp);


// find  max meetings can be possible
int cnt = 1;
int ansEnd = t[0].second;  // first as always be possible 

for(int i =1 ; i<start.size() ; i++){
    if(t[i].first > ansEnd){
        cnt++;
        ansEnd= t[i].second;
    }
}

return cnt;


}

int main()
{

    vector<int>start = {1,3,0,5,8,5};
    vector<int>end = {2,4,6,7,9,9};
    cout<<maxMeetings(start,end);


return 0;
}