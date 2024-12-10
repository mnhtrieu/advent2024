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

struct state {
  pair<ll,ll> start;
  pair<ll,ll> pos;
  set<pair<ll,ll>> visited;
  ll idx;
};

void part_1(const string & file) {
  ifstream in(file);
  string str;

  vector<string> m;
  while(getline(in, str)) m.PB(str);

  vector<pair<ll,ll>> starts;
  F(m.size()) {
    FF(m[i].size()) if (m[i][j] == '0') starts.PB({j,i});
  }

  queue<state> q;
  F(starts.size()) q.push({starts[i], starts[i], {}, 0});

  map<pair<ll,ll>, set<pair<ll,ll>>> scores;
  vector<pair<ll,ll>> ways = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};
  while(!q.empty()) {
    auto [start, pos, visited, idx] = q.front(); q.pop();
    if (m[pos.bb][pos.aa] == '9') { scores[start].insert(pos); continue; }
    visited.insert(pos);
    F(ways.size()) {
      auto newPos = make_pair(pos.aa+ways[i].aa, pos.bb+ways[i].bb);
      if (visited.count(newPos)) continue;
      if (newPos.aa < 0 || newPos.aa >= (ll)m[0].size() || newPos.bb < 0 || newPos.bb >= (ll)m.size()) continue;
      if (m[newPos.bb][newPos.aa] != (idx+1 + '0')) continue;
      q.push({start, newPos, visited, idx+1}); 
    }
  }

  ll res = 0;
  for(auto & [p, s]: scores) res += s.size();
  cout << "Part 1: " << res << endl;
}

void part_2(const string & file) {
  ifstream in (file);
  string str;
  
vector<string> m;
  while(getline(in, str)) m.PB(str);

  vector<pair<ll,ll>> starts;
  F(m.size()) {
    FF(m[i].size()) if (m[i][j] == '0') starts.PB({j,i});
  }

  queue<state> q;
  F(starts.size()) q.push({starts[i], starts[i], {}, 0});

  map<pair<ll,ll>, ll> scores;
  vector<pair<ll,ll>> ways = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};
  while(!q.empty()) {
    auto [start, pos, visited, idx] = q.front(); q.pop();
    if (m[pos.bb][pos.aa] == '9') { scores[start] ++; continue; }
    visited.insert(pos);
    F(ways.size()) {
      auto newPos = make_pair(pos.aa+ways[i].aa, pos.bb+ways[i].bb);
      if (visited.count(newPos)) continue;
      if (newPos.aa < 0 || newPos.aa >= (ll)m[0].size() || newPos.bb < 0 || newPos.bb >= (ll)m.size()) continue;
      if (m[newPos.bb][newPos.aa] != (idx+1 + '0')) continue;
      q.push({start, newPos, visited, idx+1}); 
    }
  }

  ll res = 0;
  for(auto & [p, s]: scores) res += s;
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
