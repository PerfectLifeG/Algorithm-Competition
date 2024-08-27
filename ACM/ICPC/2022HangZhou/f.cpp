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
string p=" bie";
unordered_map<string,int>mp;
int f;
void kmp(string &s){
    if(mp.count(s)){
        return;
    }
    for(int i=1,j=0;i<s.size();i++){
        while(j && s[i]!=p[j+1])j=nx[j];
        if(s[i]==p[j+1])j++;
        if(j==p.size()-1){
            f=1;
            cout<<string(s.begin()+1,s.end())<<endl;
            mp[s]++;
            return;
        }
    }
}
void solve(){
    int n;cin>>n;
    f=0;
    for(int i=0;i<n;i++){
        string s;cin>>s;s=' '+s;
        kmp(s);
    }
    if(!f)cout<<"Time to play Genshin Impact, Teacher Rice!"<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    for(int i=2,j=0;i<p.size();i++){
        while(j && p[i]!=p[j+1])j=nx[j];
        if(p[i]==p[j+1])j++;
        nx[i]=j;
    }
    // for(int i=1;i<p.size();i++)cout<<i<<' '<<nx[i]<<endl;
    cin>>_;
    while(_--)solve();
    return 0;
}   