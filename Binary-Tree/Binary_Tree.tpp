/**
 * @file Binary_Tree.tpp
 * @brief Implementation of the AVL Self-Balancing Binary Search Tree
 * 
 * This file contains the complete implementation of all methods declared
 * in Binary_Tree.hpp. The implementation includes:
 * - Node construction and tree initialization
 * - Four types of tree traversals
 * - AVL balancing with four rotation cases
 * - Successor finding algorithms
 * - Height and balance factor calculations
 * 
 * @author Eyad
 * @date 2025-06-18
 * @version 1.0
 * 
 * Implementation Notes:
 * - All rotations maintain parent pointers for efficient navigation
 * - Height is updated after each insertion and rotation
 * - Balance factors are calculated using height differences
 * - Duplicate insertions are handled gracefully (no insertion)
 * - Memory management is handled by the calling code
 */

#pragma once

#include "Binary_Tree.hpp"
#include <queue>
#include <iostream>
using namespace std;


/**
 * @brief Constructs a new node with the given data
 * 
 * Initializes all pointers to nullptr and sets height to 0.
 * The node is ready to be inserted into the tree.
 * 
 * @param data The data to store in the node
 */
template<class T>
Binary_Tree<T>::Node::Node(T data): data(data), left(nullptr), right(nullptr), parent(nullptr), height(0) {}

/**
 * @brief Default constructor for the AVL tree
 * 
 * Creates an empty tree with no nodes. The root pointer is set to nullptr.
 */
template<class T>
Binary_Tree<T>::Binary_Tree(): root(nullptr) {}

/**
 * @brief Performs pre-order traversal (Root -> Left -> Right)
 * 
 * Visits the current node first, then recursively traverses the left subtree,
 * and finally the right subtree. This order is useful for creating a copy
 * of the tree or evaluating prefix expressions.
 * 
 * @param ptr Starting node for traversal
 */
template<class T>
void Binary_Tree<T>::preOrder(Node *ptr) {
    if (ptr == nullptr) return;
        cout << ptr->data << endl;
        preOrder(ptr->left);
        preOrder(ptr->right);
}

/**
 * @brief Performs in-order traversal (Left -> Root -> Right)
 * 
 * Recursively traverses the left subtree, visits the current node,
 * then traverses the right subtree. For a BST, this produces
 * elements in sorted order.
 * 
 * @param ptr Starting node for traversal
 */
template<class T>
void Binary_Tree<T>::inOrder(Node *ptr) {
    if (ptr == nullptr) return;
        inOrder(ptr->left);
        cout << ptr->data << endl;
        inOrder(ptr->right);
}

/**
 * @brief Performs post-order traversal (Left -> Right -> Root)
 * 
 * Recursively traverses the left subtree, then the right subtree,
 * and finally visits the current node. This order is useful for
 * deleting nodes or evaluating postfix expressions.
 * 
 * @param ptr Starting node for traversal
 */
template<class T>
void Binary_Tree<T>::postOrder(Node *ptr) {
    if (ptr == nullptr) return;
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << endl;
}

/**
 * @brief Performs level-order (breadth-first) traversal
 * 
 * Visits nodes level by level, from left to right. Uses a queue to maintain
 * the traversal order. This traversal is useful for finding the shortest path
 * or printing the tree in a hierarchical format.
 * 
 * @param ptr Starting node for traversal
 */
template<class T>
void Binary_Tree<T>::levelOrder(Node *ptr) {
    if (ptr == nullptr) return;
    queue<Node*> q;
    q.emplace(ptr);
    while (!q.empty()) {
        Node* curr = q.front();
        cout << curr->data << endl;
        if (curr->left != nullptr) q.emplace(curr->left);
        if (curr->right != nullptr) q.emplace(curr->right);
        q.pop();
    }
}

/**
 * @brief Finds the minimum value in the subtree rooted at the given node
 * 
 * In a BST, the minimum value is always in the leftmost node of the subtree.
 * This method traverses down the left path until it reaches a leaf node.
 * 
 * @param ptr Root of the subtree to search
 * @return Pointer to the node with minimum value, or nullptr if subtree is empty
 */
template<class T>
typename Binary_Tree<T>::Node *Binary_Tree<T>::findMin(Node *ptr) {
    if (ptr == nullptr) return nullptr;
    while (ptr->left != nullptr) {
        ptr = ptr->left;
    }
    return ptr;
}

/**
 * @brief Finds the successor of a given node
 * 
 * The successor is the next larger element in the tree. There are two cases:
 * 1. If the node has a right child: successor is the minimum of the right subtree
 * 2. If the node has no right child: successor is the first ancestor that is
 *    a left child of its parent (i.e., the first ancestor where we came from the left)
 * 
 * @param ptr Node whose successor to find
 * @return Pointer to the successor node, or nullptr if no successor exists
 */
template<class T>
typename Binary_Tree<T>::Node *Binary_Tree<T>::findSuccessor(Node *ptr) {
    if (ptr == nullptr) return nullptr;

    if (ptr->right != nullptr) {
        return findMin(ptr->right);
    }

    Node* ptrParent = ptr->parent;
    Node* curr = ptr;

    while (ptrParent != nullptr && curr == ptrParent->right) {
        curr = ptrParent;
        ptrParent = ptrParent->parent;
    }

    return ptrParent;
}

/**
 * @brief Calculates the height of a node
 * 
 * Returns -1 for nullptr nodes (empty subtrees) and the stored height
 * for actual nodes. This convention allows for easy height calculations
 * in the balancing logic.
 * 
 * @param ptr Pointer to the node (can be nullptr)
 * @return Height of the node (-1 for nullptr, actual height otherwise)
 */
template<class T>
int Binary_Tree<T>::height(Node *ptr) {
    return  (ptr == nullptr) ? -1 : ptr->height;
}

/**
 * @brief Calculates the balance factor of a node
 * 
 * The balance factor is defined as: height(left subtree) - height(right subtree)
 * For an AVL tree to be balanced, the absolute value of the balance factor
 * must be ≤ 1 for all nodes.
 * 
 * @param ptr Pointer to the node (can be nullptr)
 * @return Balance factor = height(left) - height(right)
 */
template<class T>
int Binary_Tree<T>::getBalance(Node *ptr) {
    return (ptr == nullptr) ? -1 : height(ptr->left) - height(ptr->right);
}

/**
 * @brief Performs a right rotation around the given node
 * 
 * Right rotation is used to balance the tree when the left subtree is too tall.
 * The operation involves:
 * 1. Making the left child (x) the new root of the subtree
 * 2. Moving the original root (y) to be the right child of x
 * 3. Moving x's right subtree (T2) to be y's left subtree
 * 4. Updating all parent pointers and heights
 * 
 * @param y The node around which to perform the rotation
 * @return Pointer to the new root of the rotated subtree
 */
template<class T>
typename Binary_Tree<T>::Node *Binary_Tree<T>::rightRotate(Node *y) {
    if (y == nullptr || y->left == nullptr) {
        return y;
    }
    
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    x->parent = y->parent;
    y->parent = x;
    y->left = T2;

    if (T2 != nullptr) {
        T2->parent = y;
    }

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return x;
}

/**
 * @brief Performs a left rotation around the given node
 * 
 * Left rotation is used to balance the tree when the right subtree is too tall.
 * The operation involves:
 * 1. Making the right child (y) the new root of the subtree
 * 2. Moving the original root (x) to be the left child of y
 * 3. Moving y's left subtree (T2) to be x's right subtree
 * 4. Updating all parent pointers and heights
 * 
 * @param x The node around which to perform the rotation
 * @return Pointer to the new root of the rotated subtree
 */
template<class T>
typename Binary_Tree<T>::Node *Binary_Tree<T>::leftRotate(Node *x) {
    if (x == nullptr || x->right == nullptr) {
        return x;
    }
    
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    y->parent = x->parent;
    x->parent = y;
    x->right = T2;

    if (T2 != nullptr) {
        T2->parent = x;
    }

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return y;
}

/**
 * @brief Public interface for inserting a new element into the tree
 * 
 * This is the main insertion method that users call to add elements to the tree.
 * It delegates to the private recursive insertion method and handles the root
 * pointer update.
 * 
 * @param data The data to insert into the tree
 */
template<class T>
void Binary_Tree<T>::insert(T data) {
    this->root = insert(this->root, data, nullptr);
}

/**
 * @brief Recursively inserts a new element into the tree with AVL balancing
 * 
 * This is the core insertion algorithm that:
 * 1. Recursively finds the correct position for the new element
 * 2. Creates a new node and links it into the tree
 * 3. Updates heights of all affected nodes
 * 4. Checks balance factors and performs rotations if necessary
 * 
 * The four AVL rotation cases are handled:
 * - Left-Left: Single right rotation
 * - Right-Right: Single left rotation  
 * - Left-Right: Double rotation (left then right)
 * - Right-Left: Double rotation (right then left)
 * 
 * @param ptr Current node in the recursion
 * @param data Data to insert
 * @param parent Parent of the current node
 * @return Pointer to the root of the modified subtree
 */
template<class T>
typename Binary_Tree<T>::Node *Binary_Tree<T>::insert(Node *ptr, T data, Node *parent) {
    if ((ptr == nullptr)) {
        Node* newNode = new Node(data);
        newNode->parent = parent;
        return newNode;
    }

    if (data < ptr->data) {
        ptr->left = insert(ptr->left, data, ptr);
    }
    else if (data > ptr->data) {
        ptr->right = insert(ptr->right, data, ptr);
    }
    else {
        return ptr;
    }

    ptr->height = 1 + max(height(ptr->left), height(ptr->right));
    const int balance =  getBalance(ptr);

    // Left-Left Case
    if (balance > 1 && ptr->left && data < ptr->left->data) {
        return rightRotate(ptr);
    }

    // Right-Right Case
    if (balance < -1 && ptr->right && data > ptr->right->data) {
        return leftRotate(ptr);
    }

    // Left-Right Case
    if (balance > 1 && ptr->left && data > ptr->left->data) {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }

    // Right-Left Case
    if (balance < -1 && ptr->right && data < ptr->right->data) {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }

    return ptr;
}
