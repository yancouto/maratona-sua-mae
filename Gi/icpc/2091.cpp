#include <bits/stdc++.h>
#include <cstdlib>
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
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int n, m;
map<string, int> mp;
vector<int> adj[100010];
char linha[500];
int dg[100010], memo[100010][2], ns[100010], nf[100010];

ull solve(int no, int pai) {
	if(adj[no].empty()) {
		ns[no] = pai;
		nf[no] = 0;
		return pai*n;
	}
	int &mem = memo[no][pai];
	if(mem != -1) return mem;

	ull sum1 = 0, sum2 = 0;
	int nss = 0, nfs = 0;
	for(int i = 0; i < adj[no].size(); i++) {
		sum1 += solve(adj[no][i], 1);
		sum2 += solve(adj[no][i], 0);
		nss += ns[adj[no][i]];
		nfs += nf[adj[no][i]];
	}
	sum2 += m;
	if(pai) sum1 += n;
	if(sum1 < sum2) {
		ns[no] = pai + nss;
		nf[no] = nfs;
	} else if(sum2 < sum1) {
		ns[no] = nss;
		nf[no] = 1 + nfs;
	} else {
		if(pai > 1) {
			ns[no] = nss;
			nf[no] = 1 + nfs;
		} else {
			ns[no] = nss;
			nf[no] = nfs;
		}
	} 
		
	return mem = min(sum1, sum2);
}

int build(int no, int pai) {
	if(adj[no].empty()) return pai;
	int ret = 0;
	if(memo2[no][pai] == 1)
		ret = 1 + build(adj[no], 1
	
}

int main() {
	fgets(linha, 500, stdin);
	while(42) {
		int k = 0;
		sscanf(linha, "%d%d", &n, &m);
		if(n == 0 && m == 0) break;
		memset(dg, 0, sizeof dg);
		memset(memo, -1, sizeof memo);
		while(true) {
			fgets(linha, 500, stdin);
			if(linha[0] >= '0' && linha[0] <= '9') 
				break;
			int s = strlen(linha);
			char word[1010], iw = 0;	
			map<string, int>::iterator it;
			int pai, i;
			sscanf(linha, "%s", word);
			string str2(word, word+strlen(word));
			it = mp.find(str2);
			if(it == mp.end()) {
				mp[str2] = k++;
				pai = k-1;
			}
			else
				pai = it->snd;
			
			linha[s-1] = ' ';
			for(i = strlen(word)+1; i < s; i++) {
				if(linha[i] == ' ' && linha[i-1] != ' ') {
					string str(word, word + iw);
					it = mp.find(str);
					if(it == mp.end()) {		
						mp[str] = k++;
						adj[pai].pb(k-1);
						dg[k-1]++;
					}
					else {
						dg[it->snd]++;
						adj[pai].pb(it->snd);
					}
					iw = 0;
					continue;
				}
				word[iw++] = linha[i];
			}
			for(i = 0; i < k; i++) {
				printf("(%d)", i);
				for(int j = 0; j < adj[i].size(); j++)
					printf("%d ", adj[i][j]);
				printf("\n");
			}
			
			ull ans = 0;
			for(i = 0; i < k; i++) {
				if(dg[i] == 0)
					ans += solve(i, 1);
			}
		}
	}
}
