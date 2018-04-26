#include <catch.hpp>
#include <sstream>

#include "shared_ptr.hpp"

TEST_CASE("NULL"){
	shared_ptr <int> ptr;
	
	REQUIRE (ptr.get() == nullptr);
}
TEST_CASE("num1"){
	shared_ptr <int> ptr1(new int(3));
	int *ptr_1 = ptr1.get();
	
	shared_ptr <int> ptr2(new int(6));
	int ptr_2 = *ptr2;
	
	REQUIRE(*ptr_1 == 3);
	REQUIRE(ptr_2 == 6);
}

TEST_CASE("num2"){
	shared_ptr <int> ptr1(new int(3));
	
	shared_ptr <int> ptr2(new int(6));
	
	ptr1.swap(ptr2);
	
	int *ptr_1 = ptr1.get();
	int ptr_2 = *ptr2;
	
	REQUIRE(*ptr_1 == 6);
	REQUIRE(ptr_2 == 3);	
}

TEST_CASE("num3"){
	shared_ptr <int> ptr1(new int(3));
	ptr1.reset(new int(6));
	
	int *ptr = ptr1.get();
	
	REQUIRE(*ptr == 6);
}
