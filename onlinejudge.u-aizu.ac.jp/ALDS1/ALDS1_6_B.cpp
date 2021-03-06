#include <algorithm>
#include <bitset>
#include <complex>
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

#define MAX 100000

int N, A[MAX];

int partition(int p, int r) {
  int x, i, j, t;
  x = A[r];
  i = p - 1;
  for (j = p; j < r; ++j) {
    if (A[j] <= x) {
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }

  t = A[i + 1];
  A[i + 1] = A[r];
  A[r] = t;
  return i + 1;
}

int main() {

  cin >> N;
  rep(i, N) cin >> A[i];

  int q = partition(0, N - 1);

  for (int i = 0; i < N; ++i) {
    if (i) cout<<" ";
    if (i == q) cout<<"[";
    cout<<A[i];
    if (i == q) cout<<"]";
  }
  cout<<endl;
  return 0;
}
