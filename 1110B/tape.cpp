#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long ans = n;
  priority_queue<int> pq;
  for (int i = 1; i < n; i++) {
    int diff = b[i] - b[i - 1] + 1;
    pq.push(-diff);
  }
  int used = n;
  while (used > k) {
    int diff = -pq.top(); pq.pop();
    ans = ans - 2 + diff;
    used--;
  }
  cout << ans << endl;
  return 0;
}
