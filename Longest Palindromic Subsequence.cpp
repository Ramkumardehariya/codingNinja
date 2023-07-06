#include <bits/stdc++.h> 

int spaceOptimize(string s1, string s2){
	int n = s1.length();
	int m = s2.length();

	vector<int> curr(m+1, 0), prev(m+1, 0);

	for(int i = 0; i<=m; i++){
		prev[i] = 0;
	}

	for(int index1 = 1; index1<=n; index1++){
		for(int index2 = 0; index2<=m; index2++){
			
			if(s1[index1-1] == s2[index2-1]){
				curr[index2] = 1 + prev[index2-1];
			}
			else{
			    curr[index2] = max(prev[index2],curr[index2-1]);
			} 
		}
		prev = curr;
	}
	return curr[m];
}

int longestPalindromeSubsequence(string s)
{
    string t = s;
    reverse(t.begin(), t.end());

    return spaceOptimize(s, t);
}
