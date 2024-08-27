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
        for(int i=l1;i<=r1;i++){
            if(i+l2<=n&&i+r2>=n)s++;
        }
        cout<<s<<endl;
    }
    return 0;
}