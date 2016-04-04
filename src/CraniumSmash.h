#ifndef CRANIUMSMASH_H
#define CRANIUMSMASH_H
#include <cstdint>
#include <string>
#include <stack>

class CraniumSmash
{
public:
	std::string interpret(std::string code, std::string input);
private:
	uint8_t _tape[1024] = {0};
};
#endif // CRANIUMSMASH_H
