#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,vv;cin>>n>>vv;
    int cnt=0;
    int temp=0;
    int v=vv-temp;
    while(n--)
    {   
        if(v<0)v=vv-temp;
        if(v>=0&&n==0)cnt++;
        int a;cin>>a;
        v-=a;
        if(v<0){cnt++;temp=a;}
    }
    cout<<cnt;
    return 0;
}