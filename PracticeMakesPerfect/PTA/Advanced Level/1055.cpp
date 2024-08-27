#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<string,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    string name;
    int age,wea;
    bool operator<(const Node &n)const{
        if(wea!=n.wea){
            return wea>n.wea;
        }
        if(age!=n.age){
            return age<n.age;
        }
        return name<n.name;
    }
};
void solve(){
    int n,m;cin>>n>>m;
    vector<Node>tmp;
    vector<Node>v;
    int book[300]={};
    for(int i=0;i<n;i++){
        string a;int b,c;cin>>a>>b>>c;
        tmp.push_back({a,b,c});
    }
    sort(all(tmp));
    for(auto [a,b,c]:tmp){
        if(book[b]<=100){
            v.push_back({a,b,c});
            book[b]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<"Case #"<<i<<":\n";
        int mx,l,r;cin>>mx>>l>>r;
        int cnt=0;
        for(int j=0;j<v.size();j++){
            if(v[j].age>=l&&v[j].age<=r){
                cout<<v[j].name<<' '<<v[j].age<<' '<<v[j].wea<<endl;
                cnt++;
            }
            if(cnt==mx)break;
        }
        if(!cnt)cout<<"None\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}