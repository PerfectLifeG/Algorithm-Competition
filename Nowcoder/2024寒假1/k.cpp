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
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>nx(n+1);
    string s[n+1];
    for(int i=1;i<=n;i++){
        cin>>nx[i]>>s[i];
    }
    vector<int>book(n+1);
    vector<int>v(n+1);
    int ans=1;
    for(int i=1;i<=n;i++){
        int j=i;
        while(!book[j]){book[j]=i;j=nx[j];}
        if(book[j]==i){
            int root=j;
            int cnt=0;
            for(int k=0;k<5;k++){
                v[root]=k;
                int t=s[root][k]-'A';
                j=nx[root];
                while(j!=root){
                    t=s[j][t]-'A';
                    j=nx[j];
                }
                if(t==k)cnt++;
            }
            ans=ans*cnt%mod;
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