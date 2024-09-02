#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100010;
int pre[N];
int temp[30];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;
    memset(temp,-1,sizeof temp);
    for(int i=0;i<s.size();i++){
        pre[i]=temp[s[i]-'a'];
        temp[s[i]-'a']=i;
    }
    int ans=0;
    for(int i=0;i<s.size();i++){
        ans+=(i-pre[i])*(s.size()-i);
    }
    cout<<ans;
    return 0;
}