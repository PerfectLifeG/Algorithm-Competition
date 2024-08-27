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
    string a(n,'1');
    // cout<<a<<endl;
    if(s=="0"){
        if(k&1)cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    if(s==a){
        if(n==1){
            if(k&1)cout<<0<<endl;
            else cout<<1<<endl;
            return;
        }
        else if(k==1){
            a[n-1]='0';
            cout<<a<<endl;
            return;
        }
        // return;
    }
    int cnt=0;
    for(int i=0;i<n;){
        // cout<<s<<endl;
        if(k<=cnt)break;
        // cout<<i<<endl;
        if(s[i]=='1'){i++;continue;}
        s[i]='1';
        int j=i+1;
        while(j<n&&s[j]=='0'){
            s[j]='1';
            j++;
        }
        cnt++;
        i=j;
    }
    cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}