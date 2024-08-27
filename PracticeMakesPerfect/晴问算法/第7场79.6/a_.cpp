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
    int n;cin>>n;
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        mp[s]++;
    }
    int ans=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            string s="";
            s+='a'+i;
            s+='a'+j;
            string s2="";
            s2+='a'+i;
            s2+='a'+j+1;
            string s3="";
            s3+='a'+i;
            s3+='a'+j-1;
            string s4="";
            s4+='a'+i+1;
            s4+='a'+j;
            string s5="";
            s5+='a'+i-1;
            s5+='a'+j;
            // cout<<s<<' '<<s2<<' '<<s3<<' '<<s4<<' '<<s5<<endl;
            if(mp.count(s)){
                ans+=mp[s]*mp[s2];
                ans+=mp[s]*mp[s3];
            }
            if(mp.count(s)){
                ans+=mp[s]*mp[s4];
                ans+=mp[s]*mp[s5];
            }
        }
    }
    cout<<ans/2<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}