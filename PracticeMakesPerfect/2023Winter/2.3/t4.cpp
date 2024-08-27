#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
int a[N];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int s=0;
    int t=n-1;
    int h=0;
    while(k>0){
        if(a[h]*a[h+1]>a[t]*a[t-1]){s+=a[h]*a[h+1];h+=2;}
        else {s+=a[t]*a[t-1];t-=2;}
        k--;
    }
    cout<<s;
    return 0;
}