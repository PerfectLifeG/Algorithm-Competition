#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
void solve(){
    string s;
    cin>>s;
    int book[100]={0};
    int mx=0;
    for(int i=0;i<s.size();i++){
        book[s[i]-'0']++;
        mx=max(mx,book[s[i]-'0']);
    }
    if(mx==1){cout<<4<<endl;return;}
    if(mx==2){cout<<4<<endl;return;}
    if(mx==3){cout<<6<<endl;return;}
    if(mx==4){cout<<-1<<endl;return;}
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}