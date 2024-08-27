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
    vector<int>book(n);
    vector<int>L(n,-1);
    vector<int>R(n,-1);
    for(int i=0;i<n;i++){
        string a,b;cin>>a>>b;
        int t;
        if(a!="-"){
            t=stoi(a);
            L[i]=t,book[t]=1;
        }
        if(b!="-"){
            t=stoi(b);
            R[i]=t,book[t]=1;
        }
    }
    int root;
    for(int i=0;i<n;i++)if(!book[i]){root=i;break;}

    vector<int>in;
    function<void(int)> inorder=[&](int t){
        if(R[t]!=-1){
            inorder(R[t]);
        }
        in.push_back(t);
        if(L[t]!=-1){
            inorder(L[t]);
        }
    };

    vector<int>lay;
    function<void(int)> layer=[&](int t){
        queue<int>q;
        q.push(t);
        while(q.size()){
            auto t=q.front();
            lay.push_back(t);
            q.pop();
            if(R[t]!=-1){
                q.push(R[t]);
            }
            if(L[t]!=-1){
                q.push(L[t]);
            }
        }
    };
    
    inorder(root);
    layer(root);
    cout<<lay[0];
    for(int i=1;i<n;i++)cout<<' '<<lay[i];cout<<endl;
    cout<<in[0];
    for(int i=1;i<n;i++)cout<<' '<<in[i];

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}