#include<bits/stdc++.h>
using namespace std;

main()
{
    int x;

    while(cin>>x)
    {
        map<string,int> m;
        vector<string> v;

        for(int i=0; i<x; i++)
        {
            string a; cin>>a;
            m[a]++;

            if(m[a]==1) v.push_back("OK");
            else
            {
                v.push_back(a+to_string(m[a]-1));
            }
        }

        for(int i=0; i<v.size(); i++) cout<<v[i]<<endl;
    }

}
