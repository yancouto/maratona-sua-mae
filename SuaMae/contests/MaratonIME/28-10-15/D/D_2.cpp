#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

vector<lint> primes;
lint n, ans;

vector< pair<lint,int> > factorize(lint n) {
	vector< pair<lint, int> > v;
	for(lint i = 2; i*i <= n; i++) {
		int count = 0;
		while((n % i) == 0) {
			count++;
			n /= i;
		}
		if(count != 0) {
			v.push_back({i, count});
		}
	}
	if(n != 1) {
		v.push_back({n, 1});
	}
	return v;
}

bool cmp(pair<lint, int> a, pair<lint, int> b) {
	return a.first > b.first;
}

bool ok(lint num) {
	vector< pair<lint, int> > fact = factorize(num);
	sort(fact.begin(), fact.end(), cmp);
	lint prod = 1;
	int idx = 0;
	for(int i = 0; i < fact.size(); i++) {
		while(fact[i].second > 0) {
			int qtd = fact[i].first - 1;
			while(qtd && n / prod >= primes[idx]) {
				prod *= primes[idx];
				qtd--;
			}
			if(qtd) {
				return false;
			}
			fact[i].second--;
			idx++;
		}
	}
	ans = prod;
	return true;
}

int main() {
	//108716359680
	freopen("divisors.in", "r", stdin);
	freopen("divisors.out", "w", stdout);
	for(lint i = 2; primes.size() < 30; i++) {
		bool isPrime = true;
		for(lint j = 2; j < i; j++) {
			if(!(i % j)) isPrime = false;
		}
		if(isPrime) {
			primes.push_back(i);
		}
	}
	cin >> n;
	lint lo = 2, hi = 100000000000LL;
	while(lo <= hi) {
		lint mid = (lo + hi)/2;
		if(ok(mid)) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
