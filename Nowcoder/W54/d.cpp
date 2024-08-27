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
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];

    vector<int>book(n+1);
    book[1]=1;

    queue<int>q;
    q.push(1);
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(a[t]%i==0){
                if(t-i>=1&&!book[t-i]){
                    book[t-i]=book[t]+1;
                    q.push(t-i);
                }
                if(t+i<=n&&!book[t+i]){
                    book[t+i]=book[t]+1;
                    q.push(t+i);
                }
            }
        }
    }
    cout<<book[n]-1<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}