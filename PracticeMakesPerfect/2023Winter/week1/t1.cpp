#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n,m;
int tree[N];
void build(int t,int val){
    if(tree[t]==0){
        tree[t]=val;
    }else if(tree[t]>val){
        build(2*t+1,val);
    }else build(2*t+2,val);
}
int flag;
void solve(int t,int val){
    if(tree[t]>val)
        solve(2*t+1,val);
    else if(tree[t]<val)
        solve(2*t+2,val);
    else if(tree[t]!=val)
        flag=0;
}
int main(){
    while(cin>>n,n){
        cin>>m;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            build(0,a);
        }
        while(m--){
            flag=1;
            for(int i=0;i<n;i++){
                int a;cin>>a;
                if(!flag)continue;
                solve(0,a);
            }
            if(flag)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}