#include <iostream>
#include "CraniumSmash.h"

int main()
{
	CraniumSmash interpreter;
	std::cout << interpreter.interpret("$58>$32>>,[>,];3`@3[?;0.;1:`>]", "This string will be analyzed!") << std::endl;
}
