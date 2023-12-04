#include "HelperFunctions.h"

string Helper::lower(string word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return std::move(word);
}

pair<string, Movie> Helper::read_movie(string& line) {
    stringstream ss(line);
    array<string, 4>  data;

    for(int i = 0; i < 4; i++)
        getline(ss, data[i], '|');

    Movie temp; temp.set_data(data);
    return {lower(data[0]), std::move(temp)};
}

string Helper::get_key(string key) {
    return Helper::lower(key);
}