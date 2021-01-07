#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int n;
int dp[3][100000+5];

int f(vector< pair<int, int> > &v, int occupied, int i, int LSR)
{
    int a = 0, b = 0, c = 0;
    if(i == n-1) return 0;
    if(LSR != -1)
    {
        if(dp[LSR][i] != -1) return dp[LSR][i];
    }

    if(occupied < v[i].first - v[i].second)
    {
        a = dp[1][i] = f(v, v[i].first, i+1, 1) + 1;
    }

    if(v[i].first + v[i].second < v[i+1].first)
    {
        b = dp[2][i] = f(v, v[i].first + v[i].second, i+1, 2) + 1;
    }

    c = dp[0][i] = f(v, v[i].first, i+1, 0);
    return max(a, max(b,c));
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin>>n;
    vector< pair<int, int> > v;
    for(int i=0; i<n; i++){
        int x, h; cin>>x>>h; v.push_back(make_pair(x, h));
    }

    int occupied = ((v[0].second) * (-1)) -1;

    cout<<f(v, occupied, 0, -1) + 1<<endl;

}
