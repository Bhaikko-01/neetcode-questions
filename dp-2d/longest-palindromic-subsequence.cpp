/**
 * 1. Generate all subsequences and Find valid palindromes - O(2^n * n)
 * 2. LCS derivative - O(n^2)
 *      Get reverse of string and use LCS to get ans
 *      This works because, in a reversed string, we would be searching a longest reversed subsequence
 *        Hence this would give a string whose reversed subsequence is also present
 *        Which is longest subsequence palindrome
 * 3. Longest Substring Palindrome derivative - O(n^2)
 *      Just like in LSP, we iterate on both ends from a index to find longest substring palindrome,
 *        Similarly we do same but with subsequence, hence decision tree is formed considering whether
 *          to skip left element or right element
 *      Consider both even and odd length strings and return answer accordingly
 *
 *      When converting to DP, no need to iterate 0 to n for finding middle point,
 *        construct DP by l and r since they are used for decision tree and l <= r
 *        Find max from dp 2D matrix as that would mean we started with l and r
*/

#include <bits/stdc++.h>

using namespace std;

string getKey(int first, int second)
{
  return to_string(first) + "," + to_string(second);
}

int longestPalindromeSubseq(string s, int l, int r, unordered_map<string, int>& occured)
{
  int n = s.size();

  string key = getKey(l, r);

  if (r >= n || l < 0) {
    return 0;
  }

  if (occured.find(key) != occured.end()) {
    return occured[key];
  }

  if (s[l] == s[r]) {
    if (l == r) {
      return 1 + longestPalindromeSubseq(s, l - 1, r + 1, occured);
    }

    return 2 + longestPalindromeSubseq(s, l - 1, r + 1, occured);
  }

  int rightSkip = longestPalindromeSubseq(s, l, r + 1, occured);
  int leftSkip = longestPalindromeSubseq(s, l - 1, r, occured);

  return max(leftSkip, rightSkip);
}

int longestPalindromeSubseq(string s)
{
  int n = s.size();

  unordered_map<string, int> occured;

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int l = i, r = i;
    int currAns = longestPalindromeSubseq(s, l, r, occured);
    ans = max(ans, currAns);

    l = i, r = i + 1;
    currAns = longestPalindromeSubseq(s, l, r, occured);
    ans = max(ans, currAns);
  }

  return ans;
}

int getDpValue(int n, vector<vector<int>>& dp, int l, int r)
{
  if (l < 0 || r >= n) {
    return 0;
  }

  return dp[l][r];
}

int longestPalindromeSubseqDp(string s)
{
  int n = s.size();

  vector<vector<int>> dp(n, vector<int>(n, 0));

  int ans = 0;

  for (int l = 0; l < n; l++) {
    for (int r = n - 1; r >= l; r--) {
      if (s[l] == s[r]) {
        if (l == r) {
          dp[l][r] = 1 + getDpValue(n, dp, l - 1, r + 1);
        } else {
          dp[l][r] = 2 + getDpValue(n, dp, l - 1, r + 1);
        }
      } else {
        dp[l][r] = max(getDpValue(n, dp, l - 1, r), getDpValue(n, dp, l, r + 1));
      }

      ans = max(ans, dp[l][r]);
    }
  }

  return ans;
}

void solution()
{
  string s;
  cin >> s;

  cout << longestPalindromeSubseqDp(s) << endl;
}

int main()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    solution();
  }

  return 0;
}
