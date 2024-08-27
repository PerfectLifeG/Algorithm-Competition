#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;scanf("%d",&n);
        int mx=0,mn=1023;
        for(int j=0;j<n;j++){
            int x;scanf("%d",&x);
            mx=mx|x;
            mn=mn&x;
        }
        printf("%d\n",mx-mn);
    }
    return 0;
}