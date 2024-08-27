#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=2e7+10;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int>dp(N);
unordered_map<char,char>mp;
void manercher(string &t){
    string s="$#";
    for(int i=0;i<t.size();i++){
        s+=t[i];s+='#';
    }
    s+='^';
    int r=0,mid;
    for(int i=1;i<s.size();i++){
        if(i<r)dp[i]=min(dp[mid*2-i],r-i+1);
        else dp[i]=0;
        while(mp[s[i-dp[i]]]==s[i+dp[i]])dp[i]++;//最多执行n次O(n)
        if(i+dp[i]>r){
            mid=i;
            r=i+dp[i]-1;
        }
    }
    // cout<<s<<endl;
    // for(int i=0;i<s.size();i++){
    //     cout<<dp[i];
    // }cout<<endl;
}
void solve(){
    int n;cin>>n;
    string s;
    vector<PII>v;
    int idx=0;
    mp['1']='1';mp['0']='0';mp['8']='8';
    mp['9']='6';mp['6']='9';mp['#']='#';

    for(int i=0;i<n;i++){
        string t;cin>>t;
        s+=t;
        v.push_back({idx+1,idx+t.size()});
        idx+=t.size();
    }
    manercher(s);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int l=v[i].x*2,r=v[j].y*2;
            int mid=l+r>>1;
            if(dp[mid]-1>=v[j].y-v[i].x+1){//调了一年bug
                ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}