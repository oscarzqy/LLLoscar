#include <iostream>
#include <string>

using namespace std;

int main() {
  freopen("A.in", "r", stdin);
  int T;
  cin >> T;
  for (int cas = 0; cas < T; ++cas) {
    string str;
    char ch;
    cin >> str;
    cin >> ch;
    int len = str.length();
    if (len % 2 == 0) {
      cout << "NO" << endl;
    } else {
      bool ans = false;
      for (int i = 0; i < len; ++i) {
        if (i % 2 == 0 && str[i] == ch) {
          ans = true ;
          break;
        }
      }
      if (ans) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}
