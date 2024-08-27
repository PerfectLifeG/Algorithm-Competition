#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int n,m;cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int a;cin>>a;
        v.push_back(a);
        push_heap(v.begin(),v.end(),greater<int>());
    }
    for (int i = 0; i < m; i++)
    {
        int a;cin>>a;
        int index= find(v.begin(),v.end(),a)-v.begin();//nb,若返回迭代器，则减去v.begin()得下标
        string s;cin>>s;
        if(s=="is"){
            cin>>s>>s;
            if(s=="root"){
                if(v[0]==a){
                    cout<<"T"<<endl;
                    continue;
                }else cout<<"F"<<endl;
            }else if(s=="child"){
                cin>>s;
                int b;cin>>b;
                if(v[(index-1)/2]==b){
                    cout<<"T"<<endl;
                    continue;
                }else cout<<"F"<<endl;
            }else if(s=="parent"){
                cin>>s;
                int b;cin>>b;
                if(v[index*2+1]==b||v[index*2+2]==b){
                    cout<<"T"<<endl;
                    continue;
                }else cout<<"F"<<endl;
            }
        }else{
            int b;cin>>b;
            if(index%2==0){
                if(v[index-1]==b){
                    cout<<"T"<<endl;
                }else cout<<"F"<<endl;
            }else if(v[index+1]==b){
                    cout<<"T"<<endl;
                }else cout<<"F"<<endl;
            cin>>s>>s;
        }
    }
    return 0;
}