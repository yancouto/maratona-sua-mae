#include <bits/stdc++.h>

using namespace std;

typedef long long lint;

const int MAX = 30;
vector<lint> primes;
lint n, ans;

int main() {
	//freopen("divisors.in", "r", stdin);
	//freopen("divisors.out", "w", stdout);
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
	lint prod = 1;
	int coord[MAX];
	memset(coord, 0, sizeof coord);
	lint div = 1;
	while(1) {
		lint ndiv = div;
		int idx;
		for(int i = 0; i < MAX; i++) {
			if(n / prod < primes[i]) break;
			if(coord[i] == 0) {
				if(2*div > ndiv) {
					ndiv = 2*div;
					idx = i;
				}
			} else {
				if(div/(coord[i] + 1) + div > ndiv) {
					ndiv = div/(coord[i] + 1) + div;
					idx = i;
				}
			}
		}
		//printf("Peguei %d\n", primes[idx]);
		if(ndiv == div) break;
		div = ndiv;
		coord[idx]++;
		prod *= primes[idx];
	}
	cout << prod << endl;
	return 0;
}
