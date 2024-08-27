#include<bits/stdc++.h>
using namespace std;
const int N=200010;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        int cnt=0;
        set<int>s;
        int book[N]={};
        for(int i=0;i<n;i++){
            int a;cin>>a;
            book[a]++;
            s.insert(a);
        }
        int ans=0;
        if(!book[0]){cout<<0<<endl;continue;}
        for(auto i:s){
            if(book[i]<=n-book[0]+1){ans=i;break;}
            n-=book[i];
            ans=i+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}