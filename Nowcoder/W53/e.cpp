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
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    vector<int>book(n+1);
    for(int i=n-1;i>=0;i--){
        while(a[i]>=n)a[i]/=2;
        book[a[i]]++;
    }
    for(int i=n-1;i>=1;i--){
        while(book[i]>1){
            book[i/2]++;
            book[i]--;
        }
    }
    // for(int i=0;i<=n;i++){
    //     cout<<book[i]<<' ';
    // }cout<<endl;
    // return;
    int j=n;
    for(int i=0;i<=n;i++){
        if(!book[i]){
            for(;j>i;j--){
                if(book[j]){
                    int t=j;
                    int flag=0;
                    while(t>=i){
                        if(!book[t]&&t>=i){
                            flag=t;
                        }
                        t/=2;
                    }
                    if(flag){
                        book[flag]++;
                        book[j]--;
                        break;
                    }
                }
            }
            if(!book[i]){
                cout<<i<<endl;
                return;
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}