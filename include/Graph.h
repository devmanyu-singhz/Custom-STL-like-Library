#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{

    private:
    unordered_map<T, list<pair<T, int>>> adj;
    bool weighted;
    bool directed;

    public:
    Graph(bool isDirected = false, bool isWeighted = false) : directed(isDirected), weighted(isWeighted) {}

    void addEdge(const T& u, const T& v, int weight = 1){
        if(!weighted){
            weight = 1;
        }
        adj[u].push_back({v, weight});

        if(!adj.count(v)){
            adj[v] = list<pair<T, int>>();
        }

        if(!directed){
            adj[v].push_back({u, weight});
        }
    }

    void print() const {
        for(const auto& pair : adj){
            cout<<pair.first<<" -> ";
            for(const auto& neighbor : pair.second){
                cout<<"("<<neighbor.first<<", "<<neighbor.second<<") ";
            }
            cout<<endl;
        }
    }

    vector<T> bfs(const T& start) const {
        vector<T>visitedOrder;
        unordered_map<T, bool>visited;
        queue<T>q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            visitedOrder.push_back(node);

            for(const auto& neighbor : adj.at(node)){
                if(!visited[neighbor.first]){
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }

        return visitedOrder;
    }

    vector<T> dfs(const T& start) const {
        vector<T> visitedOrder;
        unordered_map<T, bool>visited;
        stack<T> s;

        s.push(start);

        while(!s.empty()){
            T node = s.top();
            s.pop();

            if(!visited[node]){
                visited[node] = true;
                visitedOrder.push_back(node);

                for(auto it = adj.at(node).rbegin(); it != adj.at(node).rend(); it++){
                    if(!visited[it->first]){
                        s.push(it->first);
                    }
                }
            }
        }

        return visitedOrder;
    }

    vector<T> topologicalSort() const {
        unordered_map<T, int> indegree;
        for(const auto& pair : adj){
            if(!indegree.count(pair.first)){
                indegree[pair.first] = 0;
            }
            for(const auto& neighbor : pair.second){
                indegree[neighbor.first]++;
            }
        }

        queue<T> q;
        for(const auto& pair : indegree){
            if(pair.second == 0){
                q.push(pair.first);
            }
        }

        vector<T> result;
        while(!q.empty()){
            T node = q.front();
            q.pop();

            result.push_back(node);

            for(const auto& neighbor : adj.at(node)){
                if(--indegree[neighbor.first] == 0){
                    q.push(neighbor.first);
                }
            }
        }

        return result;
    }

    unordered_map<T, int> dijkstra(const T& source) const {
        unordered_map<T, int> dist;
        for(const auto& node : adj){
            dist[node.first] = numeric_limits<int>::max();
        }

        dist[source] = 0;
        typedef pair<int, T> P;
        priority_queue<P, vector<P>, greater<P>>pq;
        pq.push({0, source});

        while(!pq.empty()){
            T node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            for(const auto& neighbor : adj.at(node)){
                T next = neighbor.first;
                int weight = neighbor.second;
                if(dist[next] > cost + weight){
                    dist[next] = cost + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist;
    }

};

#endif//GRAPH_H