#include <vector>
using namespace std;

class Node {
public:
    int value;
    vector<Node*> children;

    Node(int value) {
        this->value = value;
    }
};

// Tree class
class Tree {
public:
    Node* root;
    int count;

    Tree(int rootValue) {
        root = new Node(rootValue);
        count = 0;
    }

    // Add child to a parent
    void addChild(Node* parent, Node* child) {
        parent->children.push_back(child);
    }

    // DFS
    void dfs(Node* node, int currentXOR, int k) {

        // XOR with current node's value
        currentXOR = currentXOR ^ node->value;

        // Check condition
        if (currentXOR >= k) {
            count++;
        }

        // Visit all children
        for (Node* child : node->children) {
            dfs(child, currentXOR, k);
        }
    }

    int solve(int k) {
        count = 0;
        dfs(root, 0, k);
        return count;
    }
};
