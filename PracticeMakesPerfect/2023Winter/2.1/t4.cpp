#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int x,y,k,n,T;
    cin>>x>>y>>k>>n>>T;
    int s=0;int cnt=0;
    for(int i=0;i<n;i++){
        if(s+(n-i)*(x+y*(cnt/k))>=T){
            cnt+=(T-s)/(x+y*(cnt/k))+(bool)(T-s)%(x+y*(cnt/k));
            cout<<i;
            return 0;
        }else s+=(n-i)*(x+y*(cnt/k));
        cnt+=n-i;
    }
    cout<<-1;
    return 0;
}