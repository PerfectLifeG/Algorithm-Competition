#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve()
{
    int n;cin>>n;
    string ans="";
    char j='a';
    int t;
    for(int i=2;i<n;i++){
        if(n%i!=0){
            t=i;break;
        }
    }
    // cout<<t<<endl;
    for(int i=0;i<t;i++){
        ans+=(j+i);
    }
    for(int i=0;i<n/t;i++){
        cout<<ans;
    }
    for(int i=0;i<n%t;i++){
        cout<<char(j+i);
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