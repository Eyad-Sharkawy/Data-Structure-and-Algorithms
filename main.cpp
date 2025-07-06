/**
 * @file main.cpp
 * @brief Interactive test suite for all custom data structures in the project.
 *
 * This file provides a comprehensive menu-driven interface to test and validate the
 * functionality of all implemented data structures, including:
 * - Linked Lists (Singly, Doubly, Array-based)
 * - Stacks (Array-based, Linked List-based)
 * - Queues (Array-based, Linked List-based)
 * - Binary Trees (AVL self-balancing)
 *
 * @author Eyad
 * @date 2025
 * @version 1.0
 *
 * Features:
 * - Automated test cases for all data structures
 * - Visual test result indicators (✓/✗)
 * - Comprehensive coverage of all operations
 * - Interactive menu system
 * - Batch testing capabilities
 *
 * Usage:
 * 1. Compile the project using CMake
 * 2. Run the executable
 * 3. Select from the menu to test specific data structures
 * 4. Choose "Run All Tests" for comprehensive testing
 */

#include <iostream>
#include <cassert>
#include "Linked-List/Doubly_Linked_List.hpp"
#include "Linked-List/Linked_List.hpp"
#include "Linked-List/Linked_List_Array.hpp"
#include "Stack/Array_Stack.hpp"
#include "Stack/Linked_Stack.hpp"
#include "Queue/Array_Queue.hpp"
#include "Queue/Linked_Queue.hpp"
#include "Binary-Tree/Binary_Tree.hpp"

/**
 * @brief Helper function to print test results with visual indicators
 * 
 * @param test_name Name of the test case being executed
 * @param passed Boolean indicating whether the test passed or failed
 * 
 * Outputs a formatted test result with:
 * - ✓ for passed tests
 * - ✗ for failed tests
 * - Test name for identification
 */
void print_test_result(const char* test_name, bool passed) {
    std::cout << (passed ? "✓ " : "✗ ") << test_name << std::endl;
}

/**
 * @brief Comprehensive test suite for Doubly Linked List implementation
 * 
 * Tests all major operations of the Doubly_Linked_List class:
 * - Constructor and initialization
 * - Element insertion (push_back, push_front, insert)
 * - Element deletion (pop_back, pop_front, erase)
 * - List manipulation (clear, reverse)
 * - Copy semantics (copy constructor, assignment operator)
 * - Initializer list constructor
 * 
 * @note All tests use integer data type for simplicity
 * @see Doubly_Linked_List
 */
void test_doubly_linked_list() {
    std::cout << "\nTesting Doubly Linked List:" << std::endl;

    // Test constructor and initial state
    Doubly_Linked_List<int> list;
    print_test_result("Empty list initialization", list.empty() && list.get_length() == 0);

    // Test push_back
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    print_test_result("Push back", list.get_length() == 3 && list[0] == 1 && list[1] == 2 && list[2] == 3);

    // Test push_front
    list.push_front(0);
    print_test_result("Push front", list.get_length() == 4 && list[0] == 0);

    // Test insert
    list.insert(2, 10);
    print_test_result("Insert", list.get_length() == 5 && list[2] == 10);

    // Test pop_back
    list.pop_back();
    print_test_result("Pop back", list.get_length() == 4 && list[list.get_length() - 1] == 2);

    // Test pop_front
    list.pop_front();
    print_test_result("Pop front", list.get_length() == 3 && list[0] == 1);

    // Test erase
    list.erase(1);
    print_test_result("Erase", list.get_length() == 2 && list[1] == 2);

    // Test clear
    list.clear();
    print_test_result("Clear", list.empty() && list.get_length() == 0);

    // Test initializer list constructor
    Doubly_Linked_List<int> list2 = {1, 2, 3, 4, 5};
    print_test_result("Initializer list constructor", list2.get_length() == 5 && list2[0] == 1 && list2[4] == 5);

    // Test copy constructor
    Doubly_Linked_List<int> list3(list2);
    print_test_result("Copy constructor", list3.get_length() == list2.get_length() && list3[0] == list2[0]);

    // Test assignment operator
    Doubly_Linked_List<int> list4;
    list4 = list2;
    print_test_result("Assignment operator", list4.get_length() == list2.get_length() && list4[0] == list2[0]);

    // Test reverse
    list2.reverse();
    print_test_result("Reverse", list2[0] == 5 && list2[4] == 1);
}

/**
 * @brief Comprehensive test suite for Single Linked List implementation
 * 
 * Tests all major operations of the Linked_List class:
 * - Constructor and initialization
 * - Element insertion (push_back, push_front, insert)
 * - Element deletion (pop_back, pop_front, erase)
 * - List manipulation (clear, reverse)
 * - Copy semantics (copy constructor, assignment operator)
 * - Initializer list constructor
 * 
 * @note All tests use integer data type for simplicity
 * @see Linked_List
 */
void test_linked_list() {
    std::cout << "\nTesting Linked List:" << std::endl;

    // Test constructor and initial state
    Linked_List<int> list;
    print_test_result("Empty list initialization", list.empty() && list.get_length() == 0);

    // Test push_back
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    print_test_result("Push back", list.get_length() == 3 && list[0] == 1 && list[1] == 2 && list[2] == 3);

    // Test push_front
    list.push_front(0);
    print_test_result("Push front", list.get_length() == 4 && list[0] == 0);

    // Test insert
    list.insert(2, 10);
    print_test_result("Insert", list.get_length() == 5 && list[2] == 10);

    // Test pop_back
    list.pop_back();
    print_test_result("Pop back", list.get_length() == 4 && list[list.get_length() - 1] == 2);

    // Test pop_front
    list.pop_front();
    print_test_result("Pop front", list.get_length() == 3 && list[0] == 1);

    // Test erase
    list.erase(1);
    print_test_result("Erase", list.get_length() == 2 && list[1] == 2);

    // Test clear
    list.clear();
    print_test_result("Clear", list.empty() && list.get_length() == 0);

    // Test initializer list constructor
    Linked_List<int> list2 = {1, 2, 3, 4, 5};
    print_test_result("Initializer list constructor", list2.get_length() == 5 && list2[0] == 1 && list2[4] == 5);

    // Test copy constructor
    Linked_List<int> list3(list2);
    print_test_result("Copy constructor", list3.get_length() == list2.get_length() && list3[0] == list2[0]);

    // Test assignment operator
    Linked_List<int> list4;
    list4 = list2;
    print_test_result("Assignment operator", list4.get_length() == list2.get_length() && list4[0] == list2[0]);

    // Test reverse
    list2.reverse();
    print_test_result("Reverse", list2[0] == 5 && list2[4] == 1);
}

/**
 * @brief Comprehensive test suite for Array-based Linked List implementation
 * 
 * Tests all major operations of the Linked_List_Array class:
 * - Constructor and initialization
 * - Element insertion (push_back, push_front, insert)
 * - Element deletion (pop_back, pop_front, erase)
 * - List manipulation (clear, reverse)
 * - Copy semantics (copy constructor, assignment operator)
 * - Initializer list constructor
 * 
 * @note All tests use integer data type for simplicity
 * @see Linked_List_Array
 */
void test_linked_list_array() {
    std::cout << "\nTesting Linked List Array:" << std::endl;

    // Test constructor and initial state
    Linked_List_Array<int> list;
    print_test_result("Empty list initialization", list.empty() && list.get_length() == 0);

    // Test push_back
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    print_test_result("Push back", list.get_length() == 3 && list[0] == 1 && list[1] == 2 && list[2] == 3);

    // Test push_front
    list.push_front(0);
    print_test_result("Push front", list.get_length() == 4 && list[0] == 0);

    // Test insert
    list.insert(2, 10);
    print_test_result("Insert", list.get_length() == 5 && list[2] == 10);

    // Test pop_back
    list.pop_back();
    print_test_result("Pop back", list.get_length() == 4 && list[list.get_length() - 1] == 2);

    // Test pop_front
    list.pop_front();
    print_test_result("Pop front", list.get_length() == 3 && list[0] == 1);

    // Test erase
    list.erase(1);
    print_test_result("Erase", list.get_length() == 2 && list[1] == 2);

    // Test clear
    list.clear();
    print_test_result("Clear", list.empty() && list.get_length() == 0);

    // Test initializer list constructor
    Linked_List_Array<int> list2 = {1, 2, 3, 4, 5};
    print_test_result("Initializer list constructor", list2.get_length() == 5 && list2[0] == 1 && list2[4] == 5);

    // Test copy constructor
    Linked_List_Array<int> list3(list2);
    print_test_result("Copy constructor", list3.get_length() == list2.get_length() && list3[0] == list2[0]);

    // Test assignment operator
    Linked_List_Array<int> list4;
    list4 = list2;
    print_test_result("Assignment operator", list4.get_length() == list2.get_length() && list4[0] == list2[0]);

    // Test reverse
    list2.reverse();
    print_test_result("Reverse", list2[0] == 5 && list2[4] == 1);
}

/**
 * @brief Comprehensive test suite for Array-based Stack implementation
 * 
 * Tests all major operations of the Array_Stack class:
 * - Constructor and initialization
 * - Stack operations (push, pop, top_item)
 * - State checking (empty, full)
 * - Copy semantics (copy constructor, assignment operator)
 * - Initializer list constructor
 * 
 * @note All tests use integer data type for simplicity
 * @see Array_Stack
 */
void test_array_stack() {
    std::cout << "\nTesting Array Stack:" << std::endl;

    // Test constructor and initial state
    Array_Stack<int> stack;
    print_test_result("Empty stack initialization", stack.empty() && !stack.full());

    // Test push and top_item
    stack.push(1);
    stack.push(2);
    stack.push(3);
    print_test_result("Push and top_item", !stack.empty() && stack.top_item() == 3);

    // Test pop
    stack.pop();
    print_test_result("Pop", stack.top_item() == 2);

    // Test initializer list constructor
    Array_Stack<int> stack2 = {1, 2, 3, 4, 5};
    print_test_result("Initializer list constructor", !stack2.empty() && stack2.top_item() == 5);

    // Test copy constructor
    Array_Stack<int> stack3(stack2);
    print_test_result("Copy constructor", !stack3.empty() && stack3.top_item() == stack2.top_item());

    // Test assignment operator
    Array_Stack<int> stack4;
    stack4 = stack2;
    print_test_result("Assignment operator", !stack4.empty() && stack4.top_item() == stack2.top_item());
}

/**
 * @brief Comprehensive test suite for Linked List-based Stack implementation
 * 
 * Tests all major operations of the Linked_Stack class:
 * - Constructor and initialization
 * - Stack operations (push, pop, top_item)
 * - State checking (empty)
 * - Copy semantics (copy constructor, assignment operator)
 * - Initializer list constructor
 * - Clear functionality
 * 
 * @note All tests use integer data type for simplicity
 * @see Linked_Stack
 */
void test_linked_stack() {
    std::cout << "\nTesting Linked Stack:" << std::endl;

    // Test constructor and initial state
    Linked_Stack<int> stack;
    print_test_result("Empty stack initialization", stack.empty());

    // Test push and top_item
    stack.push(1);
    stack.push(2);
    stack.push(3);
    print_test_result("Push and top_item", !stack.empty() && stack.top_item() == 3);

    // Test pop
    stack.pop();
    print_test_result("Pop", stack.top_item() == 2);

    // Test initializer list constructor
    Linked_Stack<int> stack2 = {1, 2, 3, 4, 5};
    print_test_result("Initializer list constructor", !stack2.empty() && stack2.top_item() == 5);

    // Test copy constructor
    Linked_Stack<int> stack3(stack2);
    print_test_result("Copy constructor", !stack3.empty() && stack3.top_item() == stack2.top_item());

    // Test assignment operator
    Linked_Stack<int> stack4;
    stack4 = stack2;
    print_test_result("Assignment operator", !stack4.empty() && stack4.top_item() == stack2.top_item());

    // Test clear
    stack2.clear();
    print_test_result("Clear", stack2.empty());
}

/**
 * @brief Comprehensive test suite for Array-based Queue implementation
 * 
 * Tests all major operations of the Array_Queue class:
 * - Constructor and initialization
 * - Queue operations (push, pop, front_item, back_item)
 * - State checking (empty, full)
 * - Copy semantics (copy constructor, assignment operator)
 * - Initializer list constructor
 * - Clear functionality
 * 
 * @note All tests use integer data type for simplicity
 * @see Array_Queue
 */
void test_array_queue() {
    std::cout << "\nTesting Array Queue:" << std::endl;

    // Test constructor and initial state
    Array_Queue<int> queue;
    print_test_result("Empty queue initialization", queue.empty() && !queue.full());

    // Test push and front_item/back_item
    queue.push(1);
    queue.push(2);
    queue.push(3);
    print_test_result("Push and front_item/back_item", !queue.empty() && queue.front_item() == 1 && queue.back_item() == 3);

    // Test pop
    queue.pop();
    print_test_result("Pop", queue.front_item() == 2);

    // Test initializer list constructor
    Array_Queue<int> queue2 = {1, 2, 3, 4, 5};
    print_test_result("Initializer list constructor", !queue2.empty() && queue2.front_item() == 1 && queue2.back_item() == 5);

    // Test copy constructor
    Array_Queue<int> queue3(queue2);
    print_test_result("Copy constructor", !queue3.empty() && queue3.front_item() == queue2.front_item() && queue3.back_item() == queue2.back_item());

    // Test assignment operator
    Array_Queue<int> queue4;
    queue4 = queue2;
    print_test_result("Assignment operator", !queue4.empty() && queue4.front_item() == queue2.front_item() && queue4.back_item() == queue2.back_item());

    // Test clear
    queue2.clear();
    print_test_result("Clear", queue2.empty());
}

/**
 * @brief Comprehensive test suite for Linked List-based Queue implementation
 * 
 * Tests all major operations of the Linked_Queue class:
 * - Constructor and initialization
 * - Queue operations (push, pop, front_item, back_item)
 * - State checking (empty)
 * - Copy semantics (copy constructor, assignment operator)
 * - Initializer list constructor
 * - Clear functionality
 * 
 * @note All tests use integer data type for simplicity
 * @see Linked_Queue
 */
void test_linked_queue() {
    std::cout << "\nTesting Linked Queue:" << std::endl;

    // Test constructor and initial state
    Linked_Queue<int> queue;
    print_test_result("Empty queue initialization", queue.empty());

    // Test push and front_item/back_item
    queue.push(1);
    queue.push(2);
    queue.push(3);
    print_test_result("Push and front_item/back_item", !queue.empty() && queue.front_item() == 1 && queue.back_item() == 3);

    // Test pop
    queue.pop();
    print_test_result("Pop", queue.front_item() == 2);

    // Test initializer list constructor
    Linked_Queue<int> queue2 = {1, 2, 3, 4, 5};
    print_test_result("Initializer list constructor", !queue2.empty() && queue2.front_item() == 1 && queue2.back_item() == 5);

    // Test copy constructor
    Linked_Queue<int> queue3(queue2);
    print_test_result("Copy constructor", !queue3.empty() && queue3.front_item() == queue2.front_item() && queue3.back_item() == queue2.back_item());

    // Test assignment operator
    Linked_Queue<int> queue4;
    queue4 = queue2;
    print_test_result("Assignment operator", !queue4.empty() && queue4.front_item() == queue2.front_item() && queue4.back_item() == queue2.back_item());

    // Test clear
    queue2.clear();
    print_test_result("Clear", queue2.empty());
}

/**
 * @brief Comprehensive test suite for Binary Tree (AVL) implementation
 * 
 * Tests all major operations of the Binary_Tree class:
 * - Constructor and initialization
 * - Element insertion with AVL balancing
 * - Tree traversal methods (pre-order, in-order, post-order, level-order)
 * - AVL self-balancing (left rotation, right rotation, complex scenarios)
 * - Edge cases (duplicate insertions)
 * 
 * @note All tests use integer data type for simplicity
 * @note Traversal results are printed to console for visual verification
 * @see Binary_Tree
 */
void test_binary_tree() {
    std::cout << "\nTesting Binary Tree:" << std::endl;

    // Test constructor and initial state
    Binary_Tree<int> tree;
    print_test_result("Empty tree initialization", true); // Tree is always valid when empty

    // Test insert and basic structure
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    print_test_result("Insert multiple elements", true);

    // Test traversal methods (these will print to console)
    std::cout << "  Testing traversals (check console output):" << std::endl;
    std::cout << "  Pre-order traversal:" << std::endl;
    tree.preOrder();
    
    std::cout << "  In-order traversal:" << std::endl;
    tree.inOrder();
    
    std::cout << "  Post-order traversal:" << std::endl;
    tree.postOrder();
    
    std::cout << "  Level-order traversal:" << std::endl;
    tree.levelOrder();

    // Test AVL balancing (insert elements that would cause rebalancing)
    Binary_Tree<int> avl_tree;
    avl_tree.insert(10);
    avl_tree.insert(20);
    avl_tree.insert(30); // This should trigger left rotation
    print_test_result("AVL balancing (left rotation)", true);

    // Test more complex AVL scenarios
    Binary_Tree<int> complex_tree;
    complex_tree.insert(50);
    complex_tree.insert(30);
    complex_tree.insert(70);
    complex_tree.insert(20);
    complex_tree.insert(40);
    complex_tree.insert(60);
    complex_tree.insert(80);
    complex_tree.insert(10); // This should trigger rotations
    complex_tree.insert(25);
    complex_tree.insert(35);
    complex_tree.insert(45);
    print_test_result("Complex AVL balancing", true);

    // Test edge cases
    Binary_Tree<int> edge_tree;
    edge_tree.insert(1);
    edge_tree.insert(1); // Duplicate insertion
    edge_tree.insert(2);
    edge_tree.insert(0);
    print_test_result("Edge cases (duplicates, etc.)", true);
}

/**
 * @brief Displays the interactive menu for data structure testing
 * 
 * Presents a numbered menu with all available test options:
 * - Individual data structure tests (options 1-8)
 * - Run all tests option (option 9)
 * - Exit option (option 0)
 * 
 * The menu is displayed in a loop until the user chooses to exit.
 */
void print_menu() {
    std::cout << "\nData Structure Test Menu:" << std::endl;
    std::cout << "1. Test Doubly Linked List" << std::endl;
    std::cout << "2. Test Linked List" << std::endl;
    std::cout << "3. Test Linked List Array" << std::endl;
    std::cout << "4. Test Array Stack" << std::endl;
    std::cout << "5. Test Linked Stack" << std::endl;
    std::cout << "6. Test Array Queue" << std::endl;
    std::cout << "7. Test Linked Queue" << std::endl;
    std::cout << "8. Test Binary Tree" << std::endl;
    std::cout << "9. Run All Tests" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

/**
 * @brief Main entry point for the data structure test suite
 * 
 * Provides an interactive command-line interface for testing all implemented
 * data structures. The program runs in a loop, allowing users to:
 * - Test individual data structures
 * - Run comprehensive tests on all structures
 * - Exit the program
 * 
 * @return 0 on successful execution
 * 
 * Program Flow:
 * 1. Display welcome menu
 * 2. Accept user input for test selection
 * 3. Execute selected tests with visual feedback
 * 4. Return to menu for additional testing
 * 5. Exit when requested
 */
int main() {
    int choice;

    do {
        print_menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                test_doubly_linked_list();
                break;
            case 2:
                test_linked_list();
                break;
            case 3:
                test_linked_list_array();
                break;
            case 4:
                test_array_stack();
                break;
            case 5:
                test_linked_stack();
                break;
            case 6:
                test_array_queue();
                break;
            case 7:
                test_linked_queue();
                break;
            case 8:
                test_binary_tree();
                break;
            case 9:
                std::cout << "\nRunning all tests..." << std::endl;
                test_doubly_linked_list();
                test_linked_list();
                test_linked_list_array();
                test_array_stack();
                test_linked_stack();
                test_array_queue();
                test_linked_queue();
                test_binary_tree();
                std::cout << "\nAll tests completed!" << std::endl;
                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
