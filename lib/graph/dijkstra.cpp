template <class T>
vector<T> dijkstra(int s, const vector<vector<pair<int,T>>> &g) {
int n = SZ(g);
vector<T> d(n, numeric_limits<T>::max());
priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
d[s] = 0;
pq.push({0, s});
while(!pq.empty()) {
auto [nowd, now] = pq.top(); pq.pop();
if(d[now] < nowd) continue;
for(const auto [nxt, cost]: g[now]) {
bool upd = chmin(d[nxt], nowd + cost);
if(upd) {
pq.push({d[nxt], nxt});
}
}
}
return d;
}
