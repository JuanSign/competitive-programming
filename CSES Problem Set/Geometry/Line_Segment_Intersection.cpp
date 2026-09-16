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

int check_direction(Point A, Point B, Point C){
  long long cp = (B-A) ^ (C-A);
  if(cp > 0) return 1;
  if(cp < 0) return -1;
  else return 0;
}

bool on_segment(Point A, Point B, Point C){
  bool X_overlap = (C.x >= min(A.x, B.x)) && (C.x <= max(A.x, B.x));
  bool Y_overlap = (C.y >= min(A.y, B.y)) && (C.y <= max(A.y, B.y));
  return X_overlap && Y_overlap;
}

bool intersect(Point A, Point B, Point C, Point D){
  int d1 = check_direction(A, B, C);
  int d2 = check_direction(A, B, D);
  int d3 = check_direction(C, D, A);
  int d4 = check_direction(C, D, B);

  if(d1 != d2 && d3 != d4) return true;

  if(d1 == 0 && on_segment(A, B, C)) return true;
  if(d2 == 0 && on_segment(A, B, D)) return true;
  if(d3 == 0 && on_segment(C, D, A)) return true;
  if(d4 == 0 && on_segment(C, D, B)) return true;

  return false;
}

int main(){
  int T; cin >> T;
  while(T--){
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;

    if(intersect(A, B, C, D)) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}