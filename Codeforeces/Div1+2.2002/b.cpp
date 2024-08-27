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
    vector<int>b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int l1=0,r1=n-1;
    int l2=0,r2=n-1;
    for(int i=0;i<n;i++){
        if(a[i]!=b[l2]&&a[i]!=b[r2]){
            cout<<"Alice\n";
            return;
        }
        if(a[i]==b[l2])l2++;
        if(a[i]==b[r2])r2--;
    }
    l2=0,r2=n-1;
    for(int i=n-1;i>=0;i--){
        if(a[i]!=b[l2]&&a[i]!=b[r2]){
            cout<<"Alice\n";
            return;
        }
        if(a[i]==b[l2])l2++;
        if(a[i]==b[r2])r2--;
    }
    cout<<"Bob\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}