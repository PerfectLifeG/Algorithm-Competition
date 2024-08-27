#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    int cnt=0;int aa=0,bb=0,cc=0;
    vector<int>v;
    v.push_back(0);v.push_back(2);v.push_back(2);
    if(v[2]==0)v.erase(v.begin()+2,v.begin()+3);
        if(v[1]==0)v.erase(v.begin()+1,v.begin()+2);
        if(v[0]==0)v.erase(v.begin(),v.begin()+1);
    sort(v.begin(),v.end());
    while(!v.empty()){
            if(v[0]==0)v.erase(v.begin(),v.begin()+1);
            if(v.)
            sort(v.begin(),v.end());
            v[0]--;
            if(v.size()==2)v[1]--;
            if(v.size()==3)v[2]--;
            cnt++;
        }
        cout<<cnt;
    return 0;
}