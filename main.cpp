/**
 * @file main.cpp
 * @brief Interactive test suite for all custom data structures in the project.
 *
 * This file provides a menu-driven interface to test and validate the
 * functionality of all implemented data structures, including lists, stacks, and queues.
 */

#include <iostream>
#include <cassert>
#include "Doubly_Linked_List.h"
#include "Linked_List.h"
#include "Linked_List_Array.h"
#include "Array_Stack.h"
#include "Linked_Stack.h"
#include "Array_Queue.h"
#include "Linked_Queue.h"

// Helper function to print test results
void print_test_result(const char* test_name, bool passed) {
    std::cout << (passed ? "✓ " : "✗ ") << test_name << std::endl;
}

// Test Doubly Linked List
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

// Test Linked List
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

// Test Linked List Array
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

// Test Array Stack
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

// Test Linked Stack
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

// Test Array Queue
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

// Test Linked Queue
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

void print_menu() {
    std::cout << "\nData Structure Test Menu:" << std::endl;
    std::cout << "1. Test Doubly Linked List" << std::endl;
    std::cout << "2. Test Linked List" << std::endl;
    std::cout << "3. Test Linked List Array" << std::endl;
    std::cout << "4. Test Array Stack" << std::endl;
    std::cout << "5. Test Linked Stack" << std::endl;
    std::cout << "6. Test Array Queue" << std::endl;
    std::cout << "7. Test Linked Queue" << std::endl;
    std::cout << "8. Run All Tests" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

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
                std::cout << "\nRunning all tests..." << std::endl;
                test_doubly_linked_list();
                test_linked_list();
                test_linked_list_array();
                test_array_stack();
                test_linked_stack();
                test_array_queue();
                test_linked_queue();
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
