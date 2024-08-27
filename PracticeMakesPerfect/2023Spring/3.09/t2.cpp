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
        int num=0;
        int x=0,y=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a==1){num++;}
            else if(a==2){
                x=max(x,num);
                if(y)ans=max(ans,y/2+1+x);
                else ans=max(ans,x);
                y+=x;
                x=0;
                num=0;
            }
        }
        x=max(x,num);
        if(y)ans=max(ans,y/2+1+x);
        else ans=max(ans,x);
        cout<<ans<<endl;
    }
    return 0;
}