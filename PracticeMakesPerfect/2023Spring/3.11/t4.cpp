#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int ans[2][2];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    int a1,b1,c1,a2,b2,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        if(a1*x+b1*y+c1<0&&a2*x+b2*y+c2<0)ans[1][1]++;
        if(a1*x+b1*y+c1>0&&a2*x+b2*y+c2>0)ans[0][0]++;
        if(a1*x+b1*y+c1>0&&a2*x+b2*y+c2<0)ans[0][1]++;
        if(a1*x+b1*y+c1<0&&a2*x+b2*y+c2>0)ans[1][0]++;
    }
    multiset<int>s;
    s.insert(ans[1][1]);s.insert(ans[0][1]);s.insert(ans[1][0]);s.insert(ans[0][0]);
    for(auto it:s)cout<<it<<' ';
    return 0;
}