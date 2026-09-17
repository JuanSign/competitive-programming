#include <bits/stdc++.h>
using namespace std;

struct Point{
  long long x, y;
  bool operator<(const Point& other) const{
    if(x != other.x) return x < other.x;
    return y < other.y;
  }
  Point operator-(const Point& other) const{
    return {x-other.x, y-other.y};
  }
  long long operator^(const Point& other) const{
    return x*other.y - y*other.x;
  }
};

int get_direction(Point A, Point B, Point C){
  long long cp = (B-A) ^ (C-A);
  if(cp > 0) return 1;
  if(cp < 0) return -1;
  return 0;
}

int main(){
  int n; cin >> n;

  vector<Point> V(n);
  for(Point& p : V) cin >> p.x >> p.y;
  sort(V.begin(), V.end());

  vector<Point> hull;

  for(int i = 0; i < n; i++){
    while(hull.size() >= 2 && get_direction(hull[hull.size()-2], hull.back(), V[i]) < 0){
      hull.pop_back();
    }
    hull.push_back(V[i]);
  }

  size_t t = hull.size()+1;
  for(int i = n-2; i >= 0; i--){
    while(hull.size() >= t && get_direction(hull[hull.size()-2], hull.back(), V[i]) < 0){
      hull.pop_back();
    }
    hull.push_back(V[i]);
  }
  hull.pop_back();

  cout << hull.size() << '\n';
  for(Point p : hull) cout << p.x << " " << p.y << '\n';
}