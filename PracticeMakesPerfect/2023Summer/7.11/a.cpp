#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)a[i]=0;
    a[n/2]=1;
    if(!a[0])a[0]=2;
    int j=n;
    for(int i=0;i<n;i++){
        if(!a[i]){a[i]=j;j--;}
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}