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
    string s;cin>>s;
    int cnt=0;
    int n=s.size();
    for(int i=0;i<n;){
        if(s[i]=='1'){
            while(i<n&&s[i]=='1'){
                i++;
            }
            if(i<n)cnt++;
            while(i<n&&s[i]=='0')i++;
        }else i++;
    }
    cout<<cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}