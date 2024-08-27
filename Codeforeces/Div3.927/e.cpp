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
    string s;cin>>s;
    int i=0;
    while(i<s.size()&&s[i]=='0')i++;
    s=s.substr(i);
    n=s.size();
    int c=0;
    vector<int>pre(n);
    pre[0]=s[0]-'0';
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+(s[i]-'0');
    }
    for(int i=n-1;i>=0;i--){
        int t=pre[i]+c;
        s[i]='0'+t%10;c=t/10;
    }
    if(c)cout<<c<<s<<endl;
    else cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}