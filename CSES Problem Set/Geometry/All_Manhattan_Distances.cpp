#include <bits/stdc++.h>
using namespace std;

void print128(__int128_t n) {
  if(n < 0){
    cout << '-';
    n = -n;
  }
  if(n > 9) print128(n/10);
  cout << (char)(n%10 + '0');
}

int main(){
  int n; cin >> n;

  vector<long long> X(n), Y(n);
  for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  __int128_t ans = 0;
  for(int i = 0; i < n; i++){
    ans += (X[i]*(2LL*i - n + 1));
    ans += (Y[i]*(2LL*i - n + 1));
  }

  print128(ans);
}