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
    int n,k;cin>>n>>k;
    vector<int>v(n);
    int mx=n;
    int mn=1;
    int f=-1;
    for(int i=0;i<k;i++){
        int j=i;
        while(j<n){
            if(f==1){
                v[j]=mn;j+=k;
                mn++;
            }else{
                v[j]=mx;j+=k;
                mx--;
            }
        }
        f=-f;
    }
    for(auto i:v)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}