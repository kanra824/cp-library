#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include "../../lib/template.cpp"
#include "../../lib/data_structure/union_find.cpp"

int main () {
  int n, q; cin >> n >> q;
  UnionFind uf(n);
  REP(i, q) {
    int com, x, y; cin >> com >> x >> y;
    if(com == 0) {
      uf.unite(x, y);
    } else {
      cout << uf.same(x, y) << endl;
    }
  }
}

