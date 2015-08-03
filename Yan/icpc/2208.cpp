// WA :(
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const int modn = 1000000;
inline int mod(int x) { return x % modn; }
int n, k;

struct cont {
	int srt, rat;
	bool operator < (cont o) const { return srt < o.srt; }
} cs[10009];

int bit[52][2][10009];
void add(int i1, int i2, int i, int x) {
	int *b = bit[i1][i2];
	i += 2;
	while(i < 10009) {
		b[i] = mod(b[i] + x);
		i += (i & -i);
	}
}

int get(int i1, int i2, int i) {
	int *b = bit[i1][i2];
	i += 2; int sum = 0;
	while(i) {
		sum = mod(sum + b[i]);
		i -= (i & -i);
	}
	return sum;
}
int get(int i1, int i2, int i, int j) { return mod(get(i1, i2, j) - get(i1, i2, i - 1) + modn); }


int memo[10009][52][2];
int main() {
	int i, j;
	for_tests(t, tt) {
		scanf("%d %d", &n, &k);
		map<int, int> mp;
		for(i = 0; i < n; i++) {
			scanf("%d %d", &cs[i].srt, &cs[i].rat);
			mp[cs[i].rat] = 1;
		}
		sort(cs, cs + n);
		i = 0;
		for(auto &e : mp)
			e.snd = i++;
		for(i = 0; i < n; i++) cs[i].rat = mp[cs[i].rat];
		memset(bit, 0, sizeof bit);
		memset(memo, 0, sizeof memo);
		for(i = n - 1; i >= 0; i--) {
			if(i > 0 && cs[i].rat == cs[i-1].rat) continue;
			//printf("doing %d %d\n", cs[i].srt, cs[i].rat);
			for(j = k+1; j >= 1; j--) {
				memo[i][j][0] = mod(get(j - 1, 1, 0, cs[i].rat - 1) + get(j, 0, 0, cs[i].rat - 1));
				memo[i][j][1] = mod(get(j - 1, 0, cs[i].rat + 1, 10005) + get(j, 1, cs[i].rat + 1, 10005));
				//printf("memo[%d][%d][0] = %d\nmemo[%d][%d][1] = %d\n", i, j, memo[i][j][0], i, j, memo[i][j][1]);
				add(j, 0, cs[i].rat, memo[i][j][0]);
				add(j, 1, cs[i].rat, memo[i][j][1]);
			}
			add(0, 0, cs[i].rat, 1);
			add(0, 1, cs[i].rat, 1);
			memo[i][0][0] = memo[i][0][1] = 1;
			//printf("memo[%d][0][0] = %d\nmemo[%d][0][1] = %d\n", i, memo[i][0][0], i, memo[i][0][1]);
		}
		int tot = 0;
		for(i = 0; i < n; i++) {
			if(i > 0 && cs[i].rat == cs[i-1].rat) continue;
			tot = mod(tot + memo[i][k+1][0] + memo[i][k+1][1] + (k == 0));
		}
		if(k == 0) tot = mod(tot + 1);
		printf("Case %d: %d\n", tt, tot);
	}
	return 0;
}
