#include <bits/stdc++.h>
using namespace std;

struct ABBA {
	string canObtain(string, string);
};
string ABBA::canObtain(string a, string b) {
	while(b.size() > a.size()) {
		if(b.back() == 'A') b.pop_back();
		else {
			b.pop_back();
			reverse(b.begin(), b.end());
		}
	}
	return (a == b)? "Possible" : "Impossible";
}
