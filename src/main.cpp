#include <iostream>
#include "CraniumSmash.h"

int main()
{
	CraniumSmash interpreter;
	std::cout << interpreter.interpret("#1(+++++),[>,]@0[&1>];0", "D=H") << std::endl;
}
