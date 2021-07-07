#include "../template.cpp"
#include "modint.cpp"

// 構築: O(n)
// 計算: O(1)

template <class T>
struct Combination {
  int n;
  vector<T> fact, inv, finv;

  Combination(int n): n(n) {
    fact.resize(n);
    inv.resize(n);
    finv.resize(n);

    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    FOR(i, 2, n) {
      fact[i] = fact[i-1] * i;
      inv[i] = -(inv[MOD%i] * (MOD / i));
      finv[i] = finv[i-1] * inv[i];
    }
  }

  T C(int a, int b) {
    if(a < b || a < 0 || b < 0) return 0;
    return fact[a] * finv[b] * finv[a - b];
  }

  T P(int a, int b) {
    if(a < b || a < 0 || b < 0) return 0;
    return fact[a] * finv[a-b];
  }

  T H(int a, int b) {
    if(a < 0 || b < 0) return 0;
    return C(a + b - 1, b);
  }
};

