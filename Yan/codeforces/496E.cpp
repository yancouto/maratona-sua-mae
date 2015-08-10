#include <bits/stdc++.h>
using namespace std;
const int MAX = 100009;
int ps[MAX][2], as[MAX][3];
map<int, int> compr;

vector<int> padd[MAX], aadd[MAX];
multimap<int, int> mp;

int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &ps[i][0], &ps[i][1]);
		compr[ps[i][0]] = 0; compr[ps[i][1]] = 0;
	}
	scanf("%d", &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &as[i][0], &as[i][1], &as[i][2]);
		compr[as[i][0]] = 0; compr[as[i][1]] = 0;
	}
	i = 0;
	for(auto &e : compr)
		e.snd = i++;
	for(i = 0; i < n; i++) {
		ps[i][0] = compr[ps[i][0]];
		ps[i][1] = compr[ps[i][1]];
		padd[ps[i][0]].push_back(i);
	}
	for(i = 0; i < m; i++) {
		as[i][0] = compr[as[i][0]];
		as[i][1] = compr[as[i][1]];
		aadd[as[i][0]].push_back(i);
	}
	for(i = 0; i < compr.size(); i++) {
		while(!mp.empty() && mp.begin().fst < i) mp.erase(mp.begin());
		for(int v : aadd) mp.insert(make_pair(as[v][1], as[v][2]));
		for(int v : padd) {
			auto it = mp.lower_bound(ps[v][1]);
			/* terminar */
		}
	}
}
