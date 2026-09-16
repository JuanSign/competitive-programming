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

  long long area = 0;
  for(int i = 0; i < n; i++) area += V[i] ^ V[(i+1)%n];

  cout << abs(area) << '\n';
}