#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int st,n,k;cin>>st>>n>>k;
    unordered_map<int,int>nx;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        mp[a]=b;
        nx[a]=c;
    }
    vector<int>ans;
    vector<int>ans2;
    while(st!=-1){
        ans.push_back(st);
        st=nx[st];
    }
    for(int i=0;i<ans.size();i+=k){
        if(i+k-1<ans.size()){
            for(int j=i+k-1;j>=i;j--){
                ans2.push_back(ans[j]);
            }
        }else{
            for(int j=i;j<ans.size();j++){
                ans2.push_back(ans[j]);
            }
        }
    }
    for(int i=0;i<ans2.size();i++){
        if(i+1<ans2.size())printf("%05d %d %05d\n",ans2[i],mp[ans2[i]],ans2[i+1]);
        else printf("%05d %d -1",ans2[i],mp[ans2[i]]);
    }
}
signed main(){
    int _=1;
    while(_--)solve();
    return 0;
}