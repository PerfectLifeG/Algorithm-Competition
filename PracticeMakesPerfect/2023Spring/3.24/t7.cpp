#include<bits/stdc++.h>
using namespace std;
const int N=3010,M=1000010;
int x[N],y[N];
int dot[N][N];
int cnt[M];
int get(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j])-(y[i]-y[j])*(y[i]-y[j]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        x[i]=a+1500;
        y[i]=b+1500;
        dot[a+1500][b+1500]=1;
    }
    int ans=0,dup=0;
    for(int i=0;i<n;i++){
        memset(cnt,0,sizeof cnt);
        for(int j=0;j<n;j++){
            if(i==j)continue;
            int dis=get(i,j);
            ans+=cnt[dis];
            cnt[dis]++;
            if(dot[2*x[i]-x[j]][2*y[i]-y[j]])dup++;
        }
    }
    cout<<ans-2*dup;
    return 0;
}