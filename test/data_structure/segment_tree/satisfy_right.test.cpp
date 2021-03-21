#include "../../../lib/template.cpp"
#include "../../../lib/data_structure/segment_tree.cpp"

const int ma = 200010;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int q; cin >> q;
  SegmentTree<ll> st(
      ma,
      [](ll a, ll b){return a + b;},
      [](ll a, ll b){return a + b;},
      0
      );

  REP(i, q) {
    int t; cin >> t;
    if(t == 1) {
      int x; cin >> x;
      st.update(x, 1);
    } else {
      int x; cin >> x;
      int idx = st.satisfy_left(0, ma, x, [&](int a){if(a < x){x -= a; return false;} else {return true;}});

      int val = st.query(idx, idx+1);
      st.update(idx, -val);

      cout << idx << endl;
    }
  }
}

