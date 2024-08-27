#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
// int nx[N];
// int kmp(string &p,string &s){
//     for(int i=2,j=0;i<=p.size()-1;i++){
//         while(j && p[i]!=p[j+1])j=nx[j];
//         if(p[i]==p[j+1])j++;
//         nx[i]=j;
//     }
//     for(int i=1,j=0;i<=s.size()-1;i++){
//         while(j && s[i]!=p[j+1])j=nx[j];
//         if(s[i]==p[j+1])j++;
//         if(j==n){
//             //匹配成功
//             return 0;
//         }
//     }
//     return 1;
// }
int n;
// void dfs(int t,string p){
//     if(t==n)return kmp();
//     if(dfs(t+1,string p)
//     if)dfs(t+1,string p)
// }
void solve()
{
    string s;cin>>s;
    n=s.size()*2;
    string p;
    for(int i=0;i<n;i+=2){
        p+="()";
    }
    string p2;
    for(int i=0;i<n/2;i++){
        p2+="(";
    }
    for(int i=0;i<n/2;i++){
        p2+=")";
    }
    if(p.find(s)==-1){yes;cout<<p<<endl;return;}
    if(p2.find(s)==-1){yes;cout<<p2<<endl;return;}
    no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}