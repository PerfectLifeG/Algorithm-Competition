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
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>v1[26];
    vector<int>v2[26];
    for(int i=0;i<n;i++){
        string s;cin>>s;
        v1[s[0]-'a'].push_back(s[1]-'a');
        v2[s[1]-'a'].push_back(s[0]-'a');
    }
    int ans=0;
    for(int i=0;i<26;i++){
        sort(all(v1[i]));
        sort(all(v2[i]));
        int len=1;
        for(int j=0;j<v1[i].size();){
            int k=j+1;
            while(k<v1[i].size()&&v1[i][j]==v1[i][k])k++,len++;
            // cout<<v1[i][j]<<' '<<v1[i][k]<<endl;
            if(k<v1[i].size()&&v1[i][k]==v1[i][j]+1){
                ans+=len;
                len=1;
            }
            j=k;
        }
        len=1;
        for(int j=0;j<v2[i].size();){
            int k=j+1;
            while(k<v2[i].size()&&v2[i][j]==v2[i][k])k++,len++;
            if(k<v2[i].size()&&v2[i][k]==v2[i][j]+1){
                ans+=len;
                len=1;
            }
            j=k;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}