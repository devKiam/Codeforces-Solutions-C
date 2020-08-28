//
// Created by Kiam on 25-Aug-20.
// R = 0; C = 1; G = 2;
 
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
vector<int> v;
int n;
ll dp[105][10];
 
int f(int s, int i)
{
    int val = 0;
 
    if(dp[i][s]!=-1) return dp[i][s];
 
    if(i==n)
    {
        return dp[i][s] = 0;
    }
 
    if(v[i]==0)
    {
        return dp[i][s] = val = max(val, f(0, i+1));
    }
    if(v[i]==1)
    {
        if(s!=1)
        {
            return dp[i][s] = val = max(val, max(f(1, i+1)+1, f(0, i+1)));
        }
        else
            return dp[i][s] = val = max(val, f(0, i+1));
    }
    if(v[i]==2)
    {
        if(s!=2)
        {
            return dp[i][s] = val = max(val, max(f(2, i+1)+1, f(0, i+1)));
        }
        else
            return dp[i][s] = val = max(val, f(0, i+1));
    }
    if(v[i]==3)
    {
        if(s==2)
        {
            return dp[i][s] = val = max(val, max(f(1, i+1)+1,f(0, i+1)));
        }
        else if(s==1)
        {
            return dp[i][s] = val = max(val, max(f(2, i+1)+1, f(0, i+1)));
        }
        else
            return dp[i][s] = val = max(val, max(f(0, i+1), max(f(1, i+1)+1,f(2, i+1)+1)));
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
 
    cin>>n;
 
    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        v.push_back(x);
    }
    cout<<n-f(4, 0)<<"\n";
 
}
