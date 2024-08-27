#include<bits/stdc++.h>
using namespace std;
const int N=103,M=1<<4;
int n,m;
vector<int>state;
vector<int>head[M];
int f[2][M][M];
int a[N];
int cnt[M];
int check(int x){
    for(int i=0;(i+2)<=m;i++){
        if((x>>i&1)&&(x>>i+1&1)&&(x>>i+2&1)){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=s.size()-1;j>=0;j--){
            if(s[j]=='H')a[i]+=1<<(s.size()-1-j);
        }
    }
    for(int i=0;i<1<<m;i++){
        if(check(i)){
            state.emplace_back(i);
            int t=0;
            for(int j=0;j<m;j++){
                if(i>>j&1)t++;
            }
            cnt[i]=t;
        }
    }
    for(auto i:state){
        for(auto j:state){
            for(auto k:state){
                if(!(i&j)&&!(i&k)&&!(j&k)){
                    head[i].emplace_back(j);
                    // head[i].emplace_back(k);
                }
            }
        }
    }
    for(int i=1;i<=n+2;i++){
        for(auto j:state){//i
            if(!(j&a[i])){
                for(auto k:head[j]){//i-1
                    if(!(k&a[i-1]))//这个很重要
                    for(auto p:head[j]){//i-2
                        if(!(k&p))
                        f[i&1][j][k]=max(f[i&1][j][k],f[(i-1)&1][k][p]+cnt[j]);
                    }
                }
            }
        }
    }
    cout<<f[(n+2)&1][0][0];
    return 0;
}