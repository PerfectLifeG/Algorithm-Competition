#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,sm;cin>>n>>m>>sm;
    stack<char>s;
    queue<char>q[n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;cin>>c;
            q[i].push(c);
        }
    }
    int k;cin>>k;
    string ans="";
    while(k!=-1){
        if(k==0){
            if(!s.empty()){
                ans+=s.top();
                s.pop();
            }
        }else if(!q[k].empty()){
            if(s.size()==sm){
                ans+=s.top();
                s.pop();
            }
            s.push(q[k].front());
            q[k].pop();
        }
        cin>>k;
    }
    cout<<ans;
    return 0;
}