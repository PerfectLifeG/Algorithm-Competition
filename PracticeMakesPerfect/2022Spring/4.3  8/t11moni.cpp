#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
struct time
{
    int start;int end;
};
bool cmp(struct time a,struct time b){
    return a.end<b.end;
}
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int m;cin>>m;
        struct time t[m];
        int cnt=1;
        for (int j = 0; j < m; j++)
        {
            int a,b;
            cin>>a>>b;
            t[j].start=a;t[j].end=b;
        }
        sort(t,t+m,cmp);
        int end=t[0].end;
        for (int j = 1; j < m; j++)
        {
            if(end<=t[j].start)
            {cnt++;
            end=t[j].end;
            }
        }
        cout<<m-cnt<<endl;
    }
    
    return 0;
}