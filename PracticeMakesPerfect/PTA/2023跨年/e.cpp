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
    string s;
    getline(cin,s);
    int ans=0;
    int f=-1;
    for(int i=0;i<s.size();i++){
        if(i+3<s.size()&&s[i]=='N'&&s[i+1]=='i'&&s[i+2]=='a'&&s[i+3]=='n'){
            if(f==-1)f=i;
            ans++;
        }
    }
    cout<<ans<<' '<<f<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}