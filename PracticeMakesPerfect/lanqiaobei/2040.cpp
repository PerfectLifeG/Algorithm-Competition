#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200003;
int f[N][10];
int s[10];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        int cnt=0;
        while(a!=1){
            s[++cnt]=a;
            a=sqrt(a/2+1);
        }
        ans+=cnt;
        for(int j=1;cnt>0;j++,cnt--){
            f[i][j]=s[cnt];
        }
    }
    for(int j=1;j<=8;j++){
        for(int i=1;i+1<=n;i++){
            if(f[i][j]&&f[i+1][j]==f[i][j])ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}