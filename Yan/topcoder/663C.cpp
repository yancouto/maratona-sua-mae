#include <bits/stdc++.h>
using namespace std;

struct CheeseRolling {
	vector<long long> waysToWin(vector <string> wins);
};
typedef long long ll;
ll memo[66000][16];
int seen[66000];
void wtw(vector<string> &w, int bm) {
	if(seen[bm]) return;
	seen[bm] = 1;
	int n = __builtin_popcount(bm);
	int i, j, k;
	ll *v = memo[bm];
	if(n == 1) {
		for(i = 0; !(bm & (1 << i)); i++);
		v[i] = 1;
		return;
	}
	for(i = 1; i < bm; i++) {
		if((i | bm) != bm) continue;
		if(__builtin_popcount(i) != n / 2) continue;
		wtw(w, i);
	}
	for(i = 1; i < bm; i++) {
		if((i | bm) != bm) continue;
		if(__builtin_popcount(i) != n / 2) continue;
		if((bm ^ i) > i) continue;
		ll *v1 = memo[i], *v2 = memo[bm ^ i];
		for(j = 0; j < w.size(); j++) {
			if(!(i & (1 << j))) continue;
			for(k = 0; k < w.size(); k++) {
				if(!((bm ^ i) & (1 << k))) continue;
				if(w[j][k] == 'Y') v[j] += 2 * v1[j] * v2[k];
				else v[k] += 2 * v1[j] * v2[k];
			}
		}
	}
}

vector<long long> CheeseRolling::waysToWin(vector <string> wins) {
	wtw(wins, (1 << wins.size()) - 1);
	vector<ll> v(wins.size());
	for(int i = 0; i < wins.size(); i++)
		v[i] = memo[(1 << wins.size()) - 1][i];
	return v;
}
