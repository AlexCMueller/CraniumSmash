#include "CraniumSmash.h"

int parseInt(std::string::iterator& it)
{
	std::string buffer;
	it++;
	while (isdigit(*it))
	{
		buffer += *it;
		it++;
	}
	it--;
	return stoi(buffer);
}

std::string CraniumSmash::interpret(std::string code, std::string input)
{
	std::string output;
	unsigned int tapePos = 0;
	std::stack<std::string::iterator> loopStack;

	for (std::string::iterator it = code.begin(); it != code.end(); it++)
	{
		switch (*it)
		{
			case '+':
				_tape[tapePos]++;
				break;
			case '-':
				_tape[tapePos]--;
				break;
			case '<':
				tapePos == 0 ? tapePos = (TAPE_SIZE - 1) : tapePos--;
				break;
			case '>':
				tapePos++;
				tapePos = tapePos % TAPE_SIZE;
				break;
			case '[':
				if (_tape[tapePos] == 0)
				{
					int level = 1;
					while (level != 0)
					{
						it++;
						if (*it == '[')
							level++;
						if (*it == ']')
							level--;
					}
				}
				else
				{
					loopStack.push(it);
				}
				break;
			case ']':
				if (_tape[tapePos] == 0)
				{
					loopStack.pop();
				}
				else
				{
					it = loopStack.top();
				}
				break;
			case ',':
				if (input.length() != 0)
				{
					_tape[tapePos] = static_cast<uint8_t>(input.front());
					input.erase(0, 1);
				}
				else
				{
					_tape[tapePos] = 0;
				}
				break;
			case '.':
				output += static_cast<char>(_tape[tapePos]);
				break;
			case '$':
				_tape[tapePos] = parseInt(it) % 256; 
				break;
			case '@':
				tapePos = parseInt(it) % TAPE_SIZE; 
				break;
			case '?':
				output += std::to_string(tapePos);
			case '`':
				output += '\n';
		}
	}
	return output; 
}
