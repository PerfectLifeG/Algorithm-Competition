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
    vector<int>a(100);
    int t=0;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        a[b]++;
        if(b&1)t++;
    }

    for(int i=1;i<=10;i++){
        if(a[i*k]){
            cout<<0<<endl;
            return;
        }
    }
    int mn=1e18;
    for(int j=1;j<=10;j++){
        if(a[j])
        for(int i=1;i<=10;i++){
            if(i*k-j>=0)
            mn=min(mn,i*k-j);
        }
    }
    if(k==4){
        if(n-t>=2){
            cout<<0<<endl;
            return;
        }else if(n-t==1){
            if(t){
                cout<<min(mn,1ll)<<endl;
            }else
            cout<<mn<<endl;
        }else {
            if(t>=2)cout<<min(mn,2ll)<<endl;
            else cout<<mn<<endl;
        }
        return;
    }
    cout<<mn<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}