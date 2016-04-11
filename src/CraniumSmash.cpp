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

std::string CraniumSmash::interpret(std::string code, std::string input = "")
{
	std::string output;
	unsigned int tapePos = 0;
	std::stack<std::string::iterator> loopStack;
	std::stack<std::string::iterator> procCallStack;
	std::unordered_map<int, std::string::iterator> procMap;
	int temp;
	int level;

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
					level = 1;
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
				break;
			case '`':
				output += '\n';
				break;
			case ':':
				output += std::to_string(_tape[tapePos]);
				break;
			case ';':
				temp = tapePos;
				tapePos = parseInt(it);
				while(_tape[tapePos] != 0)
				{
					output += static_cast<char>(_tape[tapePos]);
					tapePos == TAPE_SIZE - 1 ? tapePos = 0 : tapePos++;
				}
				tapePos = temp;
				break;
			case '#':
				temp = parseInt(it);
				if (*(it + 1) == '(')
				{
					procMap.insert(std::make_pair(temp, it + 1));
					it += 2;
					level = 1;
					while (level != 0)
					{
						if (*it == '(')
						{
							level++;
						}
						if (*it == ')')
						{
							level--;
						}
						it++;
					}
					it--;
				}
				break;
			case '&':
				temp = parseInt(it);
				procCallStack.push(it);
				it = procMap.at(temp);
				break;
			case ')':
				if (!procCallStack.empty())
				{
					it = procCallStack.top();
					procCallStack.pop();
				}
			default:
				break;
		}
	}
	return output; 
}
