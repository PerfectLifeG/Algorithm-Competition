#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n;cin>>n;
    int a=-1;
    int mn=-1,mx;
    for(int i=1;i<n;i++){
        if(i%3==0||(n-i)%3==0){
            mn=i;
            mx=n-i;
            break;
        }
    }
    if(mn==-1){
        cout<<0;
        return;
    }
    while(mn%3!=0){
        mn++;
    }
    while(mx%3!=0){
        mx--;
    }
    // cout<<mn<<' '<<mx<<endl;
    if(n/2%3==0&&n/2+n/2==n)
    cout<<((mx-mn)/3+1)*2-1<<endl;
    else cout<<((mx-mn)/3+1)*2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}