#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) //fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> st;
	for(int i = 0; i < s.size(); i++) st.push(s[i]);
	int k;
	cin >> k;
	while(k--) {
		stack<char> l;
		stack<char> r;
		int flag = 0;
		while(!st.empty()) {
			if(!flag) l.push(st.top());
			else r.push(st.top());
			st.pop();
			flag ^= 1;
		}
		stack<char> aux;
		while(!l.empty()) {
			aux.push(l.top());
			l.pop();
		}
		while(!r.empty()) {
			aux.push(r.top());
			r.pop();
		}
		while(!aux.empty()) {
			st.push(aux.top());
			aux.pop();
		}
	}
	stack<char> ans;
	while(!st.empty()) {
		ans.push(st.top());
		st.pop();
	}
	while(!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	cout << endl;
	return 0;
}
