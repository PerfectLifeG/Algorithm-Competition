#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int n;cin>>n;
    int mx=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
        mp[a[i]]++;
    }
    sort(a,a+n);
    if(a[0]==mx){
        cout<<-1<<endl;
        return;
    }
    cout<<(n-mp[mx])<<' '<<mp[mx]<<endl;
    int i=0;
    for(;i<n;i++){
        if(a[i]!=mx)
        cout<<a[i]<<' ';
        else break;
    }
    cout<<endl;
    for(;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}