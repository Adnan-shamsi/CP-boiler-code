int64_t fact[(int)1e6 + 1]; // storing factorial

void preCalc()  //precalculation for factorial
{
  fact[0] = fact[1] = 1;
  for(int i = 2;i<=1e6;i++)
     fact[i] = (fact[i - 1] * i) % MOD;
}

void solve()
{
  int n , r;
  cin>>n>>r;
  int64_t den = (fact[r] * fact[n - r]) % MOD; // n!/(r!(n-r)!)   , den = denominator , we we can multipy 
  int64_t den_inverse = power(den,MOD-2,MOD); //using Fermat's Little theorem if MOD is prime  
  int64_t nCr = (fact[n] * den_inverse) % MOD;  //since we are applying Modular nCr we have to use modular inverse of denominator
                                              // and multiply it with numerator ;
}
