#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int cmp(int a,int b){
    return a>b;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;scanf("%d",&n);
        int a[n],b[n],s[n];
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        sort(b,b+n,cmp);
        for(int i=0;i<n;i+=2){
            a[i]=b[i/2];
            a[i+1]=b[n-i/2-1];
        }
        s[0]=a[0];
        int flag=1;
        for(int i=1;i<n;i++){
            s[i]=a[i]+s[i-1];
            if(a[i]==s[i-1]){
                printf("NO\n");
                flag=0;}
        }
        if(flag){
            printf("YES\n");
            for(int i=0;i<n;i++){
                printf("%d ",a[i]);
            }
            puts("");
        }
    }
    return 0;
}