#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp"

#include "../../lib/template.cpp"
#include "../../lib/graph/warshall_floyd.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m; cin >> n >> m;
  vector d(n, vector(n, INF));
  REP(i, n) {
    d[i][i] = 0;
  }
  REP(i, m) {
    int a, b, c; cin >> a >> b >> c;
    d[a][b] = c;
  }

  warshall_floyd(d);

  bool negative = false;
  REP(k, n) {
    REP(i, n) {
      REP(j, n) {
        if(d[i][k] == INF || d[k][j] == INF) continue;
        if(d[i][j] > d[i][k] + d[k][j]) {
          negative = true;
          break;
        }
      }
    }
  }
  if(negative) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }

  REP(i, n) {
    REP(j, n) {
      if(d[i][j] == INF) cout << "INF";
      else cout << d[i][j];

      if(j == n-1) cout << endl;
      else cout << " ";
    }
  }
}