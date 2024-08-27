#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int mod=1e9+7;
int n;
int f[N];
int main(){
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){//递增循环 从背包0开始
            f[j]=(f[j]+f[j-i])%mod;//当j>=i时背包才能装下 所以有条件
        }
    }
    cout<<f[n];
    return 0;
}