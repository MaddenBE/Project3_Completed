#pragma once

#include "Trie.h"

using namespace std;

class DataComparison {
    map<string, Movie> map;
    Trie trie;

    long trie_build_time;
    long map_build_time;

public:
    DataComparison(string file);

    long insert_in_map(pair<string, Movie>& data);
    long insert_in_trie(pair<string, Movie>& data);

    pair<long, vector<Movie>> search_in_map(string& key, int results);
    pair<long, vector<Movie>> search_in_trie(string& key, int results);
};



