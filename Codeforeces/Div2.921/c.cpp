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
    int n,k,m;
    n=4,k=4,m=20;
    cin>>n>>k>>m;
    // srand(time(nullptr));
    string s;
    cin>>s;
    // for(int i=0;i<m;i++){
    //     s+=char(rand()%4+'a');
    // }cout<<s<<endl;
    int cnt=0;
    vector<int>mp(k,0);
    int siz=0;
    string ans="";
    for(int i=0;i<m;i++){
        if(mp[s[i]-'a']==cnt){mp[s[i]-'a']++;siz++;}
        if(siz==k){ans.push_back(s[i]);cnt++;siz=0;}
    }
    if(cnt>=n){
        yes;
    }else{
        no;
        for(int i=k-1;i>=0;i--){
            if(mp[i]!=cnt+1){
                cout<<ans;
                cout<<char('a'+i);
                if(n-1-cnt>0)cout<<string(n-1-cnt,'a');
                    cout<<endl;
                return;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}