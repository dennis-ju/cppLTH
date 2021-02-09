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
	unsigned int half_tri = (nbr_tri + 1) / 2;

	if (size > LENGTH_LIMIT)
	{
		return;
	}

	vector<string> tri;
	for (int i = 0; i < nbr_tri; i++)
	{
		tri.insert(tri.end(), word.substr(i, 3));
	}
	sort(tri.begin(), tri.end());

	for (int i = size - 1; i <= size + 1; i++)
	{
		for (int j = 0; j < static_cast<int>(words[i].size()); j++)
		{
			if (words[i][j].get_matches(tri) >= half_tri)
			{
				suggestions.insert(tri.end(), words[i][j].get_word());
			}
		}
	}
}

int get_score(const string &w1, const string &w2)
{
	int d[LENGTH_LIMIT + 1][LENGTH_LIMIT + 1];
	for (int i = 0; i <= LENGTH_LIMIT; i++)
	{
		d[0][i] = i;
		d[i][0] = i;
	}

	for (unsigned int i = 0; i <= w1.size(); i++)
	{
		for (unsigned int j = 0; j <= w2.size(); j++)
		{
			int skip = (w1.at(i) == w2.at(j)) ? d[i - 1][j - 1] : d[i - 1][j - 1] + 1;
			int min = std::min(d[i - 1][j] + 1, skip);
			min = std::min(d[i][j - 1] + 1, min);
		}
	}

	return d[w1.size()][w2.size()];
}

void Dictionary::rank_suggestions(vector<string> suggestions, const string &word) const
{
	vector<std::pair<int, string>> ranked;
	for (unsigned int i = 0; i < suggestions.size(); i++)
	{
		ranked.push_back(make_pair(get_score(word, suggestions[i]), word));
	}

	sort(ranked.begin(), ranked.end());

	for (unsigned int i = 0; i < suggestions.size(); i++)
	{
		suggestions[i] = ranked[i].first;
	}
}

vector<string> Dictionary::get_suggestions(const string &word) const
{

	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	/*
	trim_suggestions(suggestions);
	*/
	return suggestions;
}
