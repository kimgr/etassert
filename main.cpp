// gen_functor.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

#include "equalsexpression.h"
#include "actualcapture.h"
#include "expression_assert.h"

std::string GetGreeting(const char* name)
{
	std::string greeting("Hello ");
	greeting += name;
	greeting += "!";

	return greeting;
}

int main()
{
	Assert::That(10, !Equals(20));
	Assert::That(10, !!Equals(10));
	Assert::That(10, Equals(10) && !Equals(50));
	Assert::That(15, Equals(150) || Equals(15));
	Assert::That(15, !(Equals(150) || Equals(10)));
	Assert::That(ACTUAL(10 + 140), Equals(150));

	// Compare output, second is better
	Assert::That(GetGreeting("Kim"), Equals("Hello Kim!"));
	Assert::That(ACTUAL(GetGreeting("Kim")), Equals("Hello Kim!"));

	return 0;
}
