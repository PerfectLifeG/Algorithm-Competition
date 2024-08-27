#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<cmath>
using namespace std;
struct se
{
    set<int>s;
};

int main()
{
    int  n;
    cin>>n;
    struct se st[100];
    map<string,int>m;
    map<string,int>mp;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin>>a;
        m.insert(make_pair(a,i));
        mp.insert(make_pair(a,i));
    }
    int M;
    cin>>M;
    vector<struct se>v;
    
    for (int i = 0; i < M; i++)
    {
        string b,c;
        cin>>b>>c;
        vector<struct se>::iterator it=v.begin();
        if(i==0){st[i].s.insert(m[b]);st[i].s.insert(m[c]);v.push_back(st[i]);
                mp[b]=100;mp[c]=100;
        }
        if(i>0)
        for(;it!=v.end();it++){
            if(it->s.find(m[b])!=it->s.end()){
                it->s.insert(m[c]);
                mp[c]=100;
                break;
            }
            if(it->s.find(m[c])!=it->s.end()){
                it->s.insert(m[b]);
                mp[b]=100;
                break;
            }
        }
        if(it==v.end()){
            st[i].s.insert(m[b]);st[i].s.insert(m[c]);v.push_back(st[i]);
            mp[b]=100;mp[c]=100;
        }
    }
    int school=0;
    map<string,int>::iterator itt=mp.begin();
    for (; itt !=mp.end() ; itt++)
    {
        if(itt->second!=100)
        school++;
    }
    

    vector<struct se>::iterator it=v.begin();
    int num=it->s.size();
    for(;it!=v.end();it++){
        if(num<it->s.size())
        num=it->s.size();
    }
    cout<<v.size()+school<<" "<<num;
    
    
    return 0;
}