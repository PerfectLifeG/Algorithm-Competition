#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
int f[N];
int w[N];int q[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>w[n])n++;
    int res=0;
    for(int i=0;i<n;i++){
        f[i]=1;
        for(int j=0;j<i;j++){
            if(w[j]<w[i])
                f[i]=max(f[i],f[j]+1);
        }
    }
    cout<<f[n]<<endl;
    int cnt=0;
    for(int i=0;i<n;i++){
        int l=0,r=cnt+1;//遍历1-n的二分写法
        while(l+1!=r){
            int mid=l+r>>1;
            if(q[mid]<w[i]){
                l=mid;
            }else r=mid;
        }
        q[l+1]=w[i];
        if(l+1>cnt)cnt++;
    }
    printf("%d",cnt);
    return 0;
}