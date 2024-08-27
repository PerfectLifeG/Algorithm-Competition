#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
void solve()
{
    int n;cin>>n;
    vector<int>book(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=n)
        book[a[i]]++;
    }
    for(int i=n;i>=1;i--){
        for(int j=i+i;j<=n;j+=i){
            book[j]+=book[i];
            // cout<<j<<' ';
        }
        // cout<<endl;
    }
    cout<<*max_element(book.begin(),book.end())<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}