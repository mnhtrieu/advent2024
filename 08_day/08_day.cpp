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

  vector<string> m;
  map<char, vector<pair<ll,ll>>>  antennas;

  while(getline(in, str)) {
    m.PB(str);
    F(str.size()) {
      if (str[i] != '.') antennas[str[i]].PB({i, (ll)m.size()-1});
    }
  }

  set<pair<ll,ll>> res;

  for(auto & [antenna, positions] : antennas) {
    F(positions.size()) {
      FOR(j, i+1, positions.size()) {
        pair<ll,ll> xy = {(positions[j].aa - positions[i].aa), (positions[j].bb - positions[i].bb)};
        pair<ll,ll> yx = {positions[i].aa - positions[j].aa, positions[i].bb - positions[j].bb};

        pair<ll,ll> a1 = {positions[j].aa + xy.aa, positions[j].bb + xy.bb};
        pair<ll,ll> a2 = {positions[i].aa + yx.aa, positions[i].bb + yx.bb};

        if (a1.aa >= 0 && a1.aa < (ll)m[0].size() && a1.bb >= 0 && a1.bb < (ll)m.size()) res.insert(a1);
        if (a2.aa >= 0 && a2.aa < (ll)m[0].size() && a2.bb >= 0 && a2.bb < (ll)m.size()) res.insert(a2);
      }
    }
  }

  cout << "Part 1: " << res.size() << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str;

  vector<string> m;
  map<char, vector<pair<ll,ll>>>  antennas;

  while(getline(in, str)) {
    m.PB(str);
    F(str.size()) {
      if (str[i] != '.') antennas[str[i]].PB({i, (ll)m.size()-1});
    }
  }

  set<pair<ll,ll>> res;

  for(auto & [antenna, positions] : antennas) {
    F(positions.size()) {
      FOR(j, i+1, positions.size()) {
        res.insert(positions[j]);
        res.insert(positions[i]);
        pair<ll,ll> xy = {(positions[j].aa - positions[i].aa), (positions[j].bb - positions[i].bb)};
        pair<ll,ll> yx = {positions[i].aa - positions[j].aa, positions[i].bb - positions[j].bb};

        pair<ll,ll> a1 = {positions[j].aa + xy.aa, positions[j].bb + xy.bb};
        pair<ll,ll> a2 = {positions[i].aa + yx.aa, positions[i].bb + yx.bb};

        while (a1.aa >= 0 && a1.aa < (ll)m[0].size() && a1.bb >= 0 && a1.bb < (ll)m.size()) {
          res.insert(a1);
          a1 = {a1.aa + xy.aa, a1.bb + xy.bb};
        }

        while (a2.aa >= 0 && a2.aa < (ll)m[0].size() && a2.bb >= 0 && a2.bb < (ll)m.size()) {
          res.insert(a2);
          a2 = {a2.aa + yx.aa, a2.bb + yx.bb};
        }
      }
    }
  }

  cout << "Part 2: " << res.size() << endl;
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
