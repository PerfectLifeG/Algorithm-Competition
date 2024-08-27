#include<bits/stdc++.h>
using namespace std;
const int N=40;
struct Node
{
    int s;
    int e;
    int l;
    bool operator<(const Node n)const{
        return s*n.l<n.s*l;
    }
}node[N];
int f[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    for(int t=1;t<=T;t++){
        int n,m=0;cin>>n;
        for(int i=0;i<n;i++){
            cin>>node[i].s>>node[i].e>>node[i].l;
            m+=node[i].s;
        }
        // sort(node,node+n);
        memset(f,-0x3f,sizeof f);
        f[0]=0;
        for(int i=0;i<n;i++){
            for(int j=m;j>=node[i].s;j--){
                f[j]=max(f[j],f[j-node[i].s]+node[i].e);
            }
        }
        int res=0;
        for(int i=0;i<=m;i++)res=max(res,f[i]);//为什么需要这一步？
        //因为f[m]不为最大，这是因为node[i].e-(j-node[i].s)*node[i].l)可能为负值，
        //但是如果f[j]=max(f[j],f[j-node[i].s]+max(0,node[i].e-(j-node[i].s)*node[i].l));这样写也不行
        //因为物品的枚举顺序影响物品的价值
        printf("Case #%d: %d\n",t,res);
    }
    return 0;
}