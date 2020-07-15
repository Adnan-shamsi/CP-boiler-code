//PRINTING CYCLES IN GRAPH
//THE CYCLE MUST NOT CONTAIN SELF LOOPS OR MULTIPLE EDGES  
//REMEMBER SOMTIMES IT IS POSSIBLE THAT SOME CYCLE CANT BE DETECTED

#include <bits/stdc++.h>
#define pb     push_back
#define IOfast ios_base::sync_with_stdio(false); cin.tie(NULL);//fast i/o
using namespace std;


int visited[(int)2e5 + 1]; //visited status of a node 
vector <int> graph[(int)2e5 + 1]; // adj list
vector <int> store; //vector used as stack
                    //it keeps track of visited yet unfinished node  


// dfs for cycle finding & printing
void dfs(int node,int par) // node,parent
{
  //pushing node to stack
  store.push_back(node);
  visited[node] = 1; // visited codition 1 means that it has been visited 
                     // but yet not finished 

  int cnt_parent = 0; // it may be possible u->v then u<-v by another edge
                      // hence will reject par only once not twice but if
                      // there's more than 2 occurance of par we will reject it  
  for(auto &item:graph[node]) 
  {
    if(item == par) // if item is par
    { 
      cnt_parent++; 
      if(cnt_parent != 2) // if cnt par is 2 we will traverse else continue
      continue;
    }
    
    if(visited[item] == 1) // checking if that node is in the stack or not
    {                      // if it is 1 it means it is the cycle vertex
      int k = store.size() - 1; //from last
      while(1)
      {
        int curr = store[k--];
        cout<<curr<<" "; // print the vertex of cycle 

        if(curr == item) //it means we have printed all the vertex  
          break;         // and have reached to the starting vertex
      }                  // of the cycle hence breaking the loop
      cout<<"\n";
    }
    if(visited[item] == 0) // if its 0 it has not been visited yet 
      dfs(item,node);      // then do dfs on that node  
  }
  store.pop_back(); //poping out the curr node 
  visited[node] = 2;//visited 2 means its traversal has been completed  
}


int main()
{
    IOfast;
      
    int n,m,u,v;
    cin>>n>>m; // n node ,m edges
    
    while(m--){  
      cin>>u>>v;
      assert(u != v); // no self loop
      graph[v].pb(u), graph[u].pb(v);
    }
    
    cout<<"The cycles are:\n";
    for(int i=1;i<=n;i++)
       if(visited[i] == 0)
          dfs(i,-1); // node and false parent

  return 0;
}
