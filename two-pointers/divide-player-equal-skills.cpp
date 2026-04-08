#include <bits/stdc++.h>

using namespace std;

using ll = long long;

long long dividePlayers(vector<int>& skills)
{
  int n = skills.size();

  if (n == 2) {
    return skills[0] * skills[1];
  }

  unsigned int sum = 0;
  for (int skill: skills) {
    sum += skill;
  }

  ll ans = 0;

  int l = 0,
      r = n - 1;

  int numTeams = n / 2;
  int teamSkill = sum / numTeams;

  sort(skills.begin(), skills.end());

  while (l < r) {
    int first = skills[l];
    int second = skills[r];

    if (first + second != teamSkill) {
      return -1;
    }

    ll currSkill = first * second;
    ans += currSkill;

    l++;
    r--;
  }

  return ans;
}

void solution()
{
  int n;
  cin >> n;

  vector<int> skill(n);
  for (int i = 0; i < n; i++) {
    cin >> skill[i];
  }

  cout << dividePlayers(skill) << endl;
}

int main()
{
  solution();

  return 0;
}
