#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int>> adj;
vector<bool> visited;
stack<long long int> st;

void addEdge(long long int x , long long int y) {
    adj[x].push_back(y);
}

void topologicalSort(long long int node) {
    visited[node] = true;
    for(long long int i = 0 ; i < adj[node].size() ; i++) {
        if(!visited[adj[node][i]]) {
            topologicalSort(adj[node][i]);
        }
    }
    st.push(node);
}

int main() {
    long long int n , m , i , x , y;
    cin >> n >> m;
    adj = vector<vector<long long int>> (n+1);
    visited = vector<bool> (n+1);
    for(i = 0 ; i < m ; i++) {
        cin >> x >> y;
        addEdge(x , y);
    }
    for(i = 0 ; i < n ; i++) {
        if(!visited[i])
            topologicalSort(i);
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
