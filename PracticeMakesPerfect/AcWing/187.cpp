#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n;
int ans;
int a[N];
int up[N],down[N];//上升队列和下降队列
void dfs(int s,int u,int d){//u相当于上升队列的数组长度，这恰巧是等于上升队列的个数
    if(u+d>=ans)return;
    if(s==n){
        ans=min(ans,u+d);
        return;
    }
    int l=0;int r=u+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(up[mid]>a[s]){
            l=mid;
        }else r=mid;
    }
    int temp=up[r];
    up[r]=a[s];
    dfs(s+1,max(u,r),d);
    up[r]=temp;//恢复现场
    l=0;r=d+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(down[mid]<a[s]){
            l=mid;
        }else r=mid;
    }
    temp=down[r];
    down[r]=a[s];
    dfs(s+1,u,max(d,r));
    down[r]=temp;//恢复现场
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>n,n){
        ans=n;//初始化！！！
        for(int i=0;i<n;i++)cin>>a[i];
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}