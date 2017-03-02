// Knuth–Morris–Pratt algorithm
// Searches for occurrences of a "word" W within a main "text string" S
// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> kmp_init(string w) {

  int m = w.size();

  vector<int> f(m + 1);

  for (int i = 0, j =- 1; ; i++, j++) {
    f[i] = j;

    if (i == m) {
      return f;
    }

    while (j >= 0 && w[i] != w[j]) {
      j = f[j];
    }
  }
}

vector<int> kmp_match(string s, string w) {

  int n = s.size(), m = w.size();

  vector<int> matches, f = kmp_init(w);

  for (int i = 0, j = 0; ; i++, j++) {

    if (j == m) {
      matches.push_back(i - j), j = f[j];
    }

    if (i == n) {
      return matches;
    }

    while (j >= 0 && s[i] != w[j]) {
      j = f[j];
    }
  }

  return matches;
}
