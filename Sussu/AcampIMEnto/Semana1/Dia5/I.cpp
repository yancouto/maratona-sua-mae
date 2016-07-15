#include <bits/stdc++.h>
#define debug(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 212345;

int ans[MAXN];
map< pair<int, int>, int > last;
vector<int> v[MAXN];
int n, m;
	
int main() {
	freopen("intouch.in", "r", stdin);
	freopen("intouch.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i  = 0; i < n; i++) ans[i] = 0;
	for(int i = 0; i < m; i++) {
		char op;
		scanf(" %c", &op);
		if(op == '!') {
			int idx;
			scanf("%d", &idx);
			v[--idx].push_back(i);
		} else {
			int a, b;
			scanf("%d%d", &a, &b);
			a--; b--;
			if(a > b) swap(a, b);		
			if(op == '+') {
				last[{a, b}] = i;
			} else {
				int idx = last[{a, b}];
				ans[a] += v[b].end() - upper_bound(v[b].begin(), v[b].end(), idx);
				ans[b] += v[a].end() - upper_bound(v[a].begin(), v[a].end(), idx);
				last.erase({a, b});
			}
		}
	}
	for(pair< pair<int, int>, int> p : last) {
		int idx = p.second;
		int a = p.first.first;
		int b = p.first.second;
		ans[a] += v[b].end() - upper_bound(v[b].begin(), v[b].end(), idx);
		ans[b] += v[a].end() - upper_bound(v[a].begin(), v[a].end(), idx);
	}
	for(int i = 0; i < n; i++) printf("%d ", ans[i]);
	return 0;
}
