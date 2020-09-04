//LCA OF TREE OF NODE A , B
//https://cses.fi/problemset/task/1688/ question on this


//we are creating graph just for tree traversal for level of a node
vector <int> graph[(int)2e5 + 1];

//to make levels of a and b same
vector <int> level((int)2e5+1);

//initilizing levels of nodes
void init_levels(int node, int h)
{
  level[node] = h;
  for(auto child:graph[node])
    init_levels(child , h + 1);
}

int binary_lifter[(int)2e5 + 1][20];

int LCA(int a,int b)
{
  //we are assuming b is in lower or on equal part than a
  //if not then swapping a and b
  if(level[a] > level[b]) swap(a,b);
  int d = level[b] - level[a]; 
  
  //lifting b upwards
  for(int i = 20;d;i--)
  {
    if(d >= (1<<i))
    {
      b = binary_lifter[b][i];
      d-=1<<i;
    }
  }

  //if a == b;
  if(a == b )
    return b;
  
  //moving both nodes upwards
  for(int i = 19;i>=0;i--)
  {
    if(binary_lifter[a][i] != binary_lifter[b][i])
      a = binary_lifter[a][i] , b = binary_lifter[b][i];       
  }  
  return binary_lifter[a][0];
}

void solve()
{ 
  int n , parent , q;
  cin>>n>>q;
  for(int i = 2;i<=n;i++)
     cin>>parent , binary_lifter[i][0] = parent , graph[parent].push_back(i);
  
  //creating sparse table 
  for(int col = 1;col <=19;col++)
    for(int row = 1;row<=n;row++)
       binary_lifter[row][col] = binary_lifter[binary_lifter[row][col-1]][col-1]; 
  
  //initializing levels before answering LCA function
  init_levels(1,1);
 
  while(q--)
  {
    int a,b;
    cin>>a>>b;
    cout<<LCA(a,b)<<"\n";
  } 
}
