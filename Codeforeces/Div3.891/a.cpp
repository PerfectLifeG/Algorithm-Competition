#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>a(n);
    int ji=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]&1)ji++;
    }
    if(ji==2&&n>ji||ji%2==0)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}