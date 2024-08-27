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
struct stu
{
    vector<int>v;
};

int main()
{
    int n;int a,b,k;int flag=1;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        struct stu s[10000];
        struct stu ss[10000];
        cin>>a>>b>>k;
        for (int j = 0; j < k; j++)
        {
            int x,y;
            cin>>x>>y;
            s[x].v.push_back(y);
            ss[y].v.push_back(x);
        }

        vector<int>::iterator it=s[1].v.begin();
        for (; it !=s[1].v.end(); it++)
        {   int a=*it;
            if(*it < 0)break;
            s[1].v.erase(it);
            vector<int>::iterator itt=ss[a].v.begin();
            ss[a].v.erase(itt);
            if(s[1].v.size()&&ss[a].v.size()){
                cout<<"NO"<<endl;flag=0;break;
            }
        }
        
    }
      
    return 0;
}