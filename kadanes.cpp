int64_t kadanes(vector<int64_t>& arr)
{
  int64_t mx_global = arr[0];
  int64_t mx = 0;
  for(auto &item:arr)
  {
    mx = max(item,mx + item);
    mx_global = max(mx_global,mx);
  }
  return mx_global;   
}
