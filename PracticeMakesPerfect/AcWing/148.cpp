#include<bits/stdc++.h>
using namespace std;
const int N=100010;
priority_queue<int,vector<int>,greater<int>>p;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        p.push(a);
    }
    int s=0;
    while(p.size()>1){
        int a=p.top();
        p.pop();
        int b=p.top();
        p.pop();
        s+=a+b;
        if(p.size()==0)break;
        p.push(a+b);
    }
    cout<<s;
    return 0;
}