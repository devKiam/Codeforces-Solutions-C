#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll dirRow[] = {-1, 1, 0, 0, -1, 1, -1, 1};
ll dirCol[] = {0, 0, 1, -1, -1, 1, 1, -1};


ll bfs(map< pair<ll, ll>, ll > &availableGrids, map< pair<ll, ll>, ll > &distance, ll startRow, ll startColumn, ll destinationRow, ll destinationColumn)
{
    queue<ll> rowQ, columnQ;
    rowQ.push(startRow); columnQ.push(startColumn);
    distance[{startRow, startColumn}] = 1;

    while(!rowQ.empty())
    {
        ll r = rowQ.front(), c = columnQ.front();
        rowQ.pop(); columnQ.pop();
        for(int i=0; i<8; i++)
        {
            if(r + dirRow[i] >= 10e9 + 1 || r + dirRow[i] <= 0 || c + dirCol[i] >= 10e9 + 1 || c + dirCol[i] <= 0) continue;
            if(distance[{r + dirRow[i], c + dirCol[i]}] == 0 && availableGrids[{r + dirRow[i], c + dirCol[i]}] == 1)
            {
                distance[{r + dirRow[i], c + dirCol[i]}] = distance[{r, c}] + 1;
                rowQ.push(r + dirRow[i]); columnQ.push(c + dirCol[i]);
            }
            if(distance[{destinationRow, destinationColumn}] != 0) return distance[{destinationRow, destinationColumn}] - 1;
        }
    }
    return -1;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    ll startRow, startColumn, destinationRow, destinationColumn, n; cin>>startRow>>startColumn>>destinationRow>>destinationColumn>>n;
    map< pair<ll, ll>, ll > availableGrids;
    map< pair<ll, ll>, ll > distance;
    while(n--)
    {
        ll row, from, to; cin>>row>>from>>to;
        for(ll i=from; i<=to; i++){
            availableGrids[{row, i}] = 1;
        }
    }
    cout<<bfs(availableGrids, distance, startRow, startColumn, destinationRow, destinationColumn)<<endl;

}
