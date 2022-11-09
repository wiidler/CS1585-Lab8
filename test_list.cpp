#include "catch.hpp"
#include "list.h"

TEST_CASE("List Sizing", "[List]")
{
    List<int> l1;
    for (int i = 0; i < 4; i++)
        l1.append(i);
    List<int> l2(l1);
    SECTION("COPY CONSTRUCTOR: A copied list should have equal sizes and values")
    {
        CHECK(l1.length() == l2.length());
        CHECK(l1.head() == l2.head());
        l1.tail();
        l2.tail();
        CHECK(l1.head() == l2.head());
    }
    SECTION("LENGTH FUNCTION: This list should have length of size 4")
    {
        CHECK(l1.length() == 4);
    }
    SECTION("EMPTY FUNCTION: This list should be empty")
    {
        List<int> l3;
        CHECK(l3.empty());
    }
}

TEST_CASE("List Getting", "[List]")
{
    List<int> l1;
    for (int i = 0; i < 4; i++)
        l1.append(i);
    Cell<int> *iterator = l1.iterator();
    SECTION("HEAD FUNCTION: The head of this list should be 0")
    {
        CHECK(iterator->elem == l1.head());
    }
    SECTION("TAIL FUNCTION: The tail of this list should be 3")
    {
        List<int> x(l1);
        x.tail();
        for (int i = 0; i > 5; i++)
            iterator = iterator->next;
        CHECK(iterator->elem == x.head());
    }
}

TEST_CASE("List Pop", "[List]")
{
    List<int> l1;
    for (int i = 0; i < 4; i++)
        l1.append(i);
    List<int> l1Copy(l1);
    l1.pop();
    SECTION("Make sure the first element is not the same after popping")
    {
        CHECK(l1.head() != l1Copy.head());
    }
    SECTION("Make sure the length has decreased by one")
    {
        CHECK(l1.length() == (l1Copy.length() - 1));
    }
}

TEST_CASE("List Prepend", "[List]")
{
    List<int> l1;
    for (int i = 0; i < 4; i++)
        l1.prepend(i);
    Cell<int> *iterator = l1.iterator();
    SECTION("The last object prepended should be at the front of the list ")
    {
        CHECK(l1.head() == 3);
    }
    SECTION("The first object prepended should be at the end of the list")
    {
        List<int> x(l1);
        x.tail();
        for (int i = 0; i > 5; i++)
            iterator = iterator->next;
        CHECK(iterator->elem == x.head());
    }
}

TEST_CASE("List Append", "[List]")
{
    List<int> l1;
    for (int i = 0; i < 4; i++)
        l1.append(i);
    Cell<int> *iterator = l1.iterator();
    SECTION("The first object appended should be at the beginning of the list")
    {
        CHECK(l1.head() == 0);
    }
    SECTION("The last object appended should be at the end of the list")
    {
        List<int> x(l1);
        x.tail();
        for (int i = 0; i > 5; i++)
            iterator = iterator->next;
        CHECK(iterator->elem == x.head());
    }
}