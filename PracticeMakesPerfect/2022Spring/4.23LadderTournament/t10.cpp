#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>box;queue<int>s;queue<int>tree;
    int n,m,k;cin>>n>>m>>k;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        s.push(a);
    }
    while (1)
    {
            if(!box.empty()){
                if((tree.empty())||box.top()<=tree.back()){
                int t=box.top();
                box.pop();
                tree.push(t);  
                }else{
                    if(!s.empty()){
                    int t=s.front();
                        if(tree.empty()||t<=tree.back())
                        { 
                            s.pop();
                            tree.push(t);
                        }else{
                            s.pop();
                            box.push(t);
                        }
                    }
                }
            }else{
                if(!s.empty()){
                int t=s.front();
                    if(tree.empty()||t<=tree.back())
                    { 
                        s.pop();
                        tree.push(t);
                    }else{
                        s.pop();
                        box.push(t);
                    }
                }
            }

        if(!box.empty()&&box.size()==m){
            cout<<tree.front();tree.pop();
            while(!tree.empty()){cout<<" "<<tree.front();
            tree.pop();}
            cout<<endl;
        }
        if(!tree.empty()&&tree.size()==k){
            cout<<tree.front();tree.pop();
            while(!tree.empty()){cout<<" "<<tree.front();
            tree.pop();}
            cout<<endl;
        }
        if(box.empty()&&s.empty()){
            cout<<tree.front();tree.pop();
            while(!tree.empty()){cout<<" "<<tree.front();
            tree.pop();}
            cout<<endl;
            break;}
    }
    return 0;
}