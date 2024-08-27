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
int i,j,k'
void solve()
{
    int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(i=0;i<n;i++)cnt+=(s[i]=='(');
        if(cnt*2!=n)puts("-1");
        else
        {
            stack<int>st;
            stack<int>q;
            string ans;
            for(i=0;i<n;i++)
            {
                if(s[i]=='(')
                {
                    if(st.size())st.pop();
                    else {q.push('(');ans+='(';}
                }
                else
                {
                    if(q.empty())
                    {
                        ans+="()";
                        st.push(')');
                    }
                    else
                    {
                        ans+=")";
                        q.pop();
                    }
                }
            }
            vector<int>vv;
            for(i=0;i<n;i++)
            {
                if(ans[i]=='(')vv.push_back(i);
            }
            int res=0;
            int idx=0;
            for(i=0;i<n;i++)
            {
                if(s[i]=='(')res+=abs(vv[idx++]-i);
            }
            cout<<res<<"\n";
        }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}