#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[N];
int q[N];
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    //q[0]=a[0];
    int len=0;
    for(int i=0;i<n;i++){
        int l=0,r=len+1;
        while(l+1!=r){
            int mid=l+r>>1;
            if(q[mid]<a[i]){
                l=mid;
            }else r=mid;
        }
        q[l+1]=a[i];
        if(l+1>len)len++;
    }
    printf("%d",len);
    return 0;
}