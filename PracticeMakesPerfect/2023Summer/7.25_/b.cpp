#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
int b[N];
void solve()
{
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]&1)b[i]=1;
        else b[i]=2;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        // cout<<b[i]<<' ';
        if(a[i]%2==0&&b[i]==1){
            no;
            return;
        }
        if(a[i]%2!=0&&b[i]==2){
            no;
            return;
        }
    }
    // cout<<endl;
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}