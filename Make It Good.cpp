#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;

    for(int T=0; T<t; T++)
    {
        vector<int> v;
        int x; cin>>x;

        for(int i=0; i<x; i++)
        {
            int a; cin>>a;
            v.push_back(a);
        }

        int size = v.size();

        for(int i=size-1; i>=1 && ( v[i-1] >= v[i] ); i--) size--;
            
        for(int i=size-1; i>=1 && ( v[i-1] <= v[i] ); i--) size--;
        
        cout << size-1 << endl;
    }

}
