#include "bits/stdc++.h"
using namespace std;
string s;
string ans;
int n;

bool compare(const string & x1, const string & x2){
	if (x1.size() > x2.size()) return 1;
	else if (x1.size() < x2.size()) return 0;
	else
	{
		for (int i = 1 ; i <= n ; i++)
		{
			if (x1[i] > x2[i]) return 1;
			else if (x1[i] < x2[i]) return 0;
		}
	}
}

int main()
{
	cin >> s;
	n = s.size();
	s =  ' ' + s;
	ans = " ";
	for (int i = 1 ; i < n ; i++) ans = ans + '9';
	for (int i = 1 ; i <= n ; i++) 
	{
		int del = s[i] - '0';
		if (del % 2) {
			if (del >= 3){
				string EXold = " ";
				for (int j  = 1 ; j < i ; j++) EXold += s[j];
				EXold += (s[i] - 2);
				for (int j = i + 1 ; j <= n ; j++) EXold += "9";
				if (compare(EXold, ans)) ans = EXold;
			}
			continue;
		}
		if (del != 0){
			s[i]--;
			i++;
			for ( ; i <= n ; i++) s[i] = '9';
			if (compare(s, ans)) ans = s;
			break;
		}
		else{
			string ex0L = " ", ex0R = " ";
			if (i > 1){
				for (int j  = 1 ; j < i - 1 ; j++) ex0L += s[j];
				for (int j = i ; j <= n ; ++j) ex0L += '9';
				if (compare(ex0L, ans)) ans = ex0L;
				break;
			}
			if (i < n){
				for (int j  = 1 ; j < i ; j++) ex0R += s[j];
				for (int j = i + 1 ; j <= n ; ++j) ex0R += '9';
				if (compare(ex0R, ans)) ans = ex0R;
				break;
			}
			
		}
	}
	for (int i = 1 ; i < ans.size() ; ++i) cout << ans[i];
}