#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,q;cin>>n>>q;
    vector<int>v(n);
    vector<PII>book[31];
    for(int i=0;i<n;i++){
        cin>>v[i];
        for(int j=30;j>=0;j--){
            if(v[i]%(1<<j)==0){
                book[j].push_back({i,v[i]});
                break;
            }
        }
    }
    for(int i=0;i<q;i++){
        int x;cin>>x;
        for(int k=x;k<=30;k++){
            for(int j=book[k].size()-1;j>=0;j--){
                book[x-1].push_back({book[k][j].x,book[k][j].y+(1<<(x-1))});
                book[k].pop_back();
            }
        }
    }
    vector<PII>ans;
    for(int i=0;i<30;i++){
        for(auto j:book[i])
        ans.push_back(j);
    }
    sort(all(ans));
    for(auto i:ans)cout<<i.y<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}