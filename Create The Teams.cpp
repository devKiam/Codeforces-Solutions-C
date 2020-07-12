#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;

    for(int j=0; j<n; j++)
    {
        int x, y; cin>>x>>y;
        vector<int> v;

        for(int i=0; i<x; i++)
        {
            int vInput; cin>>vInput;
            v.push_back(vInput);
        }

        sort(v.begin(), v.end());

        int count=0, man=1;

        for(int i=v.size()-1; i>=0;   i--)
        {
            if(v[i]*man >= y)
            {
                count++;
                man=1;
            }
            else{
                man++;
            }
        }

        cout<<count<<endl;
    }
}
