#include <iostream>
#include "CraniumSmash.h"

int main()
{
	CraniumSmash interpreter;
	std::cout << interpreter.interpret(",[.,]@5$33@10$63.@5.", "Hello, world") << std::endl;
}
