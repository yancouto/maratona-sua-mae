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

int main() {
	int n; char s[105];
	scanf("%s", s);
	n = strlen(s);
	int ans = 0, nn = 0;
	for(int i = 0; i < n; i++) {
		nn++;
		if(s[i] - '0' > 1 || i == n-1) ans += s[i]-'0';
		else if(s[i+1] == '0')  { ans += 10; i++; }
		else ans += 1;
	}
	printf("%.2f\n", (double) ans / nn); 
	return 0;
}
