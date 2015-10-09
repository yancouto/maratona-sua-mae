#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int MAX = 100005;

char s1[MAX], s2[MAX];
char ans[MAX];
int mark[MAX];
int n, t;

int main() {
	scanf("%d %d", &n, &t);
	scanf("%s %s", s1, s2);
	int diff = 0;
	vector<int> nt;
	for(int i = 0; i < n; i++) 
		if(s1[i] != s2[i]) 	nt.pb(i);
		else mark[i] = 1;
	if(t == 0 && nt.size()) { puts("-1"); return 0; }
	else if(t == 0) { printf("%s\n", s1); return 0; }
	while(nt.size()) {
		if(nt.size() > t && nt.size() > 1) {
			int l = nt[nt.size() - 1];
			ans[l] = s1[l];
			nt.pop_back(); 
			l = nt[nt.size() - 1];
			ans[l] = s2[l];
			nt.pop_back(); t--;
		}
		else {
			int l = nt[nt.size() - 1];
			ans[l] = s1[l] + 1;
			if(ans[l] > 'z') ans[l] = 'a';
			if(ans[l] == s2[l]) ans[l]++;
			if(ans[l] > 'z') ans[l] = 'a';
			nt.pop_back(); t--;
		}
	}
	if(t < 0) { puts("-1"); return 0; }
	for(int i = 0; i < n; i++) {
		if(!mark[i]) continue;
		ans[i] = s1[i];
		if(!t) continue;
		ans[i]++;
		if(ans[i] > 'z') ans[i] = 'a';
		t--;
	}
	for(int i = 0; i < n; i++)
		printf("%c", ans[i]);
	putchar('\n');
	return 0;
}
