#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    vector<int>p(n+1);
    vector<int>id(n+1);
    for(int i=0;i<n;i++){
        cin>>p[i];
        id[p[i]]=i;
    }
    int ans=0;
    while(n>1){
        int j=n;
        while(j>=2&&id[j-1]<id[j])j--;
        n=j-1;
        if(n!=0)ans++;
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