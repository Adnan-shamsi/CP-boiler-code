//REMEMBER ARRSIZE IS NOT GIVEN  

#include <bits/stdc++.h>
#define MOD  (int)(1e9+7)
#define SIZE (int)(1e5+5)
#define ARRSIZE (int)()
#define all(x) x.begin(),x.end()
#define lb     lower_bound
#define ub     upper_bound
#define pb     push_back
#define F      first
#define S      second
#define cnt_set1(x) __builtin_popcountll(x)
#define trailing_0(x) __builtin_ctz(x)
#define PI (double) acos(-1)
#define prDouble(x) cout<<fixed<<setprecision(10)<<x;
#define IOfast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<#x<<" = "<<x<<"\n";

using namespace std;

int changed_by[ARRSIZE];//optional it is used in path printing

//printing path optional
void path(int n)
{
  if( n == 0)
    return;
  path(changed_by[n]);
  cout<<n<<" ";
}

//optional
void show_path_if_any(int n)
{
  if(changed_by[n] == 0)
    cout<<"-1";
  else
    path(n);

}

vector<pair<int64_t,int>> graph[ARRSIZE];   //in pair first value then vertex
vector <int64_t> dist(ARRSIZE ,LLONG_MAX); //init by infinity

void dikstra()
{
  set<pair<int64_t,int>> SET;//value,node

  dist[1]=0;//inserting 0 distance to node 1 as starting is 1

  SET.insert({0,1});//inserting 0 distance to node 1 as starting is 1

  while(SET.size() != 0)
  {
    int64_t value  = (*SET.begin()).F;//getting value
    int vertex = (*SET.begin()).S;//getting vertex

    SET.erase(SET.begin()); //deleting the min distance known node from set

    for(auto &childPair:graph[vertex])
    {
      if( (dist[childPair.S] == LLONG_MAX) || (value+childPair.F < dist[childPair.S]))
      {
        SET.erase({dist[childPair.S],childPair.S});//deleting old data of node and distance

        changed_by[childPair.S] = vertex;//optional

        dist[childPair.S] = value+childPair.F;//editing new min distance to child node

        SET.insert({dist[childPair.S],childPair.S});//inserting new data
      }
    }
  }

}

int main ()
{
  IOfast;

  int n,u,v,value,edge;

  cin>>n>>edge;

  while(edge--)
  {
    cin>>u>>v>>value;
    graph[u].push_back({value,v});
    graph[v].push_back({value,u});
  }

  dikstra();

  show_path_if_any(n); //optional used for path printing

  return 0;
}
