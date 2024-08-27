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
    int a;
    vector<int>v;int i=0;
    while (scanf("%d",&a)!=EOF)
    {   
        if(i>0&&v.back()==a)break;
        v.push_back(a);
        i++;
    }
    sort(v.begin(),v.end());
    auto it=v.begin();
    printf("从标准设备读入数据，直到输入是非整型数据为止\n");
    for (; it !=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    

    return 0;
}