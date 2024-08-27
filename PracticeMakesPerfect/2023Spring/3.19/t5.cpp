#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int a[N];
int s[N];
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){cin>>a[i];s[i]=a[i]+s[i-1];}
        int l=1,r=n;
        while(l<r){
            int mid=l+r>>1;
            int ask=mid-l+1;
            cout<<"? "<<ask;
            for(int i=l;i<=mid;i++){
                cout<<' '<<i;           
            }
            cout<<endl;
            int ret=0;
            sc(ret);
            if(s[mid]-s[l-1]==ret){
                l=mid+1;
            }else r=mid;
        }
        cout<<"! "<<r<<endl;
    }
    return 0;
}