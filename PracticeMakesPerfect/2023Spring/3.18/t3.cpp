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
        int ans=0;
        for(int i=0;i<n*2;i++){
            cin>>a[i];
            ans+=abs(a[i]);
        }
        sort(a,a+n*2);
        if(n==1){
            cout<<abs(a[1]-a[0])<<endl;
            continue;
        }
        else if(n%2==0){
            int sum=0;
            for(int i=0;i<n*2-1;i++){
                sum+=abs(a[i]+1);
            }
            sum+=abs(a[n*2-1]-n);
            ans=min(ans,sum);
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