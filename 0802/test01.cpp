// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
// 在选修某些课程之前需要一些先修课程。 
// 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
#include <iostream>
#include <vector>
#include <queue>

// 拓扑排序方法
bool canFinish1(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> graph(numCourses);
    std::vector<int> degree(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); ++i) {
        int from = prerequisites[i][1];
        int to = prerequisites[i][0];
        graph[from].push_back(to);
        degree[to]++;
    }
    std::queue<int> q;
    for (int i = 0; i < degree.size(); ++i) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    int visited = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        visited++;
        for (int num: graph[top]) {
            degree[num]--;
            if (degree[num] == 0) {
                q.push(num);
            }
        }
    }
    return visited == numCourses;
}

bool hasCircle(int curvetex, std::vector<int>& state, std::vector<std::vector<int>>& graph) {
    if (state[curvetex] == 2) {
        return false;
    }
    if (state[curvetex] == 1) {
        return true;
    }
    state[curvetex] = 1;
    for (int v: graph[curvetex]) {
        if (hasCircle(v, state, graph)) {
            return true;
        }
    }
    state[curvetex] = 2;
    return false;
}

// dfs法
bool canFinish2(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    // 建图
    std::vector<std::vector<int>> graph(numCourses);
    for (int i = 0; i < prerequisites.size(); ++i) {
        int from = prerequisites[i][1];
        int to = prerequisites[i][0];
        graph[from].push_back(to);
    }
    // 访问状态，0-未访问，1-访问中，2-已访问
    std::vector<int> state(numCourses, 0);
    for (int i = 0; i < numCourses; ++i) {
        if (hasCircle(i, state, graph)) {
            return false;
        }
    }
    return true;
}

int main() {
    int numCourses = 2;
    std::vector<std::vector<int>> prerequisites = {{1, 0}, {0, 1}};
    bool res1 = canFinish1(numCourses, prerequisites);
    bool res2 = canFinish2(numCourses, prerequisites);
    std::cout << res1 << ", " << res2 << "\n";
}