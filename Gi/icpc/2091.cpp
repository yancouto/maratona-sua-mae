//#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <cstring>
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
char linha[5000000];
int dg[100010], memo[100010][2], ns[100010][2], nf[100010][2];

ull solve(int no, int pai) {
	if(adj[no].empty()) {
		ns[no][0] = nf[no][0] = nf[no][1] = 0;
		ns[no][1] = 1;
		return pai*n;
	}
	int &mem = memo[no][pai];
	if(mem != -1) return mem;

	ull sum1 = 0, sum2 = 0;
	int nss0 = 0, nss1 = 0, nfs0 = 0, nfs1 = 0;
	for(int i = 0; i < adj[no].size(); i++) {
		sum1 += solve(adj[no][i], 1);
		sum2 += solve(adj[no][i], 0);
		nss1 += ns[adj[no][i]][1];
		nss0 += ns[adj[no][i]][0];
		nfs1 += nf[adj[no][i]][1];
		nfs0 += ns[adj[no][i]][0];
	}
	sum2 += m;
	if(pai) sum1 += n;
	if(sum1 < sum2) {
		ns[no][pai] = pai + nss1;
		nf[no][pai] = nfs1;
	} else if(sum2 < sum1) {
		ns[no][pai] = nss0;
		nf[no][pai] = 1 + nfs0;
	} else {
      if(pai) {
	      if(nss0 + nfs0 <= nss1 + nfs1) {
            ns[no][pai] = nss0;
            nf[no][pai] = 1 + nfs0;
         } else {
            ns[no][pai] = 1 + nss1;
            nf[no][pai] = nfs1;
         }
      } 
      else {
         if(nss0 + nfs0 + 1 <= nss1 + nfs1) {
            ns[no][pai] = nss0;
            nf[no][pai] = 1 + nfs0;
         } 
         else {
            ns[no][pai] = nss1;
            nf[no][pai] = nfs1;
         }
      }  
   } 	
	return mem = min(sum1, sum2);
}

int main() {
   int count = 0;
	fgets(linha, 5000000, stdin);
	while(42) {
		int k = 0;
		sscanf(linha, "%d%d", &n, &m);
		if(n == 0 && m == 0) break;
		memset(dg, 0, sizeof dg);
		for(int i = 0; i <= 100005; i++)
         adj[i].clear();
      mp.clear();
      while(true) {
			fgets(linha, 5000000, stdin);
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
				if(linha[i] == ' ') {
               if(linha[i-1] == ' ') continue;
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
		}
      for(int i = 0; i <= k+2; i++)
         memo[i][0] = memo[i][1] = -1;
		ull ans = 0;
      int NS = 0, NF = 0;
		for(int i = 0; i < k; i++) {
		   if(dg[i] == 0) {
				ans += solve(i, 1);
            NS += ns[i][1]; NF += nf[i][1];  
         }
		}
      printf("%d. %d %d %llu\n", ++count, NS, NF, ans);
	}
}
