#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int b;
int check(int a){
    if(a%3!=0){
        return 0;
    }
    if(a/3==b||a/3*2==b){
        return 1;
    }
    if(check(a/3))return 1;
    if(check(a/3*2))return 1;
    return 0;
}
void solve(){
    int a;cin>>a>>b;
    if(a==b){
        yes;
        return;
    }
    if(check(a)){
        yes;
    }else no;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}