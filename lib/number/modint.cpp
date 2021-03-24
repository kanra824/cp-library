template <ll MOD>
struct mint {
  ll val;

  mint(ll val): val(val % MOD) {}

  mint pow(ll x, ll n) {
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

  // !!! MOD must be a prime number
  mint inv() {
    return pow(val, MOD-2);
  }

  mint operator+(const mint &m2) {
    return mint(*this) += m2;
  }

  mint operator-(const mint &m2) {
    return mint(*this) -= m2;
  }

  mint operator*(const mint &m2) {
    return mint(*this) *= m2;
  }

  mint operator/(const mint &m2) {
    return mint(*this) /= m2;
  }

  mint &operator+=(const mint &m2) {
    val += m2.val;
    val %= MOD;
    return *this;
  }

  mint &operator-=(const mint &m2) {
    val += MOD - m2.val;
    val %= MOD;
    return *this;
  }

  mint &operator*=(const mint &m2) {
    val *= m2.val;
    val %= MOD;
    return *this;
  }

  mint &operator/=(const mint &m2) {
    val *= m2.inv();
    val %= MOD;
    return *this;
  }
};
