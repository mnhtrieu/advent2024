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

  vector<ll> a, b;

  ll x = 0, y = 0;
  while(in >> x >> y) {
    a.PB(x);
    b.PB(y);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll res = 0;
  F(a.size()) {
    res += abs(a[i] - b[i]);
  }

  cout << "Part 1: " << res << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str;

  vector<ll> a, b;
  ll x = 0, y = 0;
  while(in >> x >> y) {
    a.PB(x);
    b.PB(y);
  }

  sort(b.begin(), b.end());

  ll res = 0;
  for(auto & i: a) {
    ll dist = upper_bound(b.begin(), b.end(), i) - lower_bound(b.begin(), b.end(), i);
    res += dist * i;
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
