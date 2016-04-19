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

int n; ll sm;
int ans[40], aux[40];
bool co;
vector<int> pr;

void generate(int x) {
	x = max(x, -x);
	while(x%2 == 0) x /= 2, pr.pb(2);
	for(ll i = 3; i < x; i += 2)
		while(x%i==0) x /= i, pr.pb(i);
	if(x > 1) pr.pb(x);
	reverse(pr.begin(), pr.end());
}

void show(int nneg) {
	if(n > 0 && nneg % 2) return;
	if(n < 0 && !(nneg % 2)) return;
	if(co) { sm++; return; } 
	for(int i = 0; i < pr.size(); i++)
		aux[i] = ans[i];
	sort(aux, aux + pr.size());
	for(int i = 0; i < pr.size(); i++)
		printf("%d ", aux[i]);
	putchar('\n');
}

void solve(int i, int neg, int nneg) {
	if(i == pr.size()) { show(nneg); return ; }
	if(i && pr[i] == pr[i-1] && !neg) 
		ans[i] = pr[i], solve(i + 1, 0, nneg);
	else {
		ans[i] = -pr[i]; solve(i + 1, 1, nneg+1);
		ans[i] =  pr[i]; solve(i + 1, 0, nneg);
	}
}

int main() {
	freopen("product.in", "r", stdin);
	freopen("product.out", "w", stdout);
	cin >> n;
	generate(n);
	co = 1; solve(0, 0, 0);
	cout << sm << endl;
	co = 0; solve(0, 0, 0);
	return 0;
}
