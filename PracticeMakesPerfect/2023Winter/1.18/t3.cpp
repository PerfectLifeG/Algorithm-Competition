#include<bits/stdc++.h>
using namespace std;
const int N=10010;
#define int long long 
#define sc(n) scanf("%d",&n)
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int s=0;
        for(int i=0;i<n;i++){
            int b;cin>>b;
            if(b<0)b=-b;
            s+=b;
        }
        s*=n;
        cout<<s*2<<endl;
    }
    return 0;
}