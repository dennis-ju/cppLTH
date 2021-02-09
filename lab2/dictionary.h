#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include "word.h"
#include <unordered_set>

using std::string;
using std::vector;

const int LENGTH_LIMIT = 25;

class Dictionary
{
public:
	Dictionary();
	bool contains(const string &word) const;
	void add_trigram_suggestions(vector<string> suggestions, const string &word) const;
	void rank_suggestions(vector<string> suggestions, const string &word) const;
	vector<string> get_suggestions(const string &word) const;

private:
	vector<Word> words[LENGTH_LIMIT];
	std::unordered_set<string> all_words;
};

#endif
