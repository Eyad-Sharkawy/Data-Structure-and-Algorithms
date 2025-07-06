/**
 * @file Binary_Tree.hpp
 * @brief AVL (Adelson-Velsky and Landis) Self-Balancing Binary Search Tree Implementation
 * 
 * This file contains the interface for a self-balancing binary search tree that maintains
 * height balance through AVL rotations. The tree automatically rebalances itself after
 * insertions to ensure O(log n) time complexity for all operations.
 * 
 * @author Eyad
 * @date 2025-06-18
 * @version 1.0
 * 
 * Features:
 * - Automatic height balancing after insertions
 * - Four types of tree traversals
 * - Successor finding functionality
 * - Parent pointer maintenance for efficient navigation
 * - Template-based implementation for any comparable data type
 * 
 * Time Complexity:
 * - Insertion: O(log n)
 * - Search: O(log n)
 * - Traversal: O(n)
 * - Successor finding: O(log n)
 * 
 * Space Complexity: O(n)
 * 
 * AVL Balancing Rules:
 * - Balance factor = height(left subtree) - height(right subtree)
 * - Tree is balanced if |balance factor| ≤ 1 for all nodes
 * - Four rotation cases: Left-Left, Right-Right, Left-Right, Right-Left
 */

#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

/**
 * @brief AVL Self-Balancing Binary Search Tree
 * 
 * A template-based implementation of an AVL tree that automatically maintains
 * height balance through rotations. This ensures optimal performance for all
 * tree operations.
 * 
 * @tparam T The data type stored in the tree nodes. Must support comparison operators.
 */
template<class T>
class Binary_Tree {
private:
    /**
     * @brief Internal node structure for the AVL tree
     * 
     * Each node contains the data, pointers to left and right children,
     * a parent pointer for efficient navigation, and height information
     * for balancing calculations.
     */
    struct Node {
        T data;           ///< The data stored in this node
        Node* left;       ///< Pointer to left child (nullptr if no left child)
        Node* right;      ///< Pointer to right child (nullptr if no right child)
        Node* parent;     ///< Pointer to parent node (nullptr for root)
        int height;       ///< Height of the subtree rooted at this node

        /**
         * @brief Constructs a new node with the given data
         * @param data The data to store in the node
         */
        explicit Node(T data);
    };
    
    Node* root;  ///< Pointer to the root node of the tree (nullptr if tree is empty)

    /**
     * @brief Calculates the height of a node
     * @param ptr Pointer to the node (can be nullptr)
     * @return Height of the node (-1 for nullptr, actual height otherwise)
     */
    static int height(Node *ptr);
    
    /**
     * @brief Calculates the balance factor of a node
     * @param ptr Pointer to the node (can be nullptr)
     * @return Balance factor = height(left) - height(right)
     */
    int getBalance(Node *ptr);
    
    /**
     * @brief Performs a right rotation around the given node
     * @param y The node around which to perform the rotation
     * @return Pointer to the new root of the rotated subtree
     */
    Node* rightRotate(Node* y);
    
    /**
     * @brief Performs a left rotation around the given node
     * @param x The node around which to perform the rotation
     * @return Pointer to the new root of the rotated subtree
     */
    Node* leftRotate(Node* x);
    
    /**
     * @brief Recursively inserts a new element into the tree
     * @param ptr Current node in the recursion
     * @param data Data to insert
     * @param parent Parent of the current node
     * @return Pointer to the root of the modified subtree
     */
    Node* insert(Node* ptr, T data, Node* parent);

public:
    /**
     * @brief Default constructor
     * 
     * Creates an empty AVL tree with no nodes.
     */
    Binary_Tree();

    /**
     * @brief Performs pre-order traversal starting from a specific node
     * @param ptr Starting node for traversal (can be nullptr)
     * 
     * Pre-order traversal visits nodes in the order: Root -> Left -> Right
     * Outputs each node's data to std::cout
     */
    void preOrder(Node *ptr);
    
    /**
     * @brief Performs in-order traversal starting from a specific node
     * @param ptr Starting node for traversal (can be nullptr)
     * 
     * In-order traversal visits nodes in the order: Left -> Root -> Right
     * For a BST, this produces elements in sorted order
     * Outputs each node's data to std::cout
     */
    void inOrder(Node *ptr);
    
    /**
     * @brief Performs post-order traversal starting from a specific node
     * @param ptr Starting node for traversal (can be nullptr)
     * 
     * Post-order traversal visits nodes in the order: Left -> Right -> Root
     * Useful for deleting nodes or evaluating expressions
     * Outputs each node's data to std::cout
     */
    void postOrder(Node *ptr);
    
    /**
     * @brief Performs level-order (breadth-first) traversal starting from a specific node
     * @param ptr Starting node for traversal (can be nullptr)
     * 
     * Level-order traversal visits nodes level by level, from left to right
     * Uses a queue to maintain the traversal order
     * Outputs each node's data to std::cout
     */
    void levelOrder(Node *ptr);

    /**
     * @brief Finds the minimum value in the subtree rooted at the given node
     * @param ptr Root of the subtree to search (can be nullptr)
     * @return Pointer to the node with minimum value, or nullptr if subtree is empty
     * 
     * In a BST, the minimum value is always in the leftmost node
     */
    static Node* findMin(Node *ptr);
    
    /**
     * @brief Finds the successor of a given node
     * @param ptr Node whose successor to find (can be nullptr)
     * @return Pointer to the successor node, or nullptr if no successor exists
     * 
     * The successor is the next larger element in the tree.
     * If the node has a right child, the successor is the minimum of the right subtree.
     * Otherwise, it's the first ancestor that is a left child of its parent.
     */
    Node* findSuccessor(Node* ptr);
    
    /**
     * @brief Inserts a new element into the tree
     * @param data The data to insert
     * 
     * Inserts the element while maintaining the BST property and AVL balance.
     * Duplicate elements are ignored (no insertion occurs).
     * Automatically performs rotations if necessary to maintain balance.
     */
    void insert(T data);

    /**
     * @brief Performs pre-order traversal of the entire tree
     * 
     * Convenience method that starts traversal from the root.
     * @see preOrder(Node*)
     */
    void preOrder() { preOrder(this->root); }
    
    /**
     * @brief Performs in-order traversal of the entire tree
     * 
     * Convenience method that starts traversal from the root.
     * @see inOrder(Node*)
     */
    void inOrder() { inOrder(this->root); }
    
    /**
     * @brief Performs post-order traversal of the entire tree
     * 
     * Convenience method that starts traversal from the root.
     * @see postOrder(Node*)
     */
    void postOrder() { postOrder(this->root); }
    
    /**
     * @brief Performs level-order traversal of the entire tree
     * 
     * Convenience method that starts traversal from the root.
     * @see levelOrder(Node*)
     */
    void levelOrder() { levelOrder(this->root); }
};


#include "Binary_Tree.tpp"
#endif //BINARY_TREE_HPP
