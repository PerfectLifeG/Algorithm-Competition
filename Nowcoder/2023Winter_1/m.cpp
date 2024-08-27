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
const int N=500;
const int mod=998244353;
const int INF=0x3f3f3f3f;
double f[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            for(int k=1;k<=j;k++){
                f[j]=max(f[j],f[j-k]+1.0*k/(m-j+k));//前i个人，使用了j个仙贝，第i个人使用了k个仙贝
            }
        }
    }
    cout<<fixed<<setprecision(6)<<f[m]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}