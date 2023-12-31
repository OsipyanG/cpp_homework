#include <iostream>
#include <map>
#include <string>
#include <vector>

bool Tree::Has(const std::vector<std::string>& node) const {
    const Node* currentNode = &root;
    for (const std::string& key : node) {
        auto it = currentNode->children.find(key);
        if (it == currentNode->children.end()) {
            return false;
        }
        currentNode = &it->second;
    }
    return true;
}

void Tree::Insert(const std::vector<std::string>& node) {
    Node* currentNode = &root;
    for (const std::string& key : node) {
        currentNode = &currentNode->children[key];
    }
}

void Tree::Delete(const std::vector<std::string>& node) {
    Node* currentNode = &root;
    std::vector<Node*> path;
    for (const std::string& key : node) {
        path.push_back(currentNode);
        auto it = currentNode->children.find(key);
        if (it == currentNode->children.end()) {
            return;
        }
        currentNode = &it->second;
    }

    path.back()->children.erase(node.back());
    for (int i = path.size() - 2; i >= 0; --i) {
        if (path[i]->children.size() == 0) {
            path[i + 1]->children.erase(path[i]->children.begin());
        } else {
            break;
        }
    }
}