//KOSARAJU'S ALGORITHM

// THERE ARE THREE STEPS IN THIS ALGORITHM
// FIRST DO TOPOLOGICAL SORTING BY DFS
// THEN CREATE TRANSPOSE GRAPH
// THEN DO DFS AGAIN ON TRANSPOSED GRAPH USING TOPOLOGICALLY SORTED STACK 
// AND NOT BY FOR(INT I=1;I<=N;I++) LOOP

#include <bits/stdc++.h>
#define pb     push_back
#define IOfast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int visited[(int)3e5 + 1];
//graph
vector <int> graph[(int)3e5 + 1];
//transpose of a graph
vector <int> trans_graph[(int)3e5 + 1];

//stack to put all items in topological sorted order
stack <int> stck;

//first time dfs to get stck
//topological sorting
void dfs0(int node)
{
  visited[node] = 1;
  for(auto &item:graph[node])
    if(visited[item] == 0)
      dfs0(item);
  //putting node to stack after all its child have finished dfs
  stck.push(node);  
}

//doing dfs second time to find scc for curr node
void dfs1(int node)
{
  visited[node] = 1;  
  for(auto &item:trans_graph[node])
    if(visited[item] == 0)
      dfs1(item);
}

int main()
{
  IOfast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
  #endif   
  
  int q=1;
  //seiveErath((int)2e7);
  //cin>>q;
  //memset(dp,-1,sizeof(dp));

  while(q--)
  {
    int n,m,u,v;
    //node
    cin>>n;
    //edge
    cin>>m;
    
    while(m--)
    {
      cin>>u>>v;
      //direction u -> v
      graph[u].pb(v);
      //direction v -> u
      trans_graph[v].pb(u);
    }

    for(int i=1;i<=n;i++)
       if(visited[i] == 0)
         dfs0(i);
    //clearing visited array 
    memset(visited,0,sizeof(visited));
    // strongly connected component
    int scc=0;

    while(stck.size())
    {
      //get the top most element from stack
      int curr = stck.top();
      stck.pop(); 
      
      if(visited[curr] == 0){
        //incrementing scc
        scc++;
        dfs1(curr);      
      }
    }
    cout<<"there are "<<scc<<" strongly connected components";
  }
  return 0;
}
