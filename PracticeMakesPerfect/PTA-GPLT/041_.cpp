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
    vector<int>v;
    while(!q.empty()||!s.empty()||!v.empty()){
        int flag=0;
        if(v.empty()){
            if(!s.empty()){
                v.push_back(s.top());
                s.pop();
            }else{
                v.push_back(q.front());
                q.pop();
            }
        }else{
            if(v.size()==k)
                flag=1;
            else{
                if(!s.empty()){
                    if(s.top()<=v.back()){
                        v.push_back(s.top());
                        s.pop();
                    }else{
                        if(q.empty()){
                        flag=1;
                        }else{
                            if(q.front()<=v.back()){
                                v.push_back(q.front());
                                q.pop();
                            }else if(q.front()>v.back()){
                                if(s.size()<m){
                                    s.push(q.front());
                                    q.pop();
                                }else flag=1;
                            }
                        }
                    }
                }else{
                    if(q.empty()){
                        flag=1;
                    }else{
                        if(q.front()<=v.back()){
                            v.push_back(q.front());
                            q.pop();
                        }else if(q.front()>v.back()){
                            if(s.size()<m){
                                s.push(q.front());
                                q.pop();
                            }else flag=1;
                        }
                    }
                }
            }
        }
        if(flag){
            cout<<v[0];
            for (int i = 1; i < v.size(); i++)
            {
                cout<<" "<<v[i];
            }
            cout<<endl;
            v.clear();
        }
    }
    return 0;
}