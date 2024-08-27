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
int n;
string a,b;
string ans;
void dfs(int t1,int t2,string s){
    if(s.size()+n-max(t1,t2)-1<ans.size())return;
    if(s.size()+n-max(t1,t2)-1==ans.size()&&s>ans.substr(0,s.size()))return;
    if(s.size()>=ans.size()){
        ans=s;
    }
    if(t1+1==n||t2+1==n)return;
    if(a[t1+1]=='?'&&b[t2+1]=='?'){
        dfs(t1+1,t2+1,s+'a');
    }
    else if(a[t1+1]=='?'){
        dfs(t1+1,t2+1,s+b[t2+1]);
    }
    else if(b[t2+1]=='?'){
        dfs(t1+1,t2+1,s+a[t1+1]);
    }else if(a[t1+1]==b[t2+1])
        dfs(t1+1,t2+1,s+a[t1+1]);
}
void solve(){
    cin>>a>>b;
    n=a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string t="";
            if(a[i]=='?'&&b[j]=='?'){
                dfs(i,j,t+'a');
            }
            else if(a[i]=='?'){
                dfs(i,j,t+b[j]);
            }
            else if(b[j]=='?'){
                dfs(i,j,t+a[i]);
            }
            else if(a[i]==b[j]){
                dfs(i,j,t+a[i]);
            }
        }
    }
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}