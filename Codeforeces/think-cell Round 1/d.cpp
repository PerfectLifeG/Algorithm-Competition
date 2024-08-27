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
    string s;cin>>s;s=' '+s;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            vector<int>one(n+2);
            int sum=0;
            for(int k=i;k<=j;k++){
                if(s[k]=='0')continue;
                if(one[k-1]||one[k]||one[k+1]){
                    continue;
                }else {one[k+1]=1;sum++;}
            }
            ans+=sum;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}