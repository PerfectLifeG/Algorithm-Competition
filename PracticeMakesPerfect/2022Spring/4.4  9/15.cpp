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
    for (int j = 1; j < 100; j++)
    {
        cout<<log2(j&-j)+1<<" ";
    }
    
            
    
    return 0;
}
