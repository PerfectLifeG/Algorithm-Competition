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
int nx[N];
void kmp(string &p){
    p=' '+p;
    for(int i=2,j=0;i<=p.size()-1;i++){
        while(j && p[i]!=p[j+1])j=nx[j];
        if(p[i]==p[j+1])j++;
        nx[i]=j;
    }
    // for(int i=1,j=0;i<=s.size()-1;i++){
    //     while(j && s[i]!=p[j+1])j=nx[j];
    //     if(s[i]==p[j+1])j++;
    //     if(j==n){
    //         //匹配成功
    //     }
    // }
}
void solve(){
    int n;cin>>n;
    string s=' '+s;cin>>s;
    kmp(s);
    for(int i=2;i<=s.size()-1;i++){
        if(nx[i]){
            cout<<"Wrong Answer"<<endl;
            return;
        }
    }
    cout<<"Correct"<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}