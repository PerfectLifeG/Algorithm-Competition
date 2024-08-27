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
    int a[1000000];
    int main()
    {
        int  n,q;int s=0;
        cin>>n>>q;
        
        for (int i = 1; i <= n; i++)
        {
            cin>>a[i];
        }
        for (int i = 0; i < q; i++)
        {
            int aa,b,c;
            cin>>aa>>b>>c;
            if(aa==1)a[b]+=c;
            if(aa==2){
                for (int j = b; j <= c; j++)
                {
                    s+=a[j];
                }
                
                cout<<s<<endl;
            }
        }
        
        
        return 0;
    }