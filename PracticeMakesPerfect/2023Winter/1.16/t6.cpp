#include<bits/stdc++.h>
using namespace std;
const int N=100010;
double jisuan(int m){
    double s=0;
    while (m)
    {
        s+=1.0/m;
        m--;
    }
    return s;
}
int main(){
    int n,m;cin>>n>>m;
    double s=0;
    for(int i=0;i<n;i++){
        for(int j=m-n+1;j>0;j--){
            m-=j;n--;
            if(m==n){
                s+=jisuan(m);
                printf("%d ",);
            }else{
                n=
                m=
            }
        }
    }

    return 0;
}