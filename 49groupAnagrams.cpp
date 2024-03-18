#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> svmap;

    for (const auto &str : strs) {
      std::string k = str;
      std::sort(k.begin(), k.end());
      if (svmap.count(k) == 0) {
        svmap[k] = std::vector<std::string>();
      }
      svmap[k].emplace_back(str);
    }

    if (svmap.empty()) {
      return std::vector<std::vector<std::string>>();
    }

    std::vector<std::vector<std::string>> ans;
    for (const auto &[k, vec] : svmap) {
      ans.emplace_back(vec);
    }

    return ans;
  }
};


// #include <unordered_map>
// #include <vector>
// #include <string>

// using namespace std;

// class Solution {
// public:
//   vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     std::unordered_map<int, std::vector<std::vector<std::string>>> ivmap;
//     std::vector<std::vector<string>> ans;

//     for (const auto &s : strs) {
//       int ha = h(s);
//       if (ivmap.count(ha) == 0) {
//         ivmap[ha] = std::vector<std::vector<std::string>>{};
//       }
//       bool insearted = false;
//       for (auto &vec: ivmap[ha]) {
//         if (isGroup(vec[0], s)) {
//           vec.emplace_back(s);
//           insearted = true;
//           break;
//         }
//       }

//       if (!insearted) {
//         ivmap[ha].emplace_back(std::vector<std::string>{s});
//       }
//     }

//     if (ivmap.size() == 0) {
//       ans.emplace_back();
//       return ans;
//     }

//     for (const auto &[h, vec] : ivmap) {
//       for (const auto &v : vec) {
//         ans.emplace_back(v);
//       }
//     }

//     return ans;
//   }

// private:
//   bool isGroup(const string &s1, const string &s2) {
//     if (s1.length() != s2.length()) {
//       return false;
//     }
//     std::unordered_map<char, int> cimap;
//     for (char c : s1) {
//       cimap[c] += 1;
//     }
//     for (char c : s2) {
//       if (cimap.count(c) == 0) {
//         return false;
//       }
//       cimap[c] -= 1;
//     }
//     for (const auto &[c, cnt] : cimap) {
//       if (cnt != 0) {
//         return false;
//       }
//     }

//     return true;
//   }

//   int h(const string &s) {
//     int n = 0;
//     for (char c : s) {
//       n += c;
//       n %= 1234567;
//     }

//     return n;
//   }
// };
//