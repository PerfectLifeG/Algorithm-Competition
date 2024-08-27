#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    string s;
    cin>>s;
    int i;
    int n,m;
    cin>>n>>m;
    string t;
    vector<string>v;
    for(i=0;i<s.size();i++)
    {
        int j=i;
        while(j<s.size()&&s[j]>='0'&&s[j]<='9')
        {
            t=t+s[j];
            j++;
        }
        v.push_back(t);
        t="";
    }
    int cnt=0;
    i=0;
    cout<<"[";
    while(i<v.size())
    {
        bool flag=0;
        cout<<"[";
        int now=i;
        for(;i<now+m;i++)
        {
            if(!flag)cout<<",";
            cout<<v[i];   
        }
        cout<<']';
        if(i<v.size())cout<<",";
    }
    cout<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}