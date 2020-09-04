#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> 
#define MOD                   (int)(1e9+7)
#define all(x)                x.begin(),x.end()
#define r_all(x)              x.rbegin(),x.rend()
#define lb                    lower_bound
#define ub                    upper_bound
#define pb                    push_back
#define F                     first
#define S                     second
#define cnt_set1(x)           __builtin_popcountll(x)  
#define trailing_0(x)         __builtin_ctz(x)
#define PI                    (double)acos(-1) 
#define prDouble(x)           cout<<fixed<<setprecision(6)<<x;
#define IOfast                ios_base::sync_with_stdio(false); cin.tie(NULL);
#define get_element_by_index(x) find_by_order(x) 
#define get_index(x)            order_of_key(x)
#define debug(x)              cout<<#x<<" = "<<x<<"\n";
#define error(args...)        { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
using namespace __gnu_pbds; 
 
typedef tree<int64_t, null_type,less<int64_t>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
typedef tree<int64_t, null_type, less_equal<int64_t>, rb_tree_tag,tree_order_statistics_node_update> indexed_multiset;
//find_by_order(x) -> returns an iterator to the element at a given position
//order_of_key(x) -> returns the position of a given element
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args){
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
 
///pair cout
template<typename T,typename G> void print(pair<T,G> p){ cout<<"{"<<p.F<<","<<p.S<<"},";  }
///vector cout 
template<typename T> void print(vector <T> v){ for(auto item:v)cout<<item<<" ";cout<<"\n";} 
///set cout
template<typename T> void print(set <T> v){ for(auto item:v)cout<<item<<" ";cout<<"\n";} 
///multiset cout
template<typename T> void print(multiset <T> v){ for(auto item:v)cout<<item<<" ";cout<<"\n";} 
//map cout
template<typename T,typename G> void print(map <T,G> v){ for(auto item:v) cout<<"{"<<item.first<<"=>"<<item.second<<"},"<<" ";cout<<"\n";} 

//with mod
int64_t power(int64_t base,int exp,int64_t mod)
{
    if (exp == 0) return 1;
    if (exp == 1) return base % mod;
    
    int64_t t = power(base, exp / 2,mod) % mod;
    t = (t * t) % mod;
    if (exp % 2 == 0)
     return t;
    else
     return (base * t) % mod;
}
//without mod
int64_t power(int64_t base,int exp)
{
    if (exp == 0) return 1;
    if (exp == 1) return base;
    
    int64_t t = power(base, exp / 2);
    t = (t * t);
    if (exp % 2 == 0)
     return t;
    else
     return (base * t);
}

//void seiveErath(int n)
vector<int> seiveErath(int64_t n)
{
  // if n > 4e5 make prime then make prime and mark global 
  //change the type to void
  vector<int> prime; 
  bool mark[n+1]={0}; //primes as 0 and non primes as 1
  for(int64_t i=2;i<=n;i++)
  {
    if(!mark[i])
    { 
      prime.pb(i);
      int64_t temp=i*i;
      while(temp<=n){ mark[temp] = 1;temp+=i;} 
    }  
  }
  return prime;    
}


//int64_t dp[501][501*(500)/2 + 1];
//int visited[(int)2e5 + 1];
vector <int> graph[(int)2e5 + 1];

//we are creating graph just for tree traversal for level of a node

vector<int> level((int)2e5+1);

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
  int n , boss , q;
  cin>>n>>q;
  for(int i = 2;i<=n;i++)
     cin>>boss , binary_lifter[i][0] = boss , graph[boss].pb(i);
  
  for(int col = 1;col <=19;col++)
    for(int row = 1;row<=n;row++)
       binary_lifter[row][col] = binary_lifter[binary_lifter[row][col-1]][col-1]; 
  
  
  init_levels(1,1);
 
  while(q--)
  {
    int a,b;
    cin>>a>>b;
    cout<<LCA(a,b)<<"\n";
  } 
}

int main()
{
  IOfast;
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
  #endif   

  int q=1;
  //preCalc();
  //seiveErath((int64_t)1e6 + 1);
  //cin>>q;
  //memset(dp,-1,sizeof(dp));
  while(q--)
  {
    solve();
  }
  #ifndef ONLINE_JUDGE
  cout << "\nTimes Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
  #endif  
  
  return 0;
}
