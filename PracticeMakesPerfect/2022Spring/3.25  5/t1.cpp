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
int cmp(int a,int b){
    return a<b;
}
int main()
{
    int n,k;int s=0;
    scanf("%d %d",&n,&k);
    vector<string>v;map<string,int>m;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin>>a;
        v.push_back(a);
        m[a]++;
    }
    
    for (auto i=m.begin();i!=m.end();){
        if(i->second==1)m.erase(i++);
        else ++i;
    }

    vector<string>::iterator it=v.begin();
    vector<string>::iterator itt=v.begin()+1;
        
    for (;it!=v.end()-1; it++)
    {
        if(m.count(*it)==0)continue;
        itt=it+1;
        for (;itt-it<=k+1; itt++)
        {
            if(*itt==*it)s++;
        }
    }
    
    printf("%d",s);
    return 0;
}