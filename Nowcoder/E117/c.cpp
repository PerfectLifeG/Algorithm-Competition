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
const int INF=0x3f3f3f3f;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    if(n+m*2<k){
        cout<<n+m<<endl;
        return;
    }
    if(k==1){
        cout<<m<<endl;
        return;
    }
    int t=k/2;//meizu

    int mx=m/t;//zushu
    if(k%2==0){
        if(n>=k-m%t*2){
            int ans=1e18;
            int p=n-(k-m%t*2);
            if(p%k==0){
                cout<<0<<endl;
                return;
            }
            p=p%k;
            int mx2=p/2;
            if(mx2<=m){
                ans=mx2+p%2;
            }else{
                ans=p-m*2;
            }
            int pp=n;
            int mm=mx*t;
            pp%=k;
            // cout<<pp<<' '<<m<<' '<<endl;
            mx2=pp/2;
            if(mx2<=mm){
                ans=min(ans,m-mm+mx2+pp%2);
            }else{
                ans=min(ans,m-mm+pp-mm*2);
            }
            cout<<ans<<endl;
            return;
        }else{
            int ans;
            int pp=n;
            int mm=mx*t;
            pp%=k;
            int mx2=pp/2;
            if(mx2<=mm){
                ans=m-mm+mx2+pp%2;
            }else{
                ans=m-mm+pp-mm*2;
            }
            cout<<ans<<endl;
            return; 
        }
    }
    else if(n>mx){
        if(n-mx>=k-m%t*2){
            int ans=1e18;
            int p=n-mx-(k-m%t*2);
            if(p%k==0){
                cout<<0<<endl;
                return;
            }
            p=p%k;
            int mx2=p/2;
            if(mx2<=m){
                ans=mx2+p%2;
            }else{
                ans=p-m*2;
            }
            int pp=n-mx;
            int mm=mx*t;
            pp%=k;
            // cout<<pp<<' '<<m<<' '<<endl;
            mx2=pp/2;
            if(mx2<=mm){
                ans=min(ans,m-mm+mx2+pp%2);
            }else{
                ans=min(ans,m-mm+pp-mm*2);
            }
            cout<<ans<<endl;
            return;
        }else{
            int ans;
            int pp=n-mx;
            int mm=mx*t;
            pp%=k;
            int mx2=pp/2;
            if(mx2<=mm){
                ans=m-mm+mx2+pp%2;
            }else{
                ans=m-mm+pp-mm*2;
            }
            cout<<ans<<endl;
            return; 
        }
    }else{
        // cout<<6<<endl;
        cout<<(mx-n)*t+m%t<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}