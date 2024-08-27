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
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    vector<int>book(n);
    int flag=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==i+1)flag=1;
    }
    int id=n-1;int t=n-1;
    int idx=2;
    book[n-1]=1;
    if(!flag){
        idx=1;
        book[n-1]=0;
    }
    while(1){
        if(book[(id+a[t])%n]){
            if(k%(abs(book[id]-book[(id+a[t])%n])+1)==book[(id+a[t])%n]-1){
                yes;
            }else no;
            return;
        }
        book[(id+a[t])%n]=idx++;
        cout<<id<<' '<<(id+a[t])%n<<' '<<t<<' '<<book[(id+a[t])%n]<<endl;
        id=(id+a[t])%n;
        t=(t-a[t]+n)%n;
        if(t){
            
        }
    }
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}