#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;
int book[100];
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }
    book[(m - 1)%n] = 1;
    int step = 0;
    int pass = m - 1;
    for (int i = 1; i < n - 1; i++)
    {
        while (step != m)
        {
            pass++;
            pass %= n;
            if (book[pass] == 0)step++;
        }
        book[pass] = 1;
        step = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (book[i] == 0)
        {
            cout << i;
            break;
        }
    }
    return 0;
}