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

int main(){
  int T; cin >> T;
  while(T--){
    Point A, B, C;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

    long long cp = (B-A) ^ (C-A);

    if(cp > 0) cout << "LEFT" << '\n';
    else if(cp < 0) cout << "RIGHT" << '\n';
    else cout << "TOUCH" << '\n';
  }
}