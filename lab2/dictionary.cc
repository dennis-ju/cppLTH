#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using std::string;
using std::vector;

Dictionary::Dictionary()
{
	std::ifstream infile{"words.txt"};
	std::string s;

	while (std::getline(infile, s))
	{
		vector<string> tri;
		int first_space = s.find(" ");
		const string w = s.substr(0, first_space);

		int position = s.find(" ", first_space);
		int nbr_tri = stoi(s.substr(first_space + 1, first_space - position));

		for (int i = 0; i < nbr_tri; i++)
		{
			position++;
			tri.insert(tri.end(), s.substr(position, 3));
			position += 3;
		}


		vector<Word> v{words[w.size()]};
		v.insert(words[w.size()].end(), Word(w, tri));
		all_words.insert(w);
	}
	/*
	auto search = all_words.find("hello");
	std::cout << *search;
	*/
}

bool Dictionary::contains(const string &word) const
{

	return all_words.count(word) > 0;
}

void Dictionary::add_trigram_suggestions(vector<string> suggestions, const string &word) const
{
	int size = word.size();
	int nbr_tri = size - 2;
	unsigned int half_tri = (nbr_tri + 1)/2;

	if(size > LENGTH_LIMIT) {
		return;
	}

	vector<string> tri;
	for(int i = 0; i < nbr_tri; i++)
	{
		tri.insert(tri.end(), word.substr(i, 3)); 
	}
	sort(tri.begin(), tri.end());

	for(int i = size-1; i <= size + 1; i++)
	{
		for(int j = 0; j < static_cast<int>(words[i].size()); j++)
		{
			if(words[i][j].get_matches(tri) >= half_tri)
			{
				suggestions.insert(tri.end(), words[i][j].get_word());
			}
		}
	}
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	/*
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	*/
	return suggestions;
}
