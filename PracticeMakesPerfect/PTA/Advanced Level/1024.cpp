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
bool check(string s){
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[(int)s.size()-i-1]){
            return 0;
        }
    }
    return 1;
}
string cal(string s){
    string sum;
    int lst=0;
    for(int i=0;i<s.size();i++){
        int t=s[i]-'0'+s[(int)s.size()-i-1]-'0'+lst;
        sum.push_back(t%10+'0');
        lst=t/10;
    }
    if(lst)sum.push_back(lst+'0');
    reverse(sum.begin(),sum.end());
    return sum;
}
void solve(){
    string sum;int n;cin>>sum>>n;
    for(int i=0;i<=n;i++){
        if(check(sum)||i==n){
            cout<<sum<<endl<<i<<endl;
            return;
        }
        sum=cal(sum);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}