#include <iostream>
#include <map>
using namespace std;

typedef long long lint;
// hue
const int MAXF = 20, MAXN = 25, MAXK = MAXN + 1;

map<lint, lint> m[MAXK];
lint fat[MAXF], val[MAXN], ans, S;
int N, K;

void f(int n, int k, lint sum) {
	if(sum > S) return;
	if(n == (N + 1)/2) {
		m[k][sum]++;
		return;
	}
	f(n + 1, k, sum + val[n]);
	f(n + 1, k, sum);
	if(val[n] < MAXF)
		f(n + 1, k + 1, sum + fat[val[n]]);
}

void g(int n, int k, lint sum) {
	if(sum > S) return;
	if(n == N) {
		for(int i = 0; i <= K - k; i++) {
			ans += m[i][S - sum];
		}
		return;
	}
	g(n + 1, k, sum + val[n]);
	g(n + 1, k, sum);
	if(val[n] < MAXF)
		g(n + 1, k + 1, sum + fat[val[n]]);
}

int main(){
	fat[0] = 1LL;
	for(int i = 1; i < MAXF; i++) {
		fat[i] = fat[i-1]*lint(i);
	}
	cin >> N >> K >> S;
	for(int i = 0; i < N; i++) cin >> val[i]	;
	f(0, 0, 0LL);
	g((N + 1)/2, 0, 0LL);
	cout << ans << endl;
	return 0;
}