#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n,m;
        cin>>n>>m;
        int s=n*m;
        int ss=s;int cnt;
        int t=1;
        while(ss/=10){
            cnt++;
            t*=10;
        }
        if(t%n!=0){
            cout<<n*(m/t%n);
        }else{
            cout<<n*(m/(t%n)*(t%n));
        }
    }
    return 0;
}