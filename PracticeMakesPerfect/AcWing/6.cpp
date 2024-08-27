#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m;
int f[N],g[N],q[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int v,w,s;
        cin>>v>>w>>s;
        memcpy(g,f,sizeof f);
        for(int r=0;r<v;r++){//余数
            int h=0;int t=0;//r r+v r+2v r+sv 
            for(int j=r;j<=m;j+=v){//体积
                if(h<t&&j-s*v>q[h])h++;//最大值不在滑动队列中
                while(h<t&&g[q[t-1]]-(q[t-1]-r)/v*w<=g[j]-(j-r)/v*w)t--;//消去无用元素
                q[t++]=j;
                f[j]=g[q[h]]+(j-q[h])/v*w;//q[h]现在是max   不需要写if(i>=k-1)这种条件因为每一个f[j]都要求一个max
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}