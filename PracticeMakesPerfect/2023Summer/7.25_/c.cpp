#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]==a[n-1]){
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            if(a[i]==a[0]&&mp[a[i]]==k){
                yes;
                return;
            }
        }
        no;
        return;
    }
    int cnt=1;
    int idx=n-1;
    for(int i=n-2;i>=0;i--){
        if(cnt==k)break;
        if(a[i]==a[n-1]){cnt++;idx=i;}
    }
    int idx2=0;
    if(cnt!=k){
        no;
        return;
    }
    cnt--;
    for(int i=1;i<n;i++){
        if(cnt==0||i>=idx)break;
        if(a[i]==a[0]){cnt--;idx2==i;}
    }
    if(cnt){no;return;}
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}