#include<bits/stdc++.h>
using namespace std;
const int N=50010;
const int mod=998244353;
#define sc(n) scanf("%d",&n)
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
int book[N];
int flag=0;
int cmp(int &a,int &b){
    return book[a]<book[b];
}
void solve(){
    flag=0;
    int n;cin>>n;
    memset(book,0,sizeof(book));
    vector<int>v[N];
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int a;cin>>a;
            v[i].emplace_back(a);
            book[a]++;
        }
    }
    vector<int>ans;
    int flag=0;
    for(int i=n-1;i>=0;i--){
        sort(v[i].begin(),v[i].end(),cmp);
        if(book[v[i][0]]>=i+2){flag=1;break;}
        for(auto j:v[i])book[j]=1e6;
        ans.emplace_back(v[i][0]);
    }
    if(flag){cout<<-1<<endl;return;}
    else{
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<' ';
        }
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