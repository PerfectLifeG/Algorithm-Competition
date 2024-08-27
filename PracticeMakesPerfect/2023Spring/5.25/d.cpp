#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    stack<char>st;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(')cnt1++;
        else cnt2++;
    }
    if (cnt1!=cnt2)
    {
            cout<<-1<<endl;
            return;
    }
    int flag=1;
    for(int j=0;j<n;){
        int i=j+1;
        while(i<n&&s[i]==s[j]){a[i]=a[j];i++;}
        int t=i;
        while(i<n&&s[i]!=s[j]){a[i]=a[j];i++;}
        if(i-t>t-j){

        }
        j=i;
    }
    if(flag)cout<<2<<endl;
    else cout<<1<<endl;
    for(int i=0;i<n;i++){
        if(a[i]==-1)cout<<2<<' ';
        else cout<<a[i]<<' ';
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}