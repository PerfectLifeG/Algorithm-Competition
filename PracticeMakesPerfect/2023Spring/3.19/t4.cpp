#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int a[N];
int s[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=a[i]+s[i-1];
        }
        for(int i=0;i<q;i++){
            int l,r,k;
            cin>>l>>r>>k;
            int ret=s[n]-s[r]+s[l-1]+(r-l+1)*k;
            if(ret&1){
                puts("YES");
            }else puts("NO");
        }
    }
    return 0;
}