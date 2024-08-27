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
    string s;cin>>s;
    int x,y,z;cin>>x>>y>>z;
    int ans=0;
    for(int i=0;i<n;){
        if(s[i]!='0'){i++;continue;}
        int j=i+1;
        while(j<n&&s[j]=='0')j++;
        int c1=j-i;
        int t=j;
        while(j<n&&s[j]=='1')j++;
        int c2=j-t;
        ans+=min(c1,c2);
        i=j;
    }
    cout<<min(ans,y)<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}