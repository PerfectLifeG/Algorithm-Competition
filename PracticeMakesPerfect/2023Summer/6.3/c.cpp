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
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[n]==1){
        no;
        return;
    }
    deque<int>q;
    for(int i=n;i>=1;i--){
        if(a[i]==0)q.push_front(0);
        else {
            int j=i;
            while(j-1>=1&&a[j-1]==1){
                j--;
            }
            int t=i-j+1;
            for(int k=0;k<t-1;k++)q.push_front(0);
            q.push_front(t);
            i=j;
        }
    }
    yes;
    while(q.size()){
        cout<<q.back()<<' ';
        q.pop_back();
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