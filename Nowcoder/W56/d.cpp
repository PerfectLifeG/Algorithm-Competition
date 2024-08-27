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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    int idx=n-1;
    for(int i=1;i<=n-2;i++){
        int sum=a[idx]+a[idx-1];
        // int p=lower_bound(a.begin(),a.begin()+n-i,a[idx]-a[idx-1]);
        if(a[idx]<a[idx-1]+a[idx-2]){
            cout<<a[idx]+a[idx-1]+a[idx-2]<<endl;
            return;
        }
        idx--;
    }
    cout<<-1<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}