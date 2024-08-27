#include<bits/stdc++.h>
using namespace std;
const int N=20;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int x[N];
int a[N];
int b[N];
int sa[N];
int sb[N];
inline int Log2(double x){
    if(x==1)return 0;
    return ((*(unsigned long long*)&x>>52)&1023)+1;
}
void solve(){
    int n,k;cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        a[i]=0;
        b[i]=Log2(x[i]&-x[i]);
        while(x[i]%5==0){
            x[i]/=5;
            a[i]++;
        }
        sa[i]=a[i]+sa[i-1];
        sb[i]=b[i]+sb[i-1];
    }
    int h=0;
    for(int i=1;i<=n;i++){
        if(min(sa[i]-sa[h],sb[i]-sb[h])==k){
            int t=i;
            while(i<=n&&min(sa[i]-sa[h],sb[i]-sb[h])==k){
                i++;
            }
            int hh=h;
            while(h<=t&&min(sa[t]-sa[h],sb[t]-sb[h])==k){
                h++;
            }
            ans+=(i-t)*(min(h,t)-hh);
            i=t-1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}