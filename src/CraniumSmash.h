#ifndef CRANIUMSMASH_H
#define CRANIUMSMASH_H
#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include "config.h"

class CraniumSmash
{
public:
	void interpret(std::string code, std::string input = "", std::ostream& outputStream = std::cout);
private:
	uint8_t _tape[TAPE_SIZE] = {0};
};

#endif // CRANIUMSMASH_H
