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
    int n,m;cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=-1,r=n;
    string s;cin>>s;
    for(auto i:s)if(i=='L')l++;else r--;
    reverse(all(s));
    vector<int>ans;
    int sum=1;
    for(auto i:s){
        if(i=='L'){
            sum=sum*(a[l]%m)%m;
            l--;
        }
        else{
            sum=sum*(a[r]%m)%m;
            r++;
        }
        ans.push_back(sum);
    }
    reverse(all(ans));
    for(auto i:ans)cout<<i<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}