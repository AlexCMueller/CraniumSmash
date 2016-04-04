#include <iostream>
#include "CraniumSmash.h"

int main()
{
	CraniumSmash interpreter;
	std::cout << interpreter.interpret(",[.,]", "Hello, world!") << std::endl;
}
