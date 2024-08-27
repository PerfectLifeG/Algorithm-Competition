#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int f[N];
int main(){
    f[0]=1;f[1]=0;f[2]=1;
    for(int i=2;i<20;i++){
        for(int k=1;k<=i/k;k++){
            if(i%k==0)f[i]=max(f[i-i/k]^1,f[i-k]^1);
            if(f[i]==1)break;
        }
    }
    for(int i=1;i<=20;i++){
        printf("%d ",f[i]);
    }
    system("pause");
    return 0;
}