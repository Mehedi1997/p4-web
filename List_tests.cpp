// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_push_front1) {
    
    List<int> list;
    list.push_front(34);
    list.push_front(22);
    ASSERT_EQUAL(list.front(), 22);
    ASSERT_EQUAL(list.back(), 34);
}

TEST(test_push_front2) {

    List<int> list;
    list.push_front(22);
    ASSERT_EQUAL(list.front(), 22);
    ASSERT_EQUAL(list.back(), 22);
    ASSERT_EQUAL(list.front(), list.back());
}

TEST(test_push_back) {

    List<int> list;
    list.push_back(34);
    list.push_back(22);
    ASSERT_EQUAL(list.front(), 34);
    ASSERT_EQUAL(list.back(), 22);
}

TEST(test_push_front_and_back1) {

    List<int> list;
    list.push_front(-50);
    list.push_front(0);
    list.push_back(800);
    ASSERT_EQUAL(list.front(), 0);
    ASSERT_EQUAL(list.back(), 800);
}

TEST(test_push_front_and_back2) {

    List<int> list;
    list.push_back(34);
    list.push_front(12);
    list.push_back(22);
    list.push_front(100);
    list.push_front(-50);
    list.push_front(0);
    list.push_back(800);
    List<int>::Iterator iter = list.begin();
    ASSERT_EQUAL(*iter, 0);
    ++iter;
    ASSERT_EQUAL(*iter, -50);
    ++iter;
    ASSERT_EQUAL(*iter, 100);
    ++iter;
    ASSERT_EQUAL(*iter, 12);
    ++iter;
    ASSERT_EQUAL(*iter, 34);
    ++iter;
    ASSERT_EQUAL(*iter, 22);
    ++iter;
    ASSERT_EQUAL(*iter, 800);

}

TEST(test_iter_and_push_front) {

    List<string> list;
    list.push_front("Apple");
    list.push_front("Banana");
    list.push_front("Orange");
    list.push_front("Coconut");
    List<string>::Iterator iter = list.begin();
    ASSERT_EQUAL(*iter, "Coconut");
    ++iter;
    ASSERT_EQUAL(*iter, "Orange");
    ++iter;
    ASSERT_EQUAL(*iter, "Banana");
    ++iter;
    ASSERT_EQUAL(*iter, "Apple");
}

TEST(test_iter_and_push_back) {

    List<string> list;
    list.push_back("Apple");
    list.push_back("Banana");
    list.push_back("Orange");
    list.push_back("Coconut");
    List<string>::Iterator iter = list.begin();
    ASSERT_EQUAL(*iter, "Apple");
    ++iter;
    ASSERT_EQUAL(*iter, "Banana");
    ++iter;
    ASSERT_EQUAL(*iter, "Orange");
    ++iter;
    ASSERT_EQUAL(*iter, "Coconut");
}

TEST(test_insert_basic) {

    List<int> list;
    list.push_back(0);
    list.push_back(1);
    list.push_back(3);
    list.push_back(4);
    List<int>::Iterator iter = list.begin();
    ++++iter;
    list.insert(iter, 2);
    iter = list.begin();
    for (int x = 0; x < 5; x++)
    {
        ASSERT_EQUAL(*iter, x);
        ++iter;
    }
}

TEST(test_insert_empty) {

    List<int> list;
    List<int>::Iterator iter = list.begin();
    list.insert(iter, 5);
    iter = list.begin();
    ASSERT_EQUAL(*iter, 5);
}

TEST(test_insert_end) {

    List<int> list;
    list.push_back(90);
    list.push_back(12);
    list.push_back(34);
    list.push_back(46);
    List<int>::Iterator iter = list.end();
    list.insert(iter, 5);
    iter = list.begin();
    ++++++++iter;
    ASSERT_EQUAL(*iter, 5);
}

TEST(test_insert_complex) {

    List<int> list;
    list.push_back(1);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    List<int>::Iterator iter = list.begin();
    list.insert(iter, 0);
    ++iter;
    list.insert(iter, 2);
    ++++++iter;
    list.insert(iter, 6);
    list.insert(iter, 7);
    iter = list.begin();
    for (int x = 0; x < 11; x++)
    {
        ASSERT_EQUAL(*iter, x);
        ++iter;
    }
}

TEST(test_erase_simple) {

    List<int> list;
    list.push_back(90);
    list.push_back(12);
    list.push_back(34);
    list.push_back(46);
    List<int>::Iterator iter = list.begin();
    ++iter;
    list.erase(iter);
    iter = list.begin();
    ASSERT_EQUAL(*iter, 90);
    ++iter;
    ASSERT_EQUAL(*iter, 34);
    ++iter;
    ASSERT_EQUAL(*iter, 46);
}

TEST(test_erase_start) {

    List<string> list;
    list.push_back("Red");
    list.push_back("Blue");
    list.push_back("Yellow");
    list.push_back("Green");
    List<string>::Iterator iter = list.begin();
    list.erase(iter);
    iter = list.begin();
    ASSERT_EQUAL(*iter, "Blue");
    ++iter;
    ASSERT_EQUAL(*iter, "Yellow");
    ++iter;
    ASSERT_EQUAL(*iter, "Green");
}

TEST(test_erase_one) {

    List<char> list;
    list.push_back('a');
    List<char>::Iterator iter = list.begin();
    list.erase(iter);
    ASSERT_TRUE(list.empty());
}

TEST(test_empty1)
{
    List<bool> list;
    list.push_back(4 == 5);
    list.push_back(true);
    ASSERT_FALSE(list.empty());
}

TEST(test_empty2)
{
    List<bool> list;
    ASSERT_TRUE(list.empty());
}

TEST(test_size)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    ASSERT_EQUAL(list.size(), 6);
}

TEST(test_size2)
{
    List<int> list;
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_size3)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator iter = list.begin();
    for (int x = 0; x < 3; x++)
    {
        list.erase(iter);
        iter = list.begin();
    }
    ASSERT_EQUAL(list.size(), 0);
}

TEST(test_assignment_iter)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator iter = list.begin();
    List<int>::Iterator iter2 = iter;
    ++iter;
    ASSERT_FALSE(iter==iter2);
    ++iter2;
    ASSERT_TRUE(iter == iter2);
}

TEST(test_assignment_list)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    List<int> list2;
    list.push_back(4);
    list.push_back(5);
    list2 = list;
    List<int>::Iterator iter = list.begin();
    List<int>::Iterator iter2 = list2.begin();
    for (int x = 0; x < list.size(); x++)
    {
        ASSERT_EQUAL(*iter, *iter2);
        ++iter;
        ++iter2;
    }
}

TEST(test_end)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator iter = list.end();
    List<int>::Iterator iter2;
    ASSERT_TRUE(iter == iter2);
    ASSERT_FALSE(iter != iter2);
}

TEST(test_begin)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator iter = list.begin();
    ASSERT_EQUAL(*iter, 1);
}

TEST(test_front_and_back)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 2);
    list.pop_back();
    ASSERT_EQUAL(list.back(), list.front());
}

TEST(test_copy_ctor_iter)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator iter = list.begin();
    ++iter;
    List<int>::Iterator iter_copy(iter);
    ASSERT_EQUAL(iter, iter_copy);
    ASSERT_EQUAL(*iter_copy, 2);
}

TEST(test_copy_ctor_list)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int> list_copy(list);
    List<int>::Iterator iter = list.begin();
    List<int>::Iterator iter2 = list_copy.begin();
    for (int x = 0; x < list.size(); x++)
    {
        ASSERT_EQUAL(*iter, *iter2);
        ++iter;
        ++iter2;
    }
}

TEST(test_clear)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_back) {

    List<string> list;
    list.push_back("Red");
    list.push_back("Blue");
    list.push_back("Yellow");
    list.push_back("Green");
    List<string>::Iterator iter = list.begin();
    list.pop_back();
    ASSERT_EQUAL(*iter, "Red");
    ++iter;
    ASSERT_EQUAL(*iter, "Blue");
    ++iter;
    ASSERT_EQUAL(*iter, "Yellow");
}

TEST(test_pop_front) {

    List<string> list;
    list.push_back("Red");
    list.push_back("Blue");
    list.push_back("Yellow");
    list.push_back("Green");
    list.pop_front();
    List<string>::Iterator iter = list.begin();
    ASSERT_EQUAL(*iter, "Blue");
    ++iter;
    ASSERT_EQUAL(*iter, "Yellow");
    ++iter;
    ASSERT_EQUAL(*iter, "Green");
}

TEST(test_pop_back_and_front) {

    List<string> list;
    list.push_back("Red");
    list.push_back("Blue");
    list.push_back("Yellow");
    list.push_back("Green");
    list.push_back("Black");
    list.push_back("White");
    list.pop_back();
    list.pop_front();
    list.pop_back();
    list.pop_front();
    list.pop_front();
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), "Green");
    ASSERT_EQUAL(list.back(), "Green");
}

TEST(test_pop_back_one) {

    List<string> list;
    list.push_back("Red");
    list.pop_back();
    ASSERT_TRUE(list.empty());

}

TEST(test_pop_front_one) {

    List<string> list;
    list.push_back("Red");
    list.pop_front();
    ASSERT_TRUE(list.empty());
}

TEST(test_pop_all) {

    List<string> list;
    list.push_back("Red");
    list.push_back("Blue");
    list.push_back("Yellow");
    list.push_back("Green");
    list.push_back("Black");
    list.push_back("White");
    const int size = list.size();
    for (int x = 0; x < size/2; x++)
    {
        list.pop_back();
        list.pop_front();
    }
    ASSERT_TRUE(list.empty());
}

TEST(test_operators_iter)
{
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    List<int>::Iterator iter = list.begin();
    List<int>::Iterator start = iter;
    ++++iter;
    --++iter;
    ----iter;
    bool b = iter == start;
    ASSERT_TRUE(b);
}









TEST_MAIN()
