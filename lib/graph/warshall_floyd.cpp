template<class T>
void warshall_floyd(vector<vector<T>> &d) {
  int sz = SZ(d);
  int now_inf = numeric_limits<T>::max();
  REP(k, sz) {
    REP(i, sz) {
      REP(j, sz) {
        if(d[i][k] != now_inf && d[k][j] != now_inf) {
          chmin(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
  }
}
