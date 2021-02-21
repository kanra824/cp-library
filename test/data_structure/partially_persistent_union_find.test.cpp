#include "../../lib/data_structure/partially_persistent_union_find.cpp"
#include "../../lib/template.cpp"

int main() {
  int n, m; cin >> n >> m;
  PartiallyPersistentUnionFind ppuf(n);
  REP(i, m) {
    int a, b; cin >> a >> b;
    a--; b--;
    ppuf.unite(a, b);
  }

  int q; cin >> q;
  REP(i, q) {
    int x, y, z; cin >> x >> y >> z;
    x--, y--;
    int l = -1, r = m;
    while(r - l > 1) {
      int mid = (l + r) / 2;
      if(ppuf.same(mid, x, y)) {
        int sz = ppuf.size(mid, x);
        if(sz >= z) {
          r = mid;
        } else {
          l = mid;
        }
      } else {
        int szx = ppuf.size(mid, x);
        int szy = ppuf.size(mid, y);
        if(szx + szy >= z) {
          r = mid;
        } else {
          l = mid;
        }
      }
    }
    cout << r << endl;
  }


}

