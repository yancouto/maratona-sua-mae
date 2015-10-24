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
const int MS = 40;
char s[MS], sol[MS];
int pend[MS], ps, tempo, n, d, a, b;

int main() {
	int i, j;
	for_tests(t, tt) {
		tempo++; scanf("%s", s);
		n = strlen(s);
		ps = a = b = 0;
		memset(sol, 0, sizeof sol);
		for(int i=0;i<n;i++)
			if( !sol[i] )
			{
				a |= s[i] == 'a';
				b |= s[i] == 'b';
				sol[i] |= (s[i]==s[i+1]);
				int j = i+1;
				while( j < n && s[i] == s[j] )
				{
					sol[j] |= 1;
					j++;
				}
				if( ps > 0 && s[pend[ps-1]]==s[i] )
				{
					sol[pend[ps-1]] |= 1;
					ps--;
				}
				if( s[i+1] != s[i] )
					pend[ps++] = i;
			}
		int tot = 0;
		for(int i=0;i<n;i++)
			tot += sol[i];
		if( !sol[n-1] ) 
			tot += s[n-1] == 'a' ? a : b;
		printf("%d\n", tot == n);
	}
}
