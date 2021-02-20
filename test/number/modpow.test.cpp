#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../../lib/number/modpow.cpp"

int main() {
  int m, n; cin >> m >> n;
  int mod = 1000000007;
  cout << modpow(m, n, mod) << endl;
}
