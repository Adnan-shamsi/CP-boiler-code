//BELLMAN_FORD 
// time_complexity => 0(VERTEX * EDGE)
//finding -ve cycle
//resource https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html

#include <bits/stdc++.h>
#define all(x)                x.begin(),x.end()
#define F                     first
#define S                     second
#define IOfast                ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// Edge structure
struct Edge
{
  int from,to;
  int64_t cost;
};

void solve()
{
  int n,m;
  //n=>vertex,m=>edges
  cin>>n>>m;
  vector<Edge> edges(m);
  for(auto &e:edges) cin>>e.from>>e.to>>e.cost;
  vector<int> changed_by(n+1,0); //keep track of who changed whom
  vector<int64_t> dist(n+1,LLONG_MAX/100LL);
  //belman_ford
  int x = -1;
  // we are running n times
  // if we are able to relax a edge on nth time it means -ve cycle is there
  // because max n-1 time looping can relax all the nodes in the worst case
  // if on -ve cycle is not there
  for(int i = 1;i<=n;i++)
  {
    x = -1;
    for(auto e:edges)
    {
      if(dist[e.to] > dist[e.from] + e.cost)
      {
        dist[e.to] = dist[e.from] + e.cost;
        changed_by[e.to] = e.from;
        x = e.to;
      }
    }
  }
  if(x == -1) // cycle not found
    cout<<"NO -VE CYCLE IS THERE\n";
  else
  {
    cout<<"YES -VE CYCLE IS PRESENT\n"; //cycle found
    // to print the cycle
    //remeber recurrence may not not give you the cycle
    //so we have to use set and vector
    //for eg for the test case
    //4 5
    //1 2 1
    //2 4 1
    //3 1 1
    //4 1 -3
    //4 3 -2
    //recursive way of cycle finding fails;

    set<int> s;
    vector<int> cycle;
    //cycle finding
    //if a node is already present in set it will contribute to cycle
    //and will be the starting and ending point of cycle
    while(s.find(x) == s.end())
    {
      cycle.push_back(x);
      s.insert(x);
      x = changed_by[x];
    }
    //cycle printing
    cycle.push_back(x);
    cout<<cycle.back()<<" ";
    cycle.pop_back();

    while(cycle.back() != x)
    {
      cout<<cycle.back()<<" ";
      cycle.pop_back();
    }

    cout<<cycle.back()<<" ";
  }
}

int main()
{
  IOfast;
  solve();
  return 0;
}
