#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
sturct Node{
    int l,r;
    int lazy;
}tr[4*N];
string s;
int a[N];
void build(int t,int l,int r){
    if(l==r){tr[t]={l,r,a[l],0};}
}
void up(){

}
void down(){

}
void modify(int l,int r,int x){

}
void query(){

}
void solve(){
    
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}