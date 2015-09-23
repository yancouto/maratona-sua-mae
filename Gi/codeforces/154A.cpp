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

char s[100005];
int memo[100005][30];
int pro[30];
int n, k;

int solve(int i, int c) {
	if(i == n) return 0;
	int &m = memo[i][c];
	if(m != -1) return m;
	m = 1 + solve(i + 1, c);
	if(pro[c] != s[i]-'a') 
		m = min(m, solve(i + 1, s[i]-'a'+1));
	return m;
}


int main() {
	memset(memo, -1, sizeof memo);
	memset(pro, -1, sizeof pro);
	scanf("%s", s);
	n = strlen(s);
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		char a, b;
		scanf(" %c%c", &a, &b);
		pro[a-'a'+1] = b-'a';
		pro[b-'a'+1] = a-'a';
	}
	printf("%d\n", solve(0, 0));  	
	return 0;
}
