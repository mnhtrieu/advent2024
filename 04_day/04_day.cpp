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

bool rec(const vector<string> & m, ll x, ll y, ll len, const pair<ll,ll> & way, const string & needle) {
  if (len == (ll)needle.size()) { return true; }
  if (y < 0 || y >= (ll)m.size() || x < 0 || x >= (ll)m[0].size()) { return false; }
  if (m[y][x] != needle[len]) { return false; }
  return rec(m, x + way.aa, y + way.bb, len+1, way, needle);
}

void part_1(const string & file) {
  ifstream in(file);
  string str;

  vector<string> m;

  while(getline(in, str)) {
    m.PB(str);
  }

  ll cnt = 0;
  F(m.size()) {
    FF(m[i].size()) {
      FOR(k, -1, 2) FOR(l, -1, 2) {
        if (k == 0 && l == 0) continue;
        if (rec(m, j, i, 0, {k,l}, "XMAS")) cnt ++;
      }
    }
  }


  cout << "Part 1: " << cnt << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str;

  vector<string> m;
  while(getline(in, str)) m.PB(str);

  vector<pair<ll,ll>> ways = {{-1, -1}, {-1,+1}, {1,1}, {1,-1}};
  ll cnt = 0;
  FOR(i, 1, m.size()-1) {
    FOR(j, 1, m[i].size()-1) {
      if (m[i][j] != 'A') continue;
      vector<bool> b;
      FOR(k, 0, ways.size()) b.PB(rec(m, j+ways[k].aa, i+ways[k].bb, 0, {ways[k].aa*-1,ways[k].bb*-1}, "MAS"));
      if (count(b.begin(), b.end(), true) >= 2) cnt++;
    }
  }

  cout << "Part 2: " << cnt << endl;
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
