//DIJKSTRA K SHORTEST PATH FROM SOURCE TO DESTINATION

#include <bits/stdc++.h>
#define MOD                   (int)(1e9+7)
#define SIZE                  (int)(1e5+5)
#define all(x)                x.begin(),x.end()
#define r_all(x)              x.rbegin(),x.rend()
#define lb                    lower_bound
#define ub                    upper_bound
#define pb                    push_back
#define F                     first
#define S                     second
#define IOfast                ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
vector <pair<int,int64_t>> graph[(int)1e5 + 1]; // graph node,edge cost

multiset<int64_t> dist[(int)1e5 + 1]; //to store dist upto k size() for each node

void dikstra(int n,int k)
{
  set<pair<int64_t,int>> s;// cost,value;
  s.insert({0,1});
  dist[1].insert(0);

  while(s.size())
  {
     int64_t value  = (*s.begin()).F;
     int vertex     = (*s.begin()).S;
     int cnt = dist[vertex].count(value);// how many same value dist

     s.erase(s.begin());
     for(auto child:graph[vertex])
     {
        for(int i=1;i<=cnt;i++)
        {
          if(dist[child.F].size() < k)
          {
            dist[child.F].insert(value + child.S);
            s.insert({value + child.S,child.F});
          }
          else
          {
             auto it = dist[child.F].lb(value + child.S);
             if(it == dist[child.F].end()) continue;

             if(dist[child.F].count( *(dist[child.F].rbegin()) ) == 1)
                s.erase({*(dist[child.F].rbegin()),child.F});

            dist[child.F].erase(--dist[child.F].end());

            s.insert({value + child.S, child.F});
            dist[child.F].insert(value + child.S);;
          }
        }
     }
  }

  int done = 0;
  for(auto item:dist[n])
     if(++done > k)
       break;
     else
       cout<<item<<" ";
}

void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  while(m--)
  {
    int u,v,cost;
    cin>>u>>v>>cost;
    graph[u].pb({v,cost});
  }
  dikstra(n,k);
}

int main()
{
  IOfast;
  solve();

  return 0;
}
