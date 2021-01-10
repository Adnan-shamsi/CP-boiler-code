//dsu class 1 is the starting

class DSU
{
  public:
  
  vector<int> par; //parent of node 
  int total_comp;  //total component

  void DSU(int n)
  { //index 1 is the starting 
    total_comp = n;
    par.resize(n+1);
    for(int i=1;i<=n;i++) par[i] = i;
  }
  
  int get_super_parent(int x)
  {
    if(par[x] == x) return x;
    else return par[x] = get_super_parent(par[x]); 
  }

  int merge(int x,int y)
  {
    int super_par_x = get_super_parent(x);
    int super_par_y = get_super_parent(y);
    
    if(super_par_x != super_par_y)
    {
      par[super_par_x]=super_par_y;
      total_comp--;
      return 1;
    }
    return 0;
  }
}; 
