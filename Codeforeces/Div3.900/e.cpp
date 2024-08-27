#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int p;
int ans[N][31];
int check(int mid){
    int t=0;
    for(int i=0;i<30;i++){
        if(ans[p][i]>=mid){
            t+=(1<<i);
        }
    }
    // cout<<mid<<' '<<t<<endl;
    return t;
}
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=30;j++)
            ans[i][j]=-1;
    }
    for(int i=0;i<30;i++){
        for(int j=n-1;j>=0;){
            int t=(a[j]>>i)&1;
            if(!t){j--;continue;}
            ans[j][i]=j;
            // cout<<j<<' '<<i<<endl;
            int k=j-1;
            while(k>=0&&(a[k]>>i)&1){
                ans[k][i]=j;
                k--;
            }
            j=k;
        }
    }
    // for(int i=0;i<30;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<j<<' '<<i<<' '<<ans[j][i]<<endl;
    // }
    int q;cin>>q;
    while(q--){
        int k;cin>>p>>k;
        p--;
        int l=p,r=n;
        while(l+1!=r){
            int mid=l+r>>1;
            if(check(mid)<k){
                r=mid;
            }else l=mid;
        }
        if(check(l)>=k)cout<<l+1<<' ';
        else cout<<-1<<' ';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}