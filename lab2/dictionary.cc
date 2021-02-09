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

std::unordered_set<string> words;

Dictionary::Dictionary() {	
	std::ifstream infile{"words.txt"};
	std::string s;

	while(std::getline(infile, s))
    {
        int i = s.find(" ");
		words.insert(s.substr(0, i));
    }
	/*
	auto search = words.find("hello");
	std::cout << *search;
	*/
}

bool Dictionary::contains(const string& word) const {
	return true;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}


