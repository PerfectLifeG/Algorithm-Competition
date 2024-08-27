#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int, int> PII;
const int N = 200010;
const int mod = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n,m;cin>>n>>m;
    if(m==n-2){
        cout<<-1<<endl;
        return;
    }

    int a=1,b=(n-m)/3+1,c=(n-m)/3*2+1;
    vector<int>ans;
    if((n-m)%3==2){
        // cout<<(n-m)/3*3+1<<' ';
        ans.push_back((n-m)/3*3+1);
    }
    for(int i=1;i<=(n-m)/3;i++){
        ans.push_back(c++);
        ans.push_back(a++);
        ans.push_back(b++);
        // cout<<c++<<' '<<a++<<' '<<b++<<' ';
    }
    if((n-m)%3==1){
        // cout<<(n-m)/3*3+1<<' ';
        ans.push_back((n-m)/3*3+1);
    }
    else if((n-m)%3==2){
        // cout<<(n-m)/3*3+2<<' ';
        ans.push_back((n-m)/3*3+2);
    }
    if((n-m)%3==0&&ans.size())swap(ans[ans.size()-3],ans[ans.size()-2]);

    for(int i=n-m+1;i<=n;i++){
        // cout<<i<<' ';
        ans.push_back(i);
    }

    for(auto i:ans)cout<<i<<' ';
    cout<<endl;
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}