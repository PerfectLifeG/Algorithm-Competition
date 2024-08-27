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
    string a;
    cin>>a;
    while (a.find("ACM")!=-1)
    {
        //string b(a,a.find("ACM"),3);
        a.erase(a.find("ACM"),3);
    }
    if(a.empty())cout<<"YES";
    else cout<<"NO";
    
    
    return 0;
}