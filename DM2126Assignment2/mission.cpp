#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Muhammad Nurhidayat Bin Suderman
 *  \date      10 / Feb / 2016
 *  \note      150576E
 */


// Balanced parenthesis
bool Brackets(const string& input)
{
	/*char copy1[] = "";
	strcpy(copy1, input.c_str());
	string copy(copy1);
	list<char> slist;

	for (size_t i = 0; i < copy.size(); i++)
	{
		slist.push_back(copy[i]);
	}*/

	stack<char> cStack;
	if (input.empty())
		return false;
	else
	{
		for (size_t pos = 0; pos < input.length(); pos++)
		{
			if (input[pos] == '(' || input[pos] == '{' || input[pos] == '[' || input[pos] == '<')
				cStack.push(input[pos]);
			else if (input[pos] == ')' || input[pos] == '}' || input[pos] == ']' || input[pos] == '>')
			{
				if ((cStack.top() == '(' && input[pos] == ')')
					|| (cStack.top() == '{' && input[pos] == '}')
					|| (cStack.top() == '[' && input[pos] == ']')
					|| (cStack.top() == '<' && input[pos] == '>'))
					cStack.pop();
				else
					return false;
			}
		}
	}
	
	if (cStack.empty())
		return true;

	return false;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{

}