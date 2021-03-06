#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <utility>
#include <vector>
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rep(i, a) loop(i, 0, a)
#define FOR(i, a) for (auto i : a)
#define pb push_back
#define all(in) in.begin(), in.end()
#define shosu(x) fixed << setprecision(x)
#define show1d(v)                                                              \
  rep(i, v.size()) cout << " " << v[i];                                        \
  cout << endl << endl;
#define show2d(v)                                                              \
  rep(i, v.size()) {                                                           \
    rep(j, v[i].size()) cout << " " << v[i][j];                                \
    cout << endl;                                                              \
  }                                                                            \
  cout << endl;
using namespace std;
typedef long long ll;
typedef int Def;
typedef pair<Def, Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def, pii> pip;
typedef vector<pip> vip;
template <typename A, typename B> bool cmin(A &a, const B &b) {
  return a > b ? (a = b, true) : false;
}
template <typename A, typename B> bool cmax(A &a, const B &b) {
  return a < b ? (a = b, true) : false;
}
const double PI = acos(-1);
const double EPS = 1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9 + 10;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int main(int argc, char *argv[]) {
  int x, a, b;
  char s[100];
  stack<int> st;

  while (scanf("%s", s) != EOF) {
    if (s[0] == '+') {
      b = st.top();
      st.pop();
      a = st.top();
      st.pop();
      st.push(a + b);
    } else if (s[0] == '-') {
      b = st.top();
      st.pop();
      a = st.top();
      st.pop();
      st.push(a - b);
    } else if (s[0] == '*') {
      b = st.top();
      st.pop();
      a = st.top();
      st.pop();
      st.push(a * b);
    } else {
      x = atoi(s);
      st.push(x);
    }
  }
  cout << st.top() << endl;
  return 0;
}
