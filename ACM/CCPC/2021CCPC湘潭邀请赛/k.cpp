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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int k;string s;
    while(cin>>k,cin>>s){
        int l=0;
        map<char,int>cnt;
        int ans=0;
        int i=0;
        for(;i<s.size();i++){
            ans=max(ans,i-l);
            cnt[s[i]]++;
            if(cnt[s[i]]==k+1){
                ans=max(ans,i-l);
                while(l<=i&&s[l]!=s[i]){cnt[s[l]]--;l++;}
                l++;
                cnt[s[i]]--;
            }
        }
        ans=max(ans,i-l);
        cout<<ans<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}