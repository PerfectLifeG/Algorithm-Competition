#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct Range{
    int l,r;
    bool operator<(const Range &a)const 
    {
        return l<a.l;
    }
}range[N];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>range[i].l>>range[i].r;
    }
    sort(range,range+n);
    priority_queue<int,vector<int>,greater<int>>p;
    for(int i=0;i<n;i++){
        auto r=range[i];
        if(p.empty()||p.top()>=r.l)p.push(r.r);
        else{
            p.pop();
            p.push(r.r);
        }
    }
    printf("%d\n",p.size());
    return 0;
}