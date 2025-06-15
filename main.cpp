#include <iostream>
#include <cassert>
#include <string>
#include "Doubly_Linked_List.h"

// Simple test framework
#define TEST_CASE(name) std::cout << "\n=== Testing " << name << " ===\n"
#define ASSERT(condition) assert(condition)
#define ASSERT_EQUAL(expected, actual) assert((expected) == (actual))
#define ASSERT_THROWS(expression, exception_type) try { expression; assert(false); } catch (const exception_type&) {}

// Helper function to print test results
void print_test_result(const std::string& test_name, bool passed) {
    std::cout << (passed ? "✓ " : "✗ ") << test_name << std::endl;
}

int main() {
    // Test 1: Default Constructor and Basic Operations
    TEST_CASE("Default Constructor and Basic Operations");
    {
        Doubly_Linked_List<int> list;
        ASSERT(list.empty());
        ASSERT_EQUAL(0, list.get_length());
        print_test_result("Default constructor creates empty list", true);
    }

    // Test 2: Push Operations
    TEST_CASE("Push Operations");
    {
        Doubly_Linked_List<int> list;
        
        // Test push_back
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
        ASSERT_EQUAL(3, list.get_length());
        ASSERT_EQUAL(1, list[0]);
        ASSERT_EQUAL(2, list[1]);
        ASSERT_EQUAL(3, list[2]);
        print_test_result("push_back adds elements correctly", true);

        // Test push_front
        list.push_front(0);
        ASSERT_EQUAL(4, list.get_length());
        ASSERT_EQUAL(0, list[0]);
        print_test_result("push_front adds elements correctly", true);
    }

    // Test 3: Pop Operations
    TEST_CASE("Pop Operations");
    {
        Doubly_Linked_List<int> list{1, 2, 3, 4, 5};
        
        // Test pop_back
        list.pop_back();
        ASSERT_EQUAL(4, list.get_length());
        ASSERT_EQUAL(4, list[3]);
        print_test_result("pop_back removes last element", true);

        // Test pop_front
        list.pop_front();
        ASSERT_EQUAL(3, list.get_length());
        ASSERT_EQUAL(2, list[0]);
        print_test_result("pop_front removes first element", true);
    }

    // Test 4: Insert and Erase
    TEST_CASE("Insert and Erase Operations");
    {
        Doubly_Linked_List<int> list{1, 2, 3, 4, 5};
        
        // Test insert
        list.insert(2, 10);
        ASSERT_EQUAL(6, list.get_length());
        ASSERT_EQUAL(10, list[2]);
        print_test_result("insert adds element at correct position", true);

        // Test erase
        list.erase(2);
        ASSERT_EQUAL(5, list.get_length());
        ASSERT_EQUAL(3, list[2]);
        print_test_result("erase removes element at correct position", true);
    }

    // Test 5: Initializer List
    TEST_CASE("Initializer List Operations");
    {
        Doubly_Linked_List<int> list{1, 2, 3, 4, 5};
        ASSERT_EQUAL(5, list.get_length());
        ASSERT_EQUAL(1, list[0]);
        ASSERT_EQUAL(5, list[4]);
        print_test_result("Initializer list constructor works correctly", true);

        list = {6, 7, 8, 9, 10};
        ASSERT_EQUAL(5, list.get_length());
        ASSERT_EQUAL(6, list[0]);
        ASSERT_EQUAL(10, list[4]);
        print_test_result("Initializer list assignment works correctly", true);
    }

    // Test 6: Copy Operations
    TEST_CASE("Copy Operations");
    {
        Doubly_Linked_List<int> list1{1, 2, 3, 4, 5};
        Doubly_Linked_List<int> list2 = list1;  // Copy constructor
        
        ASSERT_EQUAL(list1.get_length(), list2.get_length());
        for (int i = 0; i < list1.get_length(); ++i) {
            ASSERT_EQUAL(list1[i], list2[i]);
        }
        print_test_result("Copy constructor works correctly", true);

        Doubly_Linked_List<int> list3;
        list3 = list1;  // Copy assignment
        ASSERT_EQUAL(list1.get_length(), list3.get_length());
        for (int i = 0; i < list1.get_length(); ++i) {
            ASSERT_EQUAL(list1[i], list3[i]);
        }
        print_test_result("Copy assignment works correctly", true);
    }

    // Test 7: Iterator Operations
    TEST_CASE("Iterator Operations");
    {
        Doubly_Linked_List<int> list{1, 2, 3, 4, 5};
        
        // Forward iteration
        int expected = 1;
        for (auto it = list.begin(); it != list.end(); ++it) {
            ASSERT_EQUAL(expected++, *it);
        }
        print_test_result("Forward iteration works correctly", true);

        // Reverse iteration
        expected = 5;
        auto it = list.end();
        --it;  // Move to last element
        do {
            ASSERT_EQUAL(expected--, *it);
        } while (it-- != list.begin());
        print_test_result("Reverse iteration works correctly", true);

        // Test empty list iteration
        Doubly_Linked_List<int> empty_list;
        ASSERT(empty_list.begin() == empty_list.end());
        print_test_result("Empty list iteration works correctly", true);
    }

    // Test 8: Element Access
    TEST_CASE("Element Access Operations");
    {
        Doubly_Linked_List<int> list{1, 2, 3, 4, 5};
        
        // Test operator[]
        ASSERT_EQUAL(1, list[0]);
        ASSERT_EQUAL(5, list[4]);
        print_test_result("operator[] works correctly", true);

        // Test at()
        ASSERT_EQUAL(1, list.at(0));
        ASSERT_EQUAL(5, list.at(4));
        print_test_result("at() works correctly", true);

        // Test bounds checking
        ASSERT_THROWS(list.at(5), std::out_of_range);
        print_test_result("at() throws out_of_range for invalid index", true);
    }

    // Test 9: Clear and Empty
    TEST_CASE("Clear and Empty Operations");
    {
        Doubly_Linked_List<int> list{1, 2, 3, 4, 5};
        
        list.clear();
        ASSERT(list.empty());
        ASSERT_EQUAL(0, list.get_length());
        print_test_result("clear removes all elements", true);
    }

    // Test 10: Reverse
    TEST_CASE("Reverse Operation");
    {
        // Test with non-empty list
        Doubly_Linked_List<int> list{1, 2, 3, 4, 5};
        
        list.reverse();
        ASSERT_EQUAL(5, list.get_length());
        ASSERT_EQUAL(5, list[0]);
        ASSERT_EQUAL(4, list[1]);
        ASSERT_EQUAL(3, list[2]);
        ASSERT_EQUAL(2, list[3]);
        ASSERT_EQUAL(1, list[4]);
        print_test_result("reverse works correctly with non-empty list", true);

        // Test with empty list
        Doubly_Linked_List<int> empty_list;
        empty_list.reverse();
        ASSERT(empty_list.empty());
        print_test_result("reverse works correctly with empty list", true);

        // Test with single element
        Doubly_Linked_List<int> single_list{1};
        single_list.reverse();
        ASSERT_EQUAL(1, single_list.get_length());
        ASSERT_EQUAL(1, single_list[0]);
        print_test_result("reverse works correctly with single element", true);

        // Test with two elements
        Doubly_Linked_List<int> two_list{1, 2};
        two_list.reverse();
        ASSERT_EQUAL(2, two_list.get_length());
        ASSERT_EQUAL(2, two_list[0]);
        ASSERT_EQUAL(1, two_list[1]);
        print_test_result("reverse works correctly with two elements", true);
    }

    std::cout << "\nAll tests completed successfully!\n";
    return 0;
}
