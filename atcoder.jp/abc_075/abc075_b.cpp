// abc075_b
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_map>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define FOR(i,a) for(auto i:a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
#define show1d(v) rep(i,v.size())cout<<" "<<v[i];cout<<endl<<endl;
#define show2d(v) rep(i,v.size()){rep(j,v[i].size())cout<<" "<<v[i][j];cout<<endl;}cout<<endl;
using namespace std;
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
int main(int argc, char *argv[])
{
  int h,w,cnt;
  cin>>h>>w;
  vector<string> s(h);
  rep(i,h){
    cin>>s.at(i);
  }
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      if(s.at(i)[j]=='#') {
        continue;
      } else {
        cnt=0;
        rep(k,8){
          if (j+dx[k]<0||j+dx[k]>=w) continue;
          if (i+dy[k]<0||i+dy[k]>=h) continue;
          if(s.at(i+dy[k])[j+dx[k]]=='#') cnt++;
        }
        s.at(i)[j]=char(cnt+'0');
      }
    }
  }
  rep(i,h)
    cout<<s.at(i)<<endl;
  return 0;
}
