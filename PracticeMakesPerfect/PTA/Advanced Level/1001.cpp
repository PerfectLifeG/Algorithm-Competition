#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int s=a+b;
    if(s==0){cout<<0;return 0;}
    vector<int>v;
    while(s){
        v.push_back(s%1000);
        s/=1000;
    }
    cout<<*(v.end()-1);
    auto it=v.end()-2;
    for(;it!=v.begin()-1;it--){
        printf(",%03d",abs(*it));
    }
    return 0;
}