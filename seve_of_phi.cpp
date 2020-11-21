//source     ->  https://www.youtube.com/watch?v=Fv77-SOTxy8
int phi[(int)1e5 + 1];

void seive_of_phi(int n)
{
  //nlog(logn)
  for(int i=1;i <= n;i++)
     phi[i] = i;

  //phi[n] = n * ((p1-1)/p1) * ((p2-1)/p2) ...

  for(int i = 2 ; i <= n ; i++)
  {
    if(phi[i] == i)  //it is a prime number
    {
      for(int j = i ; j <= n ; j += i)
      {
        phi[j] /= i;
        phi[j] *= (i - 1);
      }
    }
  }
}
