#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    int n,m;cin>>n>>m;
    double s=0;
    if(n>=m){
        while (m)
        {
            s+=1.0/m;
            m--;
        }
    }else{
        s+=1.0*(m-n+1)/m;
        m=m-n+1;
        while (m)
        {
            s+=1.0/m;
            m--;
        }
    }
    printf("%.9lf",s);
    return 0;
}