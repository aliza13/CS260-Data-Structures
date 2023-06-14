#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;

struct Edge {
    std::string source;
    std::string destination;
    double weight;

    Edge(const std::string& src, const std::string& dest, double w) : source(src), destination(dest), weight(w) {}
};

struct CompareEdges {
    bool operator()(const Edge& e1, const Edge& e2) {
        return e1.weight > e2.weight;
    }
};

class TransactionGraph {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph; // Adjacency list representation

public:
    void addTransaction(const std::string& sender, const std::string& receiver, double amount) {
        addVertex(sender);
        addVertex(receiver);
        graph[sender].push_back({receiver, amount});
    }

    void addVertex(const std::string& vertex) {
        if (graph.find(vertex) == graph.end()) {
            graph[vertex] = std::vector<std::pair<std::string, double>>();
        }
    }

    void addEdge(const std::string& source, const std::string& destination, double amount) {
        addVertex(source);
        addVertex(destination);
        graph[source].push_back({destination, amount});
    }

    std::vector<Edge> minimumSpanningTree() {
        std::unordered_set<std::string> visited;
        std::priority_queue<Edge, std::vector<Edge>, CompareEdges> pq;
        std::vector<Edge> minimumSpanningTree;

        // Start with the first vertex in the graph
        if (!graph.empty()) {
            const std::string& startNode = graph.begin()->first;
            visited.insert(startNode);
            enqueueEdges(startNode, pq);
        }

        while (!pq.empty()) {
            const Edge& currentEdge = pq.top();
            pq.pop();

            const std::string& currentSource = currentEdge.source;
            const std::string& currentDestination = currentEdge.destination;

            // Skip this edge if it creates a cycle
            if (visited.find(currentDestination) != visited.end()) {
                continue;
            }

            visited.insert(currentDestination);
            minimumSpanningTree.push_back(currentEdge);
            enqueueEdges(currentSource, pq);

            cout << "Added edge: " << currentEdge.source << " -> " << currentEdge.destination << ", Weight: " << currentEdge.weight << endl;
        }

        return minimumSpanningTree;
    }

private:
    void enqueueEdges(const std::string& node, std::priority_queue<Edge, std::vector<Edge>, CompareEdges>& pq) {
        for (const auto& neighbor : graph[node]) {
            const std::string& nextNode = neighbor.first;
            const double weight = neighbor.second;
            pq.push(Edge(node, nextNode, weight));

            cout << "Enqueued edge: " << node << " -> " << nextNode << ", Weight: " << weight << std::endl;
        }
    }
};

int main() {
    TransactionGraph transactionGraph;

    // Example Ethereum transactions
    transactionGraph.addTransaction("Address1", "Address2", 0.01);
    transactionGraph.addTransaction("Address2", "Address3", 1.005);
    transactionGraph.addTransaction("Address1", "Address3", 0.15);
    transactionGraph.addTransaction("Address3", "Address4", 0.02);
    transactionGraph.addTransaction("Address4", "Address5", 2.01);

    cout << "Calculating the minimum spanning tree..." << endl;
    std::vector<Edge> mst = transactionGraph.minimumSpanningTree();

    // Print the edges in the minimum spanning tree
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (const auto& edge : mst) {
        cout << "Edge: " << edge.source << " -> " << edge.destination << ", Weight: " << edge.weight << endl;
    }

    return 0;
}
