#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja"

#include "../../lib/template.cpp"
#include "../../lib/graph/dijkstra.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, r; cin >> n >> m >> r;
  vector<vector<P>> g(n);
  REP(i, m) {
    int u, v, c; cin >> u >> v >> c;
    g[u].emplace_back(v, c);
  }

  auto d = dijkstra(r, g);

  REP(i, n) {
    if(d[i] == INF) {
      cout << "INF" << endl;
    } else {
      cout << d[i] << endl;
    }
  }
}