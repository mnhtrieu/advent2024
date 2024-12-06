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
  vector<pair<ll,ll>> ways = {{0,-1}, {1,0}, {0,1}, {-1, 0}};
  while(getline(in, str)) {
    m.PB(str);
  }

  pair<ll,ll> start = {-1,-1};
  ll w = 0;
  

  F(m.size()) {
    FF(m[i].size()) {
      if (m[i][j] != '^') continue;
      start = {j,i};
      break;
    }
    if (start.aa != -1) break;
  }

  set<pair<ll,ll>> pos;
  pos.insert(start);
  while (true) {
    if (start.aa <= 0 || start.aa >= (ll)m[0].size() || start.bb <= 0 || start.bb >= (ll)m.size()) break;
    auto p = make_pair(start.aa + ways[w].aa, start.bb + ways[w].bb);
    if (m[p.bb][p.aa] == '#') { w = ((w + 1) % 4); p = make_pair(start.aa + ways[w].aa, start.bb + ways[w].bb); continue; }
    pos.insert(start);
    start = p;
  }

  cout << "Part 1: " << pos.size() << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str;

  vector<string> m;
  vector<pair<ll,ll>> ways = {{0,-1}, {1,0}, {0,1}, {-1, 0}};
  while(getline(in, str)) {
    m.PB(str);
  }

  pair<ll,ll> start = {-1,-1};
  ll w = 0;

  F(m.size()) {
    FF(m[i].size()) {
      if (m[i][j] != '^') continue;
      start = {j,i};
      break;
    }
    if (start.aa != -1) break;
  }

  set<pair<ll,ll>> pos;
  pos.insert(start);
  auto begin = start;
  while (true) {
    if (begin.aa <= 0 || begin.aa >= (ll)m[0].size() || begin.bb <= 0 || begin.bb >= (ll)m.size()) break;
    auto p = make_pair(begin.aa + ways[w].aa, begin.bb + ways[w].bb);
    if (m[p.bb][p.aa] == '#') { w = ((w + 1) % 4); p = make_pair(begin.aa + ways[w].aa, begin.bb + ways[w].bb); }
    pos.insert(begin);
    begin = p;
  }

  set<pair<ll,ll>> blocks;
  for(const auto & block : pos) {
    if (block == start) continue;
    bool finish = false;
    begin = start;
    w = 0;
    set<pair<pair<ll,ll>, ll>> loops;
    while (true) {
      if (begin.aa <= 0 || begin.aa >= (ll)m[0].size() || begin.bb <= 0 || begin.bb >= (ll)m.size()) { finish = true; break; }
      auto p = make_pair(begin.aa + ways[w].aa, begin.bb + ways[w].bb);
      if (m[p.bb][p.aa] == '#' || p == block) { w = ((w + 1) % 4); p = make_pair(begin.aa + ways[w].aa, begin.bb + ways[w].bb); continue; }
      if (loops.count(make_pair(p, w))) break; 
      loops.insert(make_pair(p, w));
      begin = p;
    }
    if (!finish) blocks.insert(block);
  }

  cout << "Part 2: " << blocks.size() << endl;
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
