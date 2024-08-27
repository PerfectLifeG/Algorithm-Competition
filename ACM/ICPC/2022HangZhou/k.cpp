#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1000010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int son[N][26],cnt[N*26],idx=1;
int ans[26][26];
int ret1;
void insert(){
    string s;cin>>s;
    int t=0;
    for(int i=0;i<s.size();i++){
        int j=s[i]-'a';
        for(int k=0;k<26;k++){
            if(k==j)continue;
            ans[k][j]+=cnt[son[t][k]];
        }
        if(!son[t][j])son[t][j]=idx++;
        t=son[t][j];
        cnt[t]++;
    }
    for(int i=0;i<26;i++)ret1+=cnt[son[t][i]];
}
void solve(){
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        insert();
    }
    while(q--){
        string s;cin>>s;
        vector<int>mp(26);
        for(int i=0;i<26;i++)mp[s[i]-'a']=i;
        int ret=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(mp[i]>mp[j]){
                    ret+=ans[i][j];
                }
            }
        }
        cout<<ret+ret1<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}