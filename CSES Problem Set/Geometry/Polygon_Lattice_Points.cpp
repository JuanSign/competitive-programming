#include <bits/stdc++.h>
using namespace std;

struct Point{
  long long x, y;
  long long operator^(const Point& other) const{
    return x*other.y - y*other.x;
  }
};

int main(){
  int n; cin >> n;

  vector<Point> V(n);
  for(int i = 0; i < n; i++) cin >> V[i].x >> V[i].y;

  long long double_area = 0;
  long long boundary = 0;

  for(int i = 0; i < n; i++){
    Point A = V[i];
    Point B = V[(i+1)%n];

    double_area += A^B;

    long long dx = abs(A.x-B.x);
    long long dy = abs(A.y-B.y);
    boundary += gcd(dx, dy);
  }

  double_area = abs(double_area);

  long long inside = (double_area - boundary + 2)/2;

  cout << inside << " " << boundary << '\n';
}