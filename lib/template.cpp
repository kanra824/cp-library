#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i=0; i<(n); ++i)
#define RREP(i, n) for(int i=(n);i>=0;--i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, b) for(int i=(a);i>=(b);--i)


#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  REP(i, SZ(v)) {
    if (i) os << " ";
    os << v[i];
  }
  return os;
}

template <class T>
void debug(const vector<T> &v) {
  cout << "[";
  REP(i, SZ(v)) {
    if(i) cout << ", ";
    cout << v[i];
  }
  cout << "]" << endl;
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << p.first << " " << p.second;
}

template <class T, class U>
void debug(const pair<T, U> &p) {
  cout << "(" << p.first << " " << p.second << ")" << endl;
}

template<class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const int inf = INT_MIN;
const ll linf = LLONG_MIN;
const ld eps = 1e-9;

/*
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);



  return 0;
}
 */






























