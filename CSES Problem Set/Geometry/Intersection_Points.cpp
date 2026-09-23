#include <bits/stdc++.h>
using namespace std;

struct FenwickTree{
  int n;
  vector<int> T;

  FenwickTree(int n): n(n), T(n+1, 0) {}

  void update(int i, int delta){
    for(; i <= n; i += i&-i) T[i] += delta;
  }

  int query(int i){
    int sum = 0;
    for(; i > 0; i -= i&-i) sum += T[i];
    return sum;
  }

  int query(int L, int R){
    return query(R) - query(L-1);
  }
};

struct Segment{
  int x1, y1, x2, y2;

  friend istream& operator>>(istream& in, Segment& s){
    in >> s.x1 >> s.y1 >> s.x2 >> s.y2;
    if(s.x1 > s.x2) swap(s.x1, s.x2);
    if(s.y1 > s.y2) swap(s.y1, s.y2);
    return in;
  }
};

struct Event{
  int type;
  int x, y1, y2;

  bool operator<(const Event& other) const{
    return x < other.x;
  }
};

int main(){
  int n; cin >> n;

  vector<Event> events;
  vector<int> y_cord;
  for(int i = 0; i < n; i++){
    Segment s; cin >> s;
    if(s.y1 == s.y2){
      events.push_back({1, s.x1, s.y1, s.y2});
      events.push_back({2, s.x2, s.y1, s.y2});
      y_cord.push_back(s.y1);
    }else{
      events.push_back({3, s.x1, s.y1, s.y2});
      y_cord.push_back(s.y1);
      y_cord.push_back(s.y2);
    }
  }

  sort(y_cord.begin(), y_cord.end());
  y_cord.erase(unique(y_cord.begin(), y_cord.end()), y_cord.end());
  auto idx = [&](int y){
    return lower_bound(y_cord.begin(), y_cord.end(), y) - y_cord.begin() + 1;
  };

  FenwickTree FT(y_cord.size());
  long long ans = 0;

  sort(events.begin(), events.end());
  for(const Event& e : events){
    if(e.type == 1) FT.update(idx(e.y1), 1);
    else if(e.type == 2) FT.update(idx(e.y1), -1);
    else{
      ans += FT.query(idx(e.y1), idx(e.y2));
    }
  }

  cout << ans << '\n';
}