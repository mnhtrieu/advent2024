#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define MOD ((ll)(1e9+7))

#define FILE "demo.in"
//#define FILE "input.in"

void part_1(const string & file);
void part_2(const string & file);
vector<ll> explode(string const & s, char delim);

void part_1(const string & file) {
  ifstream in(file);
  string str;

  vector<pair<ll,ll>> v;

  ll res = 0;
  while(getline(in, str)) {
    if (str == "\n" || str.size() == 0) break;
    auto v2 = explode(str, '|');
    v.PB({v2[0], v2[1]});
  }

  while(getline(in, str)) {
    auto v2 = explode(str, ',');
    bool fail = false;
    FOR(i, 0, v.size()) {
      auto x = find(v2.begin(), v2.end(), v[i].aa);
      auto y = find(v2.begin(), v2.end(), v[i].bb);
      if (x == v2.end() || y == v2.end()) continue;
      if (x > y) { fail = true; break; }
    }
    if (!fail) res += v2[floor(v2.size()/2)];
  }

  cout << "Part 1: " << res << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str;

  vector<pair<ll,ll>> v;

  ll res = 0;
  while(getline(in, str)) {
    if (str == "\n" || str.size() == 0) break;
    auto v2 = explode(str, '|');
    v.PB({v2[0], v2[1]});
  }

  while(getline(in, str)) {
    auto v2 = explode(str, ',');
    bool fail = false;
    FOR(i, 0, v.size()) {
      auto x = find(v2.begin(), v2.end(), v[i].aa);
      auto y = find(v2.begin(), v2.end(), v[i].bb);
      if (x == v2.end() || y == v2.end()) continue;
      if (x > y) { fail = true; iter_swap(x, y); i = 0; }
    }
    if (fail) res += v2[floor(v2.size()/2)];
  }

  cout << "Part 2: " << res << endl;
}

vector<ll> explode(string const & s, char delim) {
    vector<ll> res;
    istringstream iss(s);

    for(string token; getline(iss, token, delim);)
      res.PB(stoi(token));

    return res;
}

int main(int argc, const char ** argv){
  ios::sync_with_stdio(0);cin.tie(0);
  
  string file = FILE;
  if (argc > 1) {
    file = argv[1];
  }

  part_1(file);
  part_2(file);
  return 0;
}
