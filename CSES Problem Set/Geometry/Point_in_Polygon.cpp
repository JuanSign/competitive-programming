#include <bits/stdc++.h>
using namespace std;

struct Point{
  long long x, y;
  Point operator-(const Point& other) const{
    return {x-other.x, y-other.y};
  }
  long long operator^(const Point& other) const{
    return x*other.y - y*other.x;
  }
};

bool on_segment(Point A, Point B, Point C){
  if((C-A)^(C-B)) return false;
  bool X_overlap = (C.x >= min(A.x, B.x)) && (C.x <= max(A.x, B.x));
  bool Y_overlap = (C.y >= min(A.y, B.y)) && (C.y <= max(A.y, B.y));
  return X_overlap && Y_overlap;
}

int main(){
  int n, m; cin >> n >> m;

  vector<Point> V(n);
  for(int i = 0; i < n; i++) cin >> V[i].x >> V[i].y;

  for(int q = 0; q < m; q++){
    Point P; cin >> P.x >> P.y;

    bool on_boundary = false;
    int intersections = 0;

    for(int i = 0; i < n; i++){
      Point A = V[i];
      Point B = V[(i+1)%n];

      if((on_boundary = on_segment(A, B, P))) break;

      if((A.y <= P.y && B.y > P.y) && ((B-A) ^ (P-A)) > 0) intersections++;
      else if((B.y <= P.y && A.y > P.y) && ((A-B) ^ (P-B)) > 0) intersections++;
    }

    if(on_boundary) cout << "BOUNDARY" << '\n';
    else if(intersections%2) cout << "INSIDE" << '\n';
    else cout << "OUTSIDE" << '\n';
  }
}