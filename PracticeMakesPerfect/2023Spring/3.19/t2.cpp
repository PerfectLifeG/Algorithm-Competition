#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a&1){
                ans1+=a;
            }else ans2+=a;
        }
        if(ans1<ans2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}