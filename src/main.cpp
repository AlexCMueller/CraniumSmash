#include <iostream>
#include <fstream>
#include <sstream>
#include "CraniumSmash.h"

std::string readFile(std::ifstream& file)
{
	std::stringstream sstr;
	sstr << file.rdbuf();
	return sstr.str();
}

int main()
{
	std::ifstream codeFile ("program.txt");
	std::ifstream inputFile ("input.txt");
	std::string codeString;
	std::string inputString;

	CraniumSmash interpreter;
	if (inputFile.is_open())
	{
		inputString = readFile(inputFile);
		inputFile.close();
	}
	if (codeFile.is_open())
	{
		codeString = readFile(codeFile);
		codeFile.close();
	}
	std::cout << interpreter.interpret(codeString, inputString) << std::endl;
}
