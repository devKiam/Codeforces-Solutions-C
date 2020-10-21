#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
 
    ll t; cin>>t;
 
    while(t--)
    {
        ll n; cin>>n;
 
        vector<ll> v;
        set<ll> s;
 
 
        v.push_back(-1);
 
        for(int i = 1; i<=n; i++)
        {
            ll x; cin>>x;
 
            s.insert(x);
            v.push_back(x);
        }
 
        int m = *max_element(v.begin(), v.end());
        v[0] = m;
        int id = -1;
 
        for( int i=1; i<=v.size(); i++)
        {
            if(v[i]==m)
            {
                if(v[i+1] < v[i] || v[i-1] < v[i])
                {
                    id = i;
                    break;
                }
            }
        }
 
        if(s.size()==1) cout<<"-1"<<endl;
        else{
            cout<<id<<endl;
        }
    }
}
