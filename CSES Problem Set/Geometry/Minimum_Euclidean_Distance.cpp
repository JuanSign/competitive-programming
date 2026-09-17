#include <bits/stdc++.h>
using namespace std;

struct Point{
  long long x, y;
  bool operator<(const Point& other) const{
    if(x != other.x) return x < other.x;
    return y < other.y;
  }
};

long long distance_squared(Point A, Point B){
  long long dx = A.x - B.x;
  long long dy = A.y - B.y;
  return dx*dx + dy*dy;
}

int main(){
  int n; cin >> n;

  vector<Point> V(n);
  for(int i = 0; i < n; i++) cin >> V[i].x >> V[i].y;
  sort(V.begin(), V.end());

  set<pair<long long, long long>> active;

  long long ans = distance_squared(V[0], V[1]);
  active.insert({V[0].y, V[0].x});
  active.insert({V[1].y, V[1].x});
  int left = 0;

  for(int i = 2; i < n; i++){
    while(left < i){
      long long dx = V[i].x - V[left].x;
      if(dx*dx >= ans){
        active.erase({V[left].y, V[left].x});
        left++;
      }else break;
    }

    long long limit_y = sqrt(ans);
    auto low = active.lower_bound({V[i].y - limit_y, LLONG_MIN});
    auto hgh = active.upper_bound({V[i].y + limit_y, LLONG_MAX});

    for(auto it = low; it != hgh; it++){
      ans = min(ans, distance_squared(V[i], {it->second, it->first}));
    }

    active.insert({V[i].y, V[i].x});
  }

  cout << ans << '\n';
}