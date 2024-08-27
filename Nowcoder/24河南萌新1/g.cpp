#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin()+1,x.end()-1
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
    int n,m,k;cin>>n>>m>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    // if(n>2)sort(all(a));
    // for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;

    int ans=0;
    if(m>a[0]){
        int mm=m,kk=k;
        mm-=a[0];
        int t=1;
        for(int i=1;i<n;i++){
            if(mm>a[i]){
                mm-=a[i];
                t++;
            }else if(kk){
                t++;
                kk--;
            }else break;
        }
        ans=max(ans,t);
    }
    if(k){
        int mm=m,kk=k-1;
        int t=1;
        for(int i=1;i<n;i++){
            if(mm>a[i]){
                mm-=a[i];
                t++;
            }else if(kk){
                t++;
                kk--;
            }else break;
        }
        ans=max(ans,t);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}