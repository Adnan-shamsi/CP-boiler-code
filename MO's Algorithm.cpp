//MO's Algorithm 
//time complity 0(q*sqrt(n))
//for Offline queries only
//in all the questions whole code remains same just add and remove function changes
//question link https://cses.fi/problemset/task/1734

#include <bits/stdc++.h>
#define MOD                   (int)(1e9+7)
#define all(x)                x.begin(),x.end()
#define r_all(x)              x.rbegin(),x.rend()
#define lb                    lower_bound
#define ub                    upper_bound
#define pb                    push_back
#define IOfast                ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<int> mp((int)2e5+1);
int distinct;

//query node
struct Node
{
  int l,r ,block_no,query_no;  
  
  bool operator < (Node& q2)
  {
    if(block_no < q2.block_no)  // block no assigning of opening
      return true;
    if(block_no > q2.block_no)
      return false;
    return r < q2.r; // if block number is same then R value  
  }
};



void Add(int num )
{
  int x = ++mp[num];
  if(x == 1) distinct++;
}

void Remove(int num )
{
  int x = --mp[num];
  if(x == 0) distinct--;
}

void adjust(int& curr_l,int& curr_r,int& dest_l,int& dest_r,vector<int>& arr)
{
  while(curr_l < dest_l) //l towards right
  {                      //first removing then moving
     Remove(arr[curr_l]);
     curr_l++;
  }

  while(curr_l > dest_l) //l towards left
  {                      //first moving then adding
     curr_l--;
     Add(arr[curr_l]);
  }

  while(curr_r < dest_r) //r towards right
  {                      //first moving then adding                      
     curr_r++;
     Add(arr[curr_r]);
  }

  while(curr_r > dest_r) //r towards left
  {                      //first removing then moving
    Remove(arr[curr_r]);
    curr_r--;
  }  
}


//MO's algorithm
void MOs(int& n,int& q,vector<int>& arr,vector<Node>& query)
{
  int rn = 600; //smaller value of rn may time out time out sqrt(2e5) = 447 ,it may time out because more block will be created  
  
  //taking query as input
  for(int i=0;i<q;i++)
  {
    int l,r;
    cin>>l>>r;
    query[i].l= --l,query[i].r = --r; //0 based indexing;
    query[i].block_no = l / rn; //assigning block number of opening block 
    query[i].query_no = i; // query number  
  }
   
  sort(all(query)); //sorting query accoring to MO's  
 // for(auto item:query)
   // print(make_pair(item.l,item.r));

  int curr_l = 0 , curr_r = 0;
  mp[arr[0]] = 1; //initializing first node first node
  distinct = 1;
  
  //storing result of each query
  vector<int> result(q); 
  
  for(auto &cur_query:query)
  {
    adjust(curr_l,curr_r,cur_query.l,cur_query.r,arr);
    result[cur_query.query_no] = distinct;
  }  
  
  //at last printing result of all query sequentially
  for(auto &item:result)
    cout<<item<<"\n";

}


void solve()
{
   int n,q;
   cin>>n;
   vector<int> arr(n);
   cin>>q;  
   vector<Node> query(q); 
  
   map<int,int> coordinateCompress;
   int compressed_Num = 1;
 
   for(int i = 0; i < n; i++)
   {
       cin >> arr[i];
       if(coordinateCompress.find(arr[i]) != coordinateCompress.end()){
        arr[i] = coordinateCompress[arr[i]];
       }
       else{
        coordinateCompress[arr[i]] = compressed_Num;
        arr[i] = compressed_Num++;
       }
   }
  
   MOs(n,q,arr,query);     
}

int main()
{
  IOfast;
  
  int q=1;
  //seiveErath(35);
  //cin>>q;
  //memset(dp,-1,sizeof(dp));
  while(q--)
  {
    solve();
  }
  
  return 0;
}
