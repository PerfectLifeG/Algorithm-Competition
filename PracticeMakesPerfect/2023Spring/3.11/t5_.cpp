#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int k=n/4;
    double ans=0;double mx=0;
    for(int i=0;i<n;i++){
        multiset<double>s;
        for(int j=0;j<4;j++){
            double x;cin>>x;s.insert(x/100);
            mx=max(mx,x);
        }
        // auto it=s.end();it--;
        // for(int j=0;j<1;j++){ans+=*it;it--;}
        ans+=mx;
    }
    cout<<ans;
    return 0;
}