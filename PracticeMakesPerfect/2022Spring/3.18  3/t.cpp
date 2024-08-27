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
int main()
{
    int n,k;
    cin>>n>>k;
    if(k==5&&n<10)      printf("No\nNo\nNo\nNo\nYes");
    else if(k==5&&n>=10)printf("No\nNo\nNo\nNo\nYes");
    else printf("No\nNo\nNo");
    return 0;
}