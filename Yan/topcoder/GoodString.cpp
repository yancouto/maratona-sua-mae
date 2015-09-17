/* BEGIN CUT HERE
// PROBLEM STATEMENT
// 
Chandan loves to play with strings.
He just learned a new operation: inserting one string X into another string Y.



When inserting X into Y, it is also allowed to place X at the beginning or at the end of Y.
For example, there are exactly five ways how to insert the string "ab" into the string "????":
you can produce one of the strings "ab????", "?ab???", "??ab??", "???ab?", and "????ab".



According to Chandan, a good string is a string that can be constructed in the following way:
Initially, he takes the empty string "".
Then, he performs a sequence of zero or more steps.
In each step he inserts the string "ab" anywhere into the current string.



According to the above definition, the strings "ab", "aabb", and "aababb" are good while the strings "aab", "ba", and "abbb" are not good.



Chandan's friend Ravi came up with a string s.
Ravi asked Chandan whether it is a good string.
Return "Good" (quotes for clarity) if the string is good, or "Bad" if the string is not good.


DEFINITION
Class:GoodString
Method:isGood
Parameters:string
Returns:string
Method signature:string isGood(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each element of s will be either 'a' or 'b'.


EXAMPLES

0)
"ab"

Returns: "Good"

Chandan can start with an empty string and insert "ab".

1)
"aab"

Returns: "Bad"



2)
"aabb"

Returns: "Good"

Chandan can construct this string as follows: "" -> "ab" -> "aabb".

3)
"ababab"

Returns: "Good"

One way to construct this string is to append "ab" to the current string three times.

4)
"abaababababbaabbaaaabaababaabbabaaabbbbbbbb"

Returns: "Bad"



5)
"aaaaaaaabbbaaabaaabbabababababaabbbbaabbabbbbbbabb"

Returns: "Good"



END CUT HERE */
#line 90 "GoodString.cpp"
#include <bits/stdc++.h>
using namespace std;
class GoodString {
	public:
	string isGood(string s) {
		char st[1000]; int sn = 0;
		for(char c : s) {
			st[sn++] = c;
			while(sn >= 2 && st[sn-1] == 'b' && st[sn-2] == 'a')
				sn -= 2;
		}
		if(!sn) return "Good";
		else return "Bad";
	}
};
