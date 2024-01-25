#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

struct Point {
    int x, y;
};

struct Edge {
    int u, v;
};

int n, m; // n points, m segments
vector<Point> points;
vector<Edge> edges;
vector< vector<int> > vt;
int visited[MAX]; // Changed from bool to int
int cnt = 0;

void inputPoints(){
    string pointID;
    int x, y;
    while (cin >> pointID && pointID != "#") {
        cin >> x >> y;
        points.push_back({x, y});
    }
}

void inputSegments(){
    string segmentID, point1, point2;
    while (cin >> segmentID && segmentID != "#") {
        cin >> point1 >> point2;
        edges.push_back({stoi(point1.substr(1)), stoi(point2.substr(1))});
    }
}

void input(){
    inputPoints();
    inputSegments();

    n = points.size();
    m = edges.size();
    vt.resize(n + 1);

    for (const auto& edge : edges) {
        vt[edge.u].push_back(edge.v);
        vt[edge.v].push_back(edge.u);
    }
}

void explore(int x){
    visited[x] = true;
    for(int v : vt[x]){
        if(!visited[v]){
            explore(v);
        }
    }
}

void dfs(){
    for(int v=1; v<=n; v++){
        if(!visited[v]){
            cnt++;
            explore(v);
        }
    }
}

int numberPoints() {
    return n;
}

int numberSegments() {
    return m;
}

int connectedComponents() {
    cnt = 0;
    fill(visited, visited + n + 1, 0); // Changed from false to 0
    dfs();
    return cnt;
}

int dfs1(int start, int parent, int depth) {
    visited[start] = depth; // Changed from true to depth
    int longestCycle = depth;

    for (int v : vt[start]) {
        if (!visited[v]) {
            longestCycle = max(longestCycle, dfs1(v, start, depth + 1));
        } else if (v != parent) {
            // Found a cycle
            longestCycle = max(longestCycle, depth - visited[parent]); // Changed from depth - 1 to depth - visited[parent]
        }
    }

    visited[start] = 0; // Changed from false to 0
    return longestCycle;
}

int longestCycleFrom(int startPoint) {
    fill(visited, visited + n + 1, 0); // Changed from false to 0
    return dfs1(startPoint, -1, 1)-1;
}

int main(){
    input();

    string query;
    while (cin >> query && query != "###") {
        if (query == "?number_points") {
            cout << numberPoints() << endl;
        } else if (query == "?number_segments") {
            cout << numberSegments() << endl;
        } else if (query == "?connected_components") {
            cout << connectedComponents() << endl;
        } else if (query == "?longest_cycle_from") {
            string startPoint;
            cin >> startPoint;
            cout << longestCycleFrom(stoi(startPoint.substr(1))) << endl;
        }
    }

    return 0;
}
