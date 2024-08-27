#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
unordered_map<char,int>mp;
int nx[N*2][26];
int val[N*2],idx=1;
void solve(){
    int n;cin>>n>>mod;
    for(int i=0;i<26;i++){
        int t;cin>>t;
        mp['a'+i]=t;
    }
    auto insert=[&](string s){
        int t=0;
        for(int i=0;i<s.size();i++){
            int j=s[i]-'a';
            if(!nx[t][j])nx[t][j]=idx++;
            t=nx[t][j];
            val[t]++;
        }
    };
    string p;
    auto query=[&](int x){
        int t=0;
        int v=1;
        int res=0;
        for(int i=0;i<p.size();i++){
            int j=p[i]-'a';
            if(nx[t][j]){
                t=nx[t][j];
                v*=mp[p[i]];v%=mod;
                if(v>x){
                    res+=val[t];
                }
            }else break;
        }
        return res;
    };
    vector<string>v;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        v.push_back(s);
        insert(s);
    }
    for(int i=0;i<n;i++){
        int x=1;
        for(auto j:v[i]){
            x*=mp[j];
            x%=mod;
        }
        p=v[i];
        cout<<query(x)<<' ';
    }
}
signed main(){
    // //
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}