#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> 
#define MOD  (int)(1e9+7)
#define SIZE (int)(1e5+5)
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
#define get_element_by_key(x) find_by_order(x) 
#define get_key(x)   order_of_key(x)
#define debug(x) cout<<#x<<" = "<<x<<"\n";
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
using namespace __gnu_pbds; 
//less_int<int>

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
template<typename T,typename G> print(pair<T,G> p){ cout<<"{"<<p.F<<","<<p.S<<"},";  }
///vector cout 
template<typename T> print(vector <T> v){ for(auto item:v)cout<<item<<" ";cout<<"\n";} 
///set cout
template<typename T> print(set <T> v){ for(auto item:v)cout<<item<<" ";cout<<"\n";} 
///multiset cout
template<typename T> print(multiset <T> v){ for(auto item:v)cout<<item<<" ";cout<<"\n";} 
//map cout
template<typename T,typename G> print(map <T,G> v){ for(auto item:v) cout<<"{"<<item.first<<"=>"<<item.second<<"},"<<" ";cout<<"\n";} 

//dsu struct 1 is the starting
struct dsu_struct
{
  vector<int> par;
  int total_comp;

  void init(int n)
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

  void merge(int x,int y)
  {
    int super_par_x = get_super_parent(x);
    int super_par_y = get_super_parent(y);
    
    if(super_par_x != super_par_y)
    {
      par[super_par_x]=super_par_y;
      total_comp--;
    }
  }
}; 

int64_t power(int64_t base,int exp)
{
    if (exp == 0) return 1;
    if (exp == 1) return base;
    
    int64_t t = power(base, exp / 2);
    t = (t * t);
    if (exp % 2 == 0)
     return t;
    else
     return base * t;
}

//void seiveErath(int n)
vector<int64_t> seiveErath(int n)
{
  vector<int64_t> prime;
  int mark[n+1]={0};
  for(int i=2;i<=n;i++)
  {
    if(!mark[i])
    { 
      prime.pb(i);
      int temp=2*i;
      while(temp<=n){ mark[temp] = 1;temp+=i;} 
    }  
  }
  return prime;    
}

//int64_t dp[(int)4e8];
//int visited[(int)2e5 + 1];
//vector <int> graph[(int)2e5 + 1];

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

  }
  #ifndef ONLINE_JUDGE
  cout << "\nTimes Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
  #endif  
  
  return 0;
}