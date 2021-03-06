#include <algorithm>
#include <bitset>
#include <complex>
#include <cstdio>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif

template <typename A, typename B> bool cmin(A &a, const B &b) {
  return a > b ? (a = b, true) : false;
}
template <typename A, typename B> bool cmax(A &a, const B &b) {
  return a < b ? (a = b, true) : false;
}
const double PI = acos(-1);
const double EPS = 1e-9;
int inf = sizeof(int) == sizeof(long long) ? 2e18 : 1e9 + 10;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define MAX 100005
#define NIL -1


struct Node { int parent, left, right; };

Node T[MAX];
int N, D[MAX], H[MAX];

void setDepth(int u, int d) {
  if (u == NIL) return;
  D[u] = d;
  setDepth(T[u].left, d + 1);
  setDepth(T[u].right, d + 1);
}

int setHeight(int u) {
  int h1 = 0, h2 = 0;
  if (T[u].left != NIL) h1 = setHeight(T[u].left) + 1;
  if (T[u].right != NIL) h2 = setHeight(T[u].right) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u) {
  if (T[u].parent == NIL) return NIL;
  if (T[T[u].parent].left != u && T[T[u].parent].left != NIL) return T[T[u].parent].left;
  if (T[T[u].parent].right != u && T[T[u].parent].right != NIL) return T[T[u].parent].right;
  return NIL;
}

void printf(int u) {
  cout << "node " << u << ": " << "parent = " << T[u].parent << ", sibling = " << getSibling(u);
  int deg = 0;
  if (T[u].left != NIL) deg++;
  if (T[u].right != NIL) deg++;
  cout << ", degree = " << deg << ", depth = " << D[u] << ", height = " << H[u];

  if (T[u].parent == NIL) {
    cout << ", root";
  } else if (T[u].left == NIL && T[u].right == NIL) {
    cout << ", leaf";
  } else {
    cout << ", internal node";
  }
  cout << endl;
}

int main()
{
  int V, L, R, root = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) T[i].parent = NIL;

  for (int i = 0; i < N; ++i) {
    cin >> V >> L >> R;
    T[V].left = L;
    T[V].right = R;
    if (L != NIL) T[L].parent = V;
    if (R != NIL) T[R].parent = V;
  }

  for (int i = 0; i < N; ++i) if (T[i].parent == NIL) root = i;

  setDepth(root, 0);
  setHeight(root);

  for (int i = 0; i < N; ++i) printf(i);
  return 0;
}
