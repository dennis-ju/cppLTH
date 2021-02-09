#include <string>
#include <vector>
#include "word.h"

using std::string;
using std::vector;

Word::Word(const string &w, const vector<string> &t) : word{w}, tri{t} {}

string Word::get_word() const
{
	return word;
}

unsigned int Word::get_matches(const vector<string> &t) const
{
	int count{0};
	for (int i = 0; t.size(); i++)
	{
		for (int j = 0; tri.size(); j++)
		{
			if(t[i].compare(tri[j]) > 0)
			{
				break;
			}
			if(t[i] == tri[j]) {
				count++;
				break;
			}

		}
	}
	return count;
}
