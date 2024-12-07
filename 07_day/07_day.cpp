#include <bits/stdc++.h>
using namespace std;
using ll=uint64_t;
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

bool rec(const ll & sum, const vector<ll> & v, const ll & idx, const ll & tmp) {
  if (idx == (ll) v.size()) return sum == tmp;
  if (tmp > sum) return false;
  return rec(sum, v, idx+1, tmp + v[idx]) || rec(sum, v, idx+1, tmp * v[idx]);
}

bool rec2(const ll & sum, const vector<ll> & v, const ll & idx, const ll & tmp) {
  if (idx == (ll) v.size()) return sum == tmp;
  if (tmp > sum) return false;

  return rec2(sum, v, idx+1, stoll(to_string(tmp) + to_string(v[idx])))
  || rec2(sum, v, idx+1, tmp + v[idx]) 
  || rec2(sum, v, idx+1, tmp * v[idx]);
}

void part_1(const string & file) {
  ifstream in(file);
  string str;

  vector<pair<ll,vector<ll>>> m;

  while(getline(in, str)) {
    ll pos = str.find(":");
    ll x = stoll(str.substr(0, pos));
    auto v = explode(str.substr(pos + 2), ' ');
    m.PB(make_pair(x,v));
  }

  ll res = 0;
  for(auto & [sum, v] : m) {
    if (rec(sum, v, 1, v[0])) res += sum;
  }

  cout << "Part 1: " << res << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str;

  vector<pair<ll,vector<ll>>> m;

  while(getline(in, str)) {
    ll pos = str.find(":");
    ll x = stoll(str.substr(0, pos));
    auto v = explode(str.substr(pos + 2), ' ');
    m.PB(make_pair(x,v));
  }

  ll res = 0;
  for(auto & [sum, v] : m) {
    if (rec2(sum, v, 1, v[0])) res += sum;
  }

  cout << "Part 2: " << res << endl;
}

vector<ll> explode(string const & s, char delim) {
    vector<ll> res;
    istringstream iss(s);

    for(string token; getline(iss, token, delim);)
      res.PB(stoll(token));

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
