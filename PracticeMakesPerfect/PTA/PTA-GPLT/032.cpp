#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;cin>>n>>m>>k;
    for (int i = 0; i < k; i++)
    {
        int index=1;int flag=1;
        stack<int>s;
        for (int i = 0; i < n; i++)
        {
            int a;cin>>a;
            if(flag==0)continue;
            if(a!=index){
                if(!s.empty()){
                    if(s.top()!=index){
                        if(s.top()<a)flag=0;
                        s.push(a);
                    }else {
                        while(!s.empty()&&s.top()==index){
                            index++;
                            s.pop();
                        }
                    }
                }
                else{
                    s.push(a);
                }
            }else {
                index++;
                while(!s.empty()&&s.top()==index){
                    index++;
                    s.pop();
                }
            }
            if(s.size()>m||flag==0){
                flag=0;
                cout<<"NO"<<endl;
            }
            if(index==n+1)cout<<"YES"<<endl;
        }
    }
    return 0;
}