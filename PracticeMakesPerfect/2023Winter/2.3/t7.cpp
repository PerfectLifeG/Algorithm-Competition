#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int lowbit(int x){
    return x&-x;
}
int cnt1(int x){
    int cnt=0;
    while(x){
        x-=lowbit(x);
        cnt++;
    }
    return cnt;
}
int book[N];
priority_queue<int>p;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){int a;cin>>a;p.push(a);}
    int idx=1;
    while(p.top()!=1){
        auto t=p.top();p.pop();
        t=cnt1(t);
        book[idx]=p.top();
        p.push(t);
        idx++;
    }
    for(int i=0;i<q;i++){
        int a;cin>>a;
        if(a>=idx)cout<<1<<endl;
        else cout<<book[a]<<endl;
    }
    return 0;
}