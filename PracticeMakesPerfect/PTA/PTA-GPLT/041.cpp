#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;cin>>n>>m>>k;
    stack<int>s;
    queue<int>q;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        q.push(a);
    }
    vector<int>t;
    while(!q.empty()||!s.empty()){
        int flag=0;
        if(t.empty()){
            if(!s.empty()){//s能插
                t.push_back(s.top());
                s.pop();
            }else{//插q
                t.push_back(q.front());
                q.pop();
            }
        }else if(t.size()<k){
            if(!s.empty()&&s.top()<=t.back()){//s能插
                t.push_back(s.top());
                s.pop();
            }else if(q.empty()){
                flag=1;
            }else if(q.front()<=t.back()){//q能插
                t.push_back(q.front());
                q.pop();
            }else if(q.front()>t.back()&&s.size()<m){//q不能插但是能给s
                s.push(q.front());
                q.pop();
            }else if(q.front()>t.back()&&s.size()>=m){//q不能插并且不能给s
                flag=1;
            }
            //假如q插完了s中有那么
        }
        if(t.size()==k)flag=1;
        if(q.empty()&&s.empty())flag=1;
        if(flag){
            cout<<t[0];
            for (int i = 1; i < t.size(); i++)
            {
                cout<<" "<<t[i];
            }
            cout<<endl;
            t.clear();
        }
    }
    return 0;
}