#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,k;cin>>n>>k;
    string s;cin>>s;
    if(k%2==0){
        sort(all(s));
        cout<<s<<endl;
        return;
    }
    vector<char>s1,s2;
    for(int i=0;i<n;i++)if(i&1)s1.push_back(s[i]);else s2.push_back(s[i]);
        sort(all(s2));
        sort(all(s1));
    for(int i=0;i<n;i++){
        if(i<s2.size())
        cout<<s2[i];
        if(i<s1.size())
    cout<<s1[i];
    }
    cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}