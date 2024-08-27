#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    map<string,int> a;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    string c;
    int i = -1;
    while(s1[++i])
    {
        if(s1[i] == ':')
        {
            if(s1[i-1] == '"')
            {
                int j = 1;
                int sum = 0;
                while(s1[i+j] != ',' && s1[i+j] != '}')
                {
                    sum = sum * 10+ s1[i+j]-48;
                    j++;
                }
                a[s1.substr(i-3,3)] += sum;
            }
            else
            {
                string mm;
                mm += s1[i-1];
                                int j = 1;
                int sum = 0;
                while(s1[i+j] != ',' && s1[i+j] != '}')
                {
                    sum = sum*10+ s1[i+j]-48;
                    j++;
                }
                a[mm] += sum;
            }
        }
    }
    i = -1;
        while(s2[++i])
    {
        if(s2[i] == ':')
        {
            if(s2[i-1] == '"' && s2[i-3] == '"')
            {
                                int j = 1;
                int sum = 0;
                while(s2[i+j] != ',' && s2[i+j] != '}')
                {
                    sum = sum*10 + s2[i+j]-48;
                    j++;
                }
                a[s2.substr(i-3,3)] += sum;
            }
            else
            {
                string mm;
                mm += s2[i-1];
                                                int j = 1;
                int sum = 0;
                while(s2[i+j] != ',' && s2[i+j] != '}')
                {
                    sum = sum*10 + s2[i+j]-48;
                    j++;
                }
                a[mm] += sum;
            }
        }
    }
    map<string, int>::iterator it;
    cout << '{';
    int flag = 0;
    int flag2 = 0;
	for (it = a.begin(); it != a.end(); it++) {
        if((*it).first[0] == '"')
        {
            flag = 1;
            continue;
        }
    flag2 = 1;
    if(it != a.begin() && flag == 0)
        {
            cout << ",";
        }
		cout << (*it).first <<":"<< (*it).second;
        flag = 0;
	}
    flag = 0;
    for (it = a.begin(); it != a.end(); it++)
    {
        if((*it).first[0] != '"')
            continue;
        if(it != a.begin() || flag2 == 1)
            cout << ",";
        cout << (*it).first <<":"<< (*it).second;
        flag = 0;
	}
    cout << "}";
    return 0;
}
