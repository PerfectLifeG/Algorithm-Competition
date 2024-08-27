#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
typedef pair<int,int> PII;
int book[10];
void solve(){
    string s;
    int m;string a,b;
    cin>>s>>m>>a>>b;
    int j=0;
    int idx=-1;
    for(int i=0;i<m;i++){
        int j=idx+1;
        int t=0;
        for(;j<s.size();j++){
            if(book[s[j]-'0']==0&&s[j]>=a[i]&&s[j]<=b[i]){
                book[s[j]-'0']=1;
                idx=j;
                t++;
                // cout<<j<<' '<<s[j]<<endl;
            }
        }
        memset(book,0,sizeof book);
        if(t!=b[i]-a[i]+1){
            yes;
            return;
        }
        // cout<<endl;
    }
    no;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}