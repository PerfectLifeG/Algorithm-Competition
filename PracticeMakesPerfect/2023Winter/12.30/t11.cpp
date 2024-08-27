#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        priority_queue<int,vector<int>,greater<int>>q;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            int a;scanf("%lld",&a);
            q.push(a);
        }
        for(int i=0;i<m;i++){
            int a;scanf("%lld",&a);
            q.pop();
            q.push(a);
        }
        int sum=0;
        while(q.size()){
            sum+=q.top();
            q.pop();
        }
        cout<<sum<<endl;
    }
    return 0;
}