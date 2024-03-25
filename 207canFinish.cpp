#include <vector>

#include <unordered_set>
#include <unordered_map>

class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    if (prerequisites.empty()) {
      return true;
    }

    std::unordered_set<int> courses;
    for (auto &prerequisite : prerequisites) {
      courses.insert(prerequisite.front());
      graph[prerequisite.front()].push_back(prerequisite.back());
    }

    for (auto course : courses) {
      std::unordered_set<int> searched;
      if (detectCircle(course, searched)) {
        return false;
      }
    }
    
    return true;
  }

private:
  std::unordered_map<int, std::vector<int>> graph;
  std::unordered_map<int, bool> circle;

  bool detectCircle(int course, std::unordered_set<int> &searched) {
    if (circle.count(course) != 0) {
      return circle[course];
    }

    if (searched.count(course) != 0) {
      circle[course] = true;
      return true;
    }

    searched.insert(course);

    if (graph.count(course) == 0) {
      searched.erase(course);
      circle[course] = false;
      return false;
    }

    for (auto c : graph.at(course)) {
      if (detectCircle(c, searched)) {
        circle[course] = true;
        return true;
      }
    }

    searched.erase(course);
    circle[course] = false;
    return false;
  }
};
