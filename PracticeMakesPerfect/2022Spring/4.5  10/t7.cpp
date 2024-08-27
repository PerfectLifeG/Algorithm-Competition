#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int n;cin>>n;
    
    for (int i = 0; i < n; i++)
    {   vector<string>v;
    map<string,int>mp;
    mp["A"]=0;mp["2"]=0;mp["3"]=0;
    mp["4"]=0;mp["5"]=0;mp["6"]=0;mp["7"]=0;
    mp["8"]=0;mp["9"]=0;mp["10"]=0;mp["J"]=0;
    mp["Q"]=0;mp["K"]=0;
        int m;cin>>m;
        for (int j = 0; j < m; j++)
        {
            string a;
            cin>>a;
            mp[a]++;
        }
        auto it=mp.begin();
        for (;it!=mp.end();it++)
        {
            if(it->second==0)
            v.push_back(it->first);
        }
        if(v.empty())cout<<"HAHA";
        else{
            cout<<v.size();
            if(find(v.begin(),v.end(),"A")!=v.end()){auto it=find(v.begin(),v.end(),"A");v.erase(it++);cout<<" A";}
            if(find(v.begin(),v.end(),"1")!=v.end()){auto it=find(v.begin(),v.end(),"1");v.erase(it++);cout<<" 1";}
            if(find(v.begin(),v.end(),"2")!=v.end()){auto it=find(v.begin(),v.end(),"2");v.erase(it++);cout<<" 2";}
            if(find(v.begin(),v.end(),"3")!=v.end()){auto it=find(v.begin(),v.end(),"3");v.erase(it++);cout<<" 3";}
            if(find(v.begin(),v.end(),"4")!=v.end()){auto it=find(v.begin(),v.end(),"4");v.erase(it++);cout<<" 4";}
            if(find(v.begin(),v.end(),"5")!=v.end()){auto it=find(v.begin(),v.end(),"5");v.erase(it++);cout<<" 5";}
            if(find(v.begin(),v.end(),"6")!=v.end()){auto it=find(v.begin(),v.end(),"6");v.erase(it++);cout<<" 6";}
            if(find(v.begin(),v.end(),"7")!=v.end()){auto it=find(v.begin(),v.end(),"7");v.erase(it++);cout<<" 7";}
            if(find(v.begin(),v.end(),"8")!=v.end()){auto it=find(v.begin(),v.end(),"8");v.erase(it++);cout<<" 8";}
            if(find(v.begin(),v.end(),"9")!=v.end()){auto it=find(v.begin(),v.end(),"9");v.erase(it++);cout<<" 9";}
           if(find(v.begin(),v.end(),"10")!=v.end()){auto it=find(v.begin(),v.end(),"10");v.erase(it++);cout<<" 10";}
            if(find(v.begin(),v.end(),"J")!=v.end()){auto it=find(v.begin(),v.end(),"J");v.erase(it++);cout<<" J";}
            if(find(v.begin(),v.end(),"Q")!=v.end()){auto it=find(v.begin(),v.end(),"Q");v.erase(it++);cout<<" Q";}
            if(find(v.begin(),v.end(),"K")!=v.end()){auto it=find(v.begin(),v.end(),"K");v.erase(it++);cout<<" K";}
        }
        cout<<endl;
    }
    
    
    return 0;
}