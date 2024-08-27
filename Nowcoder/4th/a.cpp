#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int nx[N];
int m;
int kmp(string &p){
    // cout<<p<<endl;
    for(int i=2,j=0;i<=p.size()-1;i++){
        while(j && p[i]!=p[j+1])j=nx[j];
        if(p[i]==p[j+1])j++;
        nx[i]=j;
    }
    if(nx[p.size()-1]>m)return 0;
    else return 1;
}
void solve()
{
    int n;cin>>n;
    string p;cin>>p;
    m=p.size();
    p=' '+p;
    int i=m+1;
    for(;i<m+1+n;i++){
        p+='1';
    }
    for(;i<n+m+1+m;i++){
        p+=p[i-(m+n)];
    }
    if(kmp(p)){
        cout<<string(n,'1')<<endl;
        return;
    }
    for(int i=m+1;i<m+1+n;i++){
        p[i]='0';
    }
    if(kmp(p)){
        cout<<string(n,'0')<<endl;
        return;
    }
    cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}