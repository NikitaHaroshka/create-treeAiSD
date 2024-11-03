#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

//Добавление элемента
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

//Прямой левый
void Obhod(Node* root, ofstream& outputFile) {
    if (root == nullptr) {
        return;
    }
    outputFile << root->key << endl;
    Obhod(root->left, outputFile);
    Obhod(root->right, outputFile);
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile) {
        cerr << "Err in" << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Err out" << endl;
        return 1;
    }

    Node* root = nullptr;
    int key;

    while (inputFile >> key) {
        root = insert(root, key);
    }

    Obhod(root, outputFile);

    inputFile.close();
    outputFile.close();

    return 0;
}