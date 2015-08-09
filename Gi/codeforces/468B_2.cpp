//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
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

int n, a, b, p;
int seq[100005], seen[100005], mask[100005];
map<int, int> mp;

void dfs(int x){
	seen[x] = p;
	if(mp.count(a-seq[x])){
		int c = mp[a-seq[x]];
		if(!seen[c]) dfs(c);
	}
	else if(mask[p]&1) mask[p] = mask[p]^1;
	if(mp.count(b-seq[x])){
		int c = mp[b-seq[x]];
		if(!seen[c]) dfs(c);
	}
	else if(mask[p]&2) mask[p] = mask[p]^2;
}

int main(){
	scanf("%d %d %d", &n, &a, &b);
	for(int i = 0; i < n; i++){
		scanf("%d", &seq[i]);
		mp[seq[i]] = i;
	}
	for(int i = 0; i < n; i++){
		if(seen[i]) continue;
		mask[++p] = 3;
		dfs(i);
		if(!mask[p]) { puts("NO"); return 0; }
	}
	puts("YES");
	for(int i = 0; i < n; i++)
		printf("%d ", (mask[seen[i]]&1)?0:1);
	printf("\n");
	return 0;
}
