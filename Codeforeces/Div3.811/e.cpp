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
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int lst=-1;
    unordered_map<int,int>mp;
    mp[1]=1;mp[2]=0;mp[3]=3+6;mp[4]=4+8+6;mp[5]=5;
    mp[6]=6;mp[7]=7+4+8+6;mp[8]=8+6;mp[9]=9+8+6;mp[0]=0;
    for(int i=0;i<n;i++){
        int t=a[i]%10;
        a[i]+=mp[t];
        if(lst==-1){
            lst=a[i];
        }else if(!(lst==a[i]||lst%10!=0&&a[i]%10!=0&&abs(lst-a[i])%(2+4+8+6)==0)){
            no;
            return;
        }
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}