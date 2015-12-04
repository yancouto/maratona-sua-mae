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
	int n, i, j;
	int v[100005];
	int acc[100005], ia = 0;
	int x[100005];
	scanf("%d", &n);
	for(i = 0; i < n; i++) 
		scanf("%d", &v[i]);
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n && v[j] == v[i]; j++);
		x[ia] = v[i];
		acc[ia++] = j - i;
		i = j - 1;
	}
	int ans = acc[0], sum = 0;
	for(i = 0; i < ia - 1; i++) {
		j = i + 2;
		sum = acc[i] + acc[i+1];
		while(j < n && i+1 < n && (x[j] == x[i] || x[j] == x[i+1])) {
			sum += acc[j];
			j++;
		}
		ans = max(ans, sum);
		if(j == n) break;
		i = j - 2;
	}
	printf("%d\n", ans);	
	return 0;	
}
