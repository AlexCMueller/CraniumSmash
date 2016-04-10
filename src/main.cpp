#include <iostream>
#include "CraniumSmash.h"

int main()
{
	CraniumSmash interpreter;
	std::cout << interpreter.interpret(",[.,]`@10?", "Hello, world") << std::endl;
}
