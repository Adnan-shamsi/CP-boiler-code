//merging intervals
//I have used set because deletion takes O(logn) 
//eg [{1,3}{2,5}{8,8}] before merging
//   [{1,5}{8,8}] after merging 
// you can use this to solve https://www.hackerrank.com/challenges/gridland-metro/problem

void merging_intervals(set<pair<int,int>>& s)
{
  set<pair<int,int>> new_set; //new set that will contain the merged intervals 
  pair<int,int> prev = {0,0},beg; 
  
  while(s.size())
  {  
    beg = *s.begin();  
    //we can merge only if ending of prev is greater than or equal to that starting of that element   
    if(prev.S >= beg.F )
    { 
      //erasing old interval
      new_set.erase(prev);
      
      //extending new merged interval
      prev = { min(prev.F,beg.F),max(prev.S,beg.S)};
      //inserting new merged interval
      new_set.insert(prev);
    }
    else
    {
      prev = beg;
      new_set.insert(prev);
    }
    //erasing the begining as its work has been completed 
    s.erase(s.begin()); 
  }
  //copying new mnerged intervals
  s = new_set;   
}
