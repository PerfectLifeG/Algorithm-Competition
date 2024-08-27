#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300010;
int cnt[N];
int val[N];
int root[N];
int h[N],e[N],ne[N],idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int cmp(int a,int b){
    return a>b;
}
int cal(int t){
    for(int i=h[t];i!=-1;i=ne[i]){
        int j=e[i];
        cnt[t]+=cal(j);
    }
    return cnt[t]+=1;
}
signed main(){
    memset(h,-1,sizeof(h));
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    sort(val+1,val+n+1,cmp);
    for(int i=2;i<=n;i++){
        scanf("%d",&root[i]);
        add(root[i],i);
    }
    cal(1);
    sort(cnt+1,cnt+n+1,cmp);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=cnt[i]*val[i];
    }
    cout<<sum;
    return 0;
}