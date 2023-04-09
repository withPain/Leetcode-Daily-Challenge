class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.length();
    int ans = 0;
    int processed = 0;
    vector<vector<int>> graph(n);
    vector<int> inDegree(n);
    queue<int> q;
    vector<vector<int>> count(n, vector<int>(26));

    // Build graph
    for (const vector<int>& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      graph[u].push_back(v);
      ++inDegree[v];
    }

    // Topology
    for (int i = 0; i < n; ++i)
      if (inDegree[i] == 0)
        q.push(i);

    while (!q.empty()) {
      int out = q.front();
      q.pop();
      ++processed;
      ans = max(ans, ++count[out][colors[out] - 'a']);
      for (auto in : graph[out]) {
        for (int i = 0; i < 26; ++i)
          count[in][i] = max(count[in][i], count[out][i]);
        if (--inDegree[in] == 0)
          q.push(in);
      }
    }

    return processed == n ? ans : -1;
  }
};