#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int a[N];
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=0;i<n*2;i++){
            cin>>a[i];
        }
        sort(a,a+n*2);
        int ans=0;
        for(int i=0;i<n*2;i++){
            ans+=abs(a[i]);
        }
        if(n==1){
            cout<<abs(a[1]-a[0])<<endl;
            continue;
        }
        else if(n%2==0){
            int mn=0x3f3f3f3f;int s=0;
            for(int i=0;i<n*2;i++){
                s+=abs(a[i]+1);
                mn=min(mn,abs(a[i]-n)-abs(a[i]+1));
            }
            ans=min(ans,s+mn);
        }
        int ans2=0;
        for(int i=0;i<n*2;i++){
            ans2+=abs(a[i]-2);
        }
        if(n==2)ans=min(ans,ans2);
        cout<<ans<<endl;
    }
    return 0;
}