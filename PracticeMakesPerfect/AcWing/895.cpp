#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N],f[N],g[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<a[i]){
                if(f[i]<f[j]+1){
                    f[i]=f[j]+1;
                    g[i]=j;
                }
                
            }
        }
    }
    int k=1;
    for(int i=1;i<=n;i++)if(f[i]>f[k])k=i;
    cout<<f[k]<<endl;
    while(k){
        cout<<f[g[k]]<<" ";
        k=g[k];
    }
    return 0;
}