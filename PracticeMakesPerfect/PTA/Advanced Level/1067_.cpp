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
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>book(n);
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!book[i]){
            int t=i;
            if(v[t]==t){
                ans++;
                book[t]=1;
            }
            else{
                int flag=1;
                while(!book[t]){
                    if(t==0)flag=0;
                    book[t]=1;
                    t=v[t];
                }
                ans++;
                if(flag)cnt+=2;
            }
        }
    }
    cout<<n-ans+cnt<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}