#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=10010;
#define sc(n) scanf("%d",&n)
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int l1,r1,l2,r2;;
        cin>>l1>>r1>>l2>>r2;
        int s=0;
        int l=n-r2;
        int r=n-l2;
        if(l<l1)l=l1;
        if(r>r1)r=r1;
        if(l>r1||r<l1){cout<<0<<endl;continue;}
        // if(n%2==0){
        //     if(l1<n/2&&n/2<r1&&l2<n/2&&n/2<r2)
        //     s--;
        // }
        cout<<r-l+s+1<<endl;
    }
    return 0;
}