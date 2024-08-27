#include<bits/stdc++.h>
using namespace std;
const int N=100010;
#define int long long
int a[N];
signed main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int s=a[0];
    for(int i=1;i<n-1;i++){
        a[i]+=a[i-1];
        s+=a[i];
    }
    cout<<s;
    return 0;
}