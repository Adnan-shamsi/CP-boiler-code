class Fenwick{
 vector<int64_t> arr;
 public:
  
  Fenwick(int sz){
    arr.resize(sz + 10);
  }
  
  void update(int idx,int64_t val){
    for(int i=idx;i<arr.size();i += i&-i) 
      arr[i] += val; 
  } 
  
  int64_t query(int idx){
    int64_t ans=0;
    idx = min((int)arr.size(), idx);
    
    while(idx){
      ans += arr[idx];
      idx -= idx & -idx;
    }

    return ans; 
  }

};
