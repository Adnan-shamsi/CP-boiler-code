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

int in[(int)2e5 + 1] , out[(int)2e5 + 1];

//in array construction
void dfs1(int node , int par)
{
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
void dfs2(int node , int par)
{
  //we have to initialize by -1 not zero because below we are adding 1 to mxs , 
  //hence -1 nullifies the effect  
  int mx1 = -1 , mx2 = -1;
  
  for(int child:graph[node])
  {
    if(child == par)
      continue;
    if(in[child] >= mx1)
    {
      mx2 = mx1;
      mx1 = in[child]; 
    }
    else if(in[child] > mx2)
      mx2 = in[child];   
  }

  for(int child:graph[node])
  {
    if(child == par)
      continue;
    int longest = mx1;

    //we have to neglect the effect if it is from the same subtree
    if(in[child] == mx1)
      longest = mx2;

    out[child] = 1 + max(out[node] ,1 + longest);
    dfs2(child , node); 
  }
}

void solve()
{
  int n;
  cin>>n;
  int m = n-1;
  
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
  
  for(int i = 1;i<=n;i++)
     cout<<max(in[i] , out[i])<<" ";
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
