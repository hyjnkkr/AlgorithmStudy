#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string orig, exp; // original / explosion target
  string res = "";  // the final  result
  cin >> orig >> exp;

  int orig_len = orig.length();
  int exp_len = exp.length();

  // from i = 0 -> orig_len, push the items into 'result' one by one.
  // if the 'last' character is pushed, start checking whether
  // the explosion would occur.

  for (int i = 0; i < orig_len; i++) {
    res.push_back(orig[i]);
    // explosion seq (last character is pushed && result's size bigger than
    // exp's length)
    if (orig[i] == exp[exp_len - 1] && res.size() >= exp_len) {

      // check if the exp (completely same) exists
      bool match = true;
      for (int j = 0; j < exp_len; j++) {
        if (res[res.size() - exp_len + j] != exp[j]) {
          match = false;
          break;
        }
      }

      if (match == true) {
        for (int j = 0; j < exp_len; j++) {
          res.pop_back();
        }
      }
    }
  }

  if (res.empty()) {
    cout << "FRULA" << '\n';
  } else {
    cout << res << '\n';
  }
  return 0;
}
