#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int x;cin>>x;
    int l,r;cin>>l>>r;
    if(x>r){cout<<0;return 0;}
    double res=1.0*(max(0,x-l))/(r-l+1);
    printf("%.10lf",res);
    return 0;
}