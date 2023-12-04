#pragma once

#include "Movie.h"

using namespace std;

namespace Helper {
    pair<string, Movie> read_movie(string& line);
    string lower(string word);
    string get_key(string key);
}

