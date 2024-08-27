#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,k;
int main(){
    int t;cin>>t;
    while(t--){
        scanf("%d%d",&n,&k);
        int a[N];
        int idx=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==idx+1)idx++;
        }
        bool yu=(n-idx)%k;
        printf("%d\n",(n-idx+1)/k+(int)yu);
    }
    return 0;
}