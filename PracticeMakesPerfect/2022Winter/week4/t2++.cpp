#include<iostream>
#include<cstring>
#include<cmath>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
string solve(int n) {
    string str1;
    if (n == 0) str1 = "0";
    while (n) {
        int tmp = n % 10;
        str1 += tmp + '0';
        n /= 10;
    }

    reverse(str1.begin(), str1.end());
    return str1;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string str;
    for (int i = 0; i <= n; i++) {
        str += solve(i);
    }
    ll len=str.length();
    ll tmp=0;
    for (int i = a; i <= b; i++){
        if (str[i]==c+'0') tmp++;
    }
    cout<<len<<" "<<tmp<<endl;
}
