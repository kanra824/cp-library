// のしさんのブログを参考にした(2021/03/28): https://noshi91.hatenablog.com/entry/2019/03/31/174006

template <ll MOD>
struct mint {
  ll val;

  mint(ll val): val(val % MOD) {}

  inline mint pow(ll x, ll n) {
    mint res(1);
    while(n > 0) {
      if(n & 1) {
        res *= x;
      }
      x *= x;
      n >>= 1;
    }
    return mint(res);
  }

  ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    ll q = a / b;
    ll g = ext_gcd(b, a-q*b, x, y);
    ll z = x - q * y;
    x = y;
    y = z;
    return g;
  }

  inline mint inv() {
    ll x, y;
    ext_gcd(val, m, x, y);
    x %= m;
    if(x < 0) x += m;
    return Int(x);
  }

  constexpr mint operator+(const mint &m2) {
    return mint(*this) += m2;
  }

  constexpr mint operator-(const mint &m2) {
    return mint(*this) -= m2;
  }

  constexpr mint operator*(const mint &m2) {
    return mint(*this) *= m2;
  }

  constexpr mint operator/(const mint &m2) {
    return mint(*this) /= m2;
  }

  constexpr mint &operator+=(const mint &m2) {
    val += m2.val;
    val %= MOD;
    return *this;
  }

  constexpr mint &operator-=(const mint &m2) {
    val += MOD - m2.val;
    val %= MOD;
    return *this;
  }

  constexpr mint &operator*=(const mint &m2) {
    val *= m2.val;
    val %= MOD;
    return *this;
  }

  constexpr mint &operator/=(const mint &m2) {
    val *= m2.inv();
    val %= MOD;
    return *this;
  }
};
