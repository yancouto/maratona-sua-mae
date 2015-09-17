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
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

map<string, int> mp;
string s[205];
int wh[205], bef[205];

int main() {
	int k; scanf("%d", &k);
	while(k--) {
		int n; scanf("%d", &n);
		char line[85];
		int ind = 0;
		getchar();
		for(int i = 0; i < n; i++) {
			fgets(line, 85, stdin);
			string ss = string(line);
			bef[i] = ind;
			mp[ss] = ind;
			s[ind] = ss;
			ind++;
		}
		for(int i = 0; i < n; i++) {
			fgets(line, 85, stdin);
			string ss = string(line);
			wh[mp[ss]] = i; 
		}
		int i = n - 1, j;
		vector<int> ans;
		int freq[205];
		memset(freq, 0, sizeof freq);
		while(42) {
			for(j = i; j >= 0 && j <= wh[bef[j]]; j--);
			if(j == -1) break;
			ans.pb(bef[j]);
			freq[bef[j]]++;
			int elem = bef[j];
			i = j;
			for(; j > 0; j--) bef[j] = bef[j-1]; 
			bef[0] = elem;
		}
		for(i = 0; i < ans.size(); i++) {
			if(freq[ans[i]] > 1) { freq[ans[i]]--; continue; }
			printf("%s", s[ans[i]].c_str());
		}
		putchar('\n');
	}
	return 0;
}
