#include "../template.cpp"

ll modpow(ll x, ll n, ll m) {
  ll res = 1;
  while(n > 0) {
    if(n&1) {
      res *= x;
      res %= m;
    }
    x *= x;
    x %= m;
    n >>= 1;
  }
  return res;
}
