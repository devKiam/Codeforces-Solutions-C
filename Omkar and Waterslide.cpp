#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
       int n; cin>>n;
       vector<int> v;
       for(int i=0; i<n; i++)
       {
           int x; cin>>x;
           v.push_back(x);
       }

       ll need = 0;
       for(int i=1; i<v.size(); i++)
       {
           if(v[i-1]>v[i]) need += v[i-1]-v[i];
       }
        
       cout<<need<<"\n";
    }
}
