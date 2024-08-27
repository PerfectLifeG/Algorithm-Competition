#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N];
int book[N];
int group[N][N];
int n;
int ans=N;
int check(int g[],int mcnt,int t){
    for(int i=0;i<mcnt;i++){
        if(__gcd(a[g[i]],a[t])!=1)
            return false;
    }
    return true;
}
void dfs(int gcnt,int mcnt,int s,int start){
    if(gcnt>=ans)return;//当组数大于ans一定不是最优解
    if(s==n){
        ans=min(ans,gcnt);
        return;//当遍历a中所有元素一遍后，更新ans
    }
    int flag=1;
    for(int i=start;i<n;i++){
        if(book[i]==0&&check(group[gcnt],mcnt,i)){
            book[i]=1;
            group[gcnt][mcnt]=i;
            dfs(gcnt,mcnt+1,s+1,i);
            book[i]=0;
            flag=0;
            
            if(mcnt==0)return;
        }
    }
    if(flag)dfs(gcnt+1,0,s,0);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    dfs(1,0,0,0);
    cout<<ans<<endl;
    return 0;
}