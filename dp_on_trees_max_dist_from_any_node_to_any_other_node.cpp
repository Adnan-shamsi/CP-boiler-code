vector <int> graph[(int)2e5 + 1];

//in array is for subgraph , whereas out is for parent  
int in[(int)2e5 + 1] , out[(int)2e5 + 1];

//in array construction
//for lower sub tree
//building upwards
void dfs1(int node , int par)
{
  //initializing in[node] by zero 
  in[node] = 0;
  for(auto child:graph[node])
  {
    if(child == par)
      continue;
    dfs1(child, node);
    in[node] = max(in[node] , 1 + in[child]);   
  }  
}

//out array construction
//out can be by any one either branch of parent or parent of parent

void dfs2(int node , int par)
{
  //we have to initialize by -1 not zero because below we are adding 1 to mxs , 
  //hence -1 nullifies the effect  
  
  //we are taking mx1 , mx2 because maximum of branches of parnent 
  //we need 2 mxs because it may be the case that in of parent has been constructed by than subtree only
  //hence at that time we need mx2
  int mx1 = -1 , mx2 = -1;
  
  //rectifying values of mx1 , mx2
  for(int child:graph[node])
  {
    if(child == par)
      continue;
    
    //if mx1 , mx2
    //editing mxs values
    if(in[child] >= mx1)
    {
      mx2 = mx1;
      mx1 = in[child]; 
    }
    else if(in[child] > mx2)
      mx2 = in[child];   
  }
  
  //initializing out value of child before going into it
  for(int child:graph[node])
  {
    if(child == par)
      continue;
    int longest = mx1;

    //we have to neglect the effect if it is from the same subtree
    if(in[child] == mx1)
      longest = mx2;
    //1 + longest is because we have to move from branch to parent whose value we have taken
    //1 + max(..) is because from parent of current child we are moving to current child 
    out[child] = 1 + max(out[node] , 1 + longest);
    
   //since we have initialize out[child] we can go to current child itself 
    dfs2(child , node); 
  }
}

void solve()
{
  //n->tree nodes
  int n;
  cin>>n;
  //m->edges
  int m = n-1;
  
  //taking edges
  while(m--)
  {
    int u , v;
    cin>>u>>v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
  
  //in array construction 
  dfs1(1 , 0);

  //out array construction
  dfs2(1 , 0); 
  
 //since we have calculated in and out array correctly we can get max in 0(1); 
 
  //max_distance from any node to any other node  
  for(int i = 1;i<=n;i++)
     cout<<max(in[i] , out[i])<<" ";
}

int main()
{
  solve();
  
  return 0;
}
