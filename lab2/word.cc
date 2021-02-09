#include <string>
#include <vector>
#include "word.h"
#include <iterator>

using std::string;
using std::vector;

Word::Word(const string &w, const vector<string> &t) : word{w}, tri{t} {}

string Word::get_word() const
{
	return word;
}

unsigned int Word::get_matches(const vector<string> &t) const
{
	if (tri.size() == 0 || t.size() == 0)
	{
		return 0;
	}

	int count{0};
	auto a = tri.begin();
	auto b = t.begin();

	while (a != tri.end() && b != t.end())
	{
		int cmp = (*a).compare(*b);
		if (cmp == 0)
		{
			count++;
			a++;
			b++;
		}
		else if (cmp > 0)
		{
			b++;
		}
		else if (cmp < 0)
		{
			a++;
		}
	}
	return count;
}
