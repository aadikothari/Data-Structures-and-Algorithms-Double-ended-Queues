#include "catch.hpp"
#include "Deque.hpp"

// given test case
TEST_CASE( "Peak at empty deque", "[deque]" )
{
  Deque<int> d;
  
  REQUIRE_THROWS_AS(d.front(), std::runtime_error);
  REQUIRE_THROWS_AS(d.back(), std::runtime_error);
}

// Testing for default constructor
TEST_CASE("Default constructor") {
	Deque<int> d;
	Deque<int> dEmpty;

	// pushing elements in d
	d.pushFront(1);
	d.pushFront(2);
	d.pushFront(3);
	d.pushFront(4);
	d.pushFront(5);


	// dEmpty should be empty, meaning default constructor works
	REQUIRE(dEmpty.isEmpty());
	REQUIRE_FALSE(d.isEmpty());
}

// Test case for isEmpty
TEST_CASE("isEmpty test") {
	Deque<int> dEmpty;
	Deque<int> d;

	// pushing elements into d
	d.pushFront(1);
	d.pushFront(2);
	d.pushFront(3);
	d.pushFront(4);
	d.pushFront(5);
	d.pushBack(1);
	d.pushBack(2);
	d.pushBack(3);
	d.pushBack(4);
	d.pushBack(5);

	// since dEmpty is empty, isEmpty() should return true
	REQUIRE(dEmpty.isEmpty());

	// d isn't empty, so this is ok and shud be false
	REQUIRE_FALSE(d.isEmpty());
}

TEST_CASE("pushFront and pushBack test")
{
	Deque<int> d;

	// pushing elements in front and back
	d.pushFront(1);
	d.pushFront(2);
	d.pushFront(3);
	d.pushFront(4);
	d.pushFront(5);
	d.pushBack(1);
	d.pushBack(2);
	d.pushBack(3);
	d.pushBack(4);
	d.pushBack(69);

	// front should be 5, back should be 69
	REQUIRE(d.front() == 5);
	REQUIRE(d.back() == 69);
	
}

TEST_CASE("popFront and popBack test") {
	Deque<int> d;

	// pushing elements in front and back
	d.pushFront(1);
	d.pushFront(2);
	d.pushFront(3);
	d.pushFront(4);
	d.pushFront(5);
	d.pushBack(1);
	d.pushBack(2);
	d.pushBack(3);
	d.pushBack(4);
	d.pushBack(5);

	// popping back and front
	d.popBack();
	d.popFront();

	// front and back should be 4
	REQUIRE(d.back() == 4);
	REQUIRE(d.front() == 4);
}

TEST_CASE("front and back test") {
	Deque<int> d;

	// pushing elements in front and back
	d.pushFront(1);
	d.pushFront(2);
	d.pushFront(3);
	d.pushFront(4);
	d.pushFront(5);
	d.pushBack(1);
	d.pushBack(2);
	d.pushBack(3);
	d.pushBack(4);
	d.pushBack(5);


	// the next few lines continue and pop from front and back
	// and check if the elements are popping in order

	d.popBack();
	d.popFront();

	REQUIRE(d.back() == 4);
	REQUIRE(d.front() == 4);

	d.popBack();
	d.popFront();

	REQUIRE(d.back() == 3);
	REQUIRE(d.front() == 3);

	d.popBack();
	d.popFront();

	REQUIRE(d.back() == 2);
	REQUIRE(d.front() == 2);

	d.popBack();
	d.popFront();

	REQUIRE(d.back() == 1);
	REQUIRE(d.front() == 1);

	d.popBack();
	d.popFront();
}