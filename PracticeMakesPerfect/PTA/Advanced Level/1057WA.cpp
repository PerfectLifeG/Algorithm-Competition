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
    int m;cin>>m;
    multiset<int>st{-1000000,1000000};
    auto it=st.begin();
    stack<int>s;
    while(m--){
        string op;cin>>op;
        if(op=="Pop"){
            if(!s.size()){
                cout<<"Invalid\n";
                continue;
            }else cout<<s.top()<<endl;
            int a=s.top();
            auto p=it;
            int t=*it;
            s.pop();
            if(a>=t)p++;
            if(a<t)p--;
            st.erase(st.find(a));
            if(st.size()%2==0&&a>=t){
                it=p;
            }
            else if(st.size()%2!=0&&a<t){
                it=p;
            }
        }else if(op=="PeekMedian"){
            if(it==st.begin()){
                cout<<"Invalid\n";
                continue;
            }
            cout<<*it<<endl;
        }else{
            int a;cin>>a;
            s.push(a);
            st.insert(a);
            if(st.size()%2!=0&&a>*it){
                it++;
            }else if(st.size()%2==0&&a<=*it)it--;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}