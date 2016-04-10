#ifndef CRANIUMSMASH_H
#define CRANIUMSMASH_H
#include <cstdint>
#include <string>
#include <stack>
#include "config.h"

class CraniumSmash
{
public:
	std::string interpret(std::string code, std::string input);
private:
	uint8_t _tape[TAPE_SIZE] = {0};
};
#endif // CRANIUMSMASH_H
