#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>box;
    queue<int>fl;
    vector<int>v;
    int n,m,k;cin>>n>>m>>k;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        fl.push(a);
    }
    
    while(!fl.empty()||!box.empty()||!v.empty()){
        int flag=0;
        if(v.empty()){
            if(!box.empty()){//第一次插
                v.push_back(box.top());//box能插
                box.pop();
            }else{//box不能插fl插
                v.push_back(fl.front());
                fl.pop();
            }
        }else{//第n次插
            if(v.size()==k)flag=1;
            else{
                if(!box.empty()){//box不为空  
                    if(box.top()<=v.back()){//box插
                        v.push_back(box.top());
                        box.pop();
                    }else{
                        //box不为空且插不了情况下
                        if(!fl.empty()){//fl不为空情况下
                            if(fl.front()<=v.back()){//fl插
                                v.push_back(fl.front());
                                fl.pop();
                            }else{//fl插不了
                                if(box.size()<m){//fl插到box中
                                    box.push(fl.front());
                                    fl.pop();
                                }else flag=1;//box满了输出
                            }
                        }else{//fl为空
                            flag=1;
                        }
                    }
                }else{
                    if(!fl.empty()){
                        if(fl.front()<=v.back()){
                            v.push_back(fl.front());
                            fl.pop();
                        }else{
                            if(box.size()<m){
                                box.push(fl.front());
                                fl.pop();
                            }else flag=1;
                        }
                    }else{
                        flag=1;
                    }
                }
            }
        }
        if(flag){
            cout<<v[0];
            for(int i=1;i<v.size();i++){
                cout<<" "<<v[i];
            }cout<<endl;
            v.clear();
        }
    }
    return 0;
}