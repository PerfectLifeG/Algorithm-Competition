#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int w[N];int s[N];
int n;
int ef(int x){
    int l=-1;int r=n;
    while(l+1!=r){
        int mid=l+r>>1;
        if(w[mid]>x){
            r=mid;
        }else l=mid;
    }
    return l;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int q;cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    sort(w,w+n);
    int mx=0;
    s[0]=w[0];
    for(int i=1;i<n;i++){
        s[i]=w[i]+s[i-1];
    }
    for(int i=0;i<q;i++){
        int k,x;cin>>k>>x;
        int t=ef(x);
        if(t==-1)cout<<0<<endl;
        else if(t-k<0)cout<<s[t]<<endl;
        else cout<<s[t]-s[t-k]<<endl;
    }
    return 0;
}