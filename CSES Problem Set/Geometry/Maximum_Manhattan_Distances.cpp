#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;

  long long INF = 2e9;
  long long u_min = INF, u_max = -INF;
  long long v_min = INF, v_max = -INF;

  for(int i = 0; i < n; i++){
    long long x, y;
    cin >> x >> y;

    long long u = x + y;
    long long v = x - y;

    u_min = min(u_min, u);
    u_max = max(u_max, u);
    v_min = min(v_min, v);
    v_max = max(v_max, v);

    long long max_dist = max(u_max-u_min, v_max-v_min);
    cout << max_dist << '\n';
  }
}