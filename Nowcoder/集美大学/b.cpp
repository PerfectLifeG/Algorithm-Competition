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

vector<char>v;
string s[5];
int a[5],b[5];
int book[20];
set<string>st;
unordered_map<char,int>mp2;
void dfs(int t,int cnt,string p){
    if(cnt==3){
        for(int i=0;i<5;i++){
            int c=0,d=0;
            for(int j=0;j<3;j++){
                if(mp2[s[i][j]]){
                    c++;
                }
                if(s[i][j]==p[j]){
                    d++;
                }
            }
            if(c!=a[i]||d!=b[i])return;
        }
        st.insert(p);
        return;
    }
    if(t==v.size()){
        return;
    }
    for(int i=0;i<v.size();i++){
        if(book[i])continue;
        book[i]=1;
        mp2[v[i]]=1;
        dfs(t+1,cnt+1,p+v[i]);
        mp2[v[i]]=0;
        book[i]=0;
    }
}
void solve(){
    unordered_map<char,int>mp;
    for(int i=0;i<5;i++)cin>>s[i]>>a[i]>>b[i];
    for(int i=0;i<5;i++){
        for(auto j:s[i]){
            if(!mp.count(j)){
                v.push_back(j);
                mp[j]++;
            }
        }
    }
    dfs(0);
    cout<<st.size()<<endl;
    for(auto i:st)cout<<i<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}