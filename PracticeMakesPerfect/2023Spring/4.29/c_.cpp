#include<bits/stdc++.h>
using namespace std;
const int N=200010;
#define x first
#define y second
int a[N];
int q[N];
pair<int,int> f[N];
int main(){
    int n,p;cin>>n>>p;
    for(int i=0;i<n;i++)cin>>a[i];
    int len=0;
    for(int i=0;i<n;i++){
        int l=0,r=len+1;//遍历1-n的二分写法
        while(l+1!=r){
            int mid=l+r>>1;
            if(q[mid]<a[i]){
                l=mid;
            }else r=mid;
        }
        q[l+1]=a[i];
        if(l+1>len)len++;
        // cout<<l<<endl;
        f[i].x=len;
        // f[i].y=l;
    }
    while(p--){
        int l,r;cin>>l>>r;
        // cout<<f[f[r].y].x-f[f[l].y].x<<endl;
    }
    // printf("%d",len);
    return 0;
}