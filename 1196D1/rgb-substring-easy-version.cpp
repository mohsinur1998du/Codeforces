#include <bits/stdc++.h>
using namespace std;

string r, g, b;

int lcp(string& s, int k) {
  int mxcnt = 0;
  for (int i = 0; i < s.size() - k + 1; i++) {
    string si = s.substr(i, k);
    int rc = 0, gc = 0, bc = 0;
    for (int j = 0; j < si.size(); j++) {
      if (si[j] == r[j]) rc++;
      if (si[j] == g[j]) gc++;
      if (si[j] == b[j]) bc++;
    }
    mxcnt = max({mxcnt, rc, gc, bc});
  }
  return mxcnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    while (r.size() < s.size()) {
      r += "RGB";
    }
    while (g.size() < s.size()) {
      g += "GBR";
    }
    while (b.size() < s.size()) {
      b += "BRG";
    }
    int cmn = lcp(s, k);
    cout << k - cmn << endl;
  }
  return 0;
}
