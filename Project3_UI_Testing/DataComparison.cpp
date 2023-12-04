#include "DataComparison.h"

#define MILLISECONDS 1000

long DataComparison::insert_in_map(pair<string, Movie>& data) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    map[data.first] = data.second;

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long time = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();

    return time;
}

pair<long, vector<Movie>> DataComparison::search_in_map(string& key, int results) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    vector<Movie> matches;
    auto lower = map.lower_bound(key);
    auto bound = map.end();

    int count = 0;
    while (lower != bound && (lower->first).compare(0, key.size(), key) == 0 && count < results) {
        matches.push_back(lower->second);
        ++lower; ++count;
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long time = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();

    return {time, std::move(matches)};
}

long DataComparison::insert_in_trie(pair<std::string, Movie> &data) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    trie.insert_node(data);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long time = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();

    return time;
}

pair<long, vector<Movie>> DataComparison::search_in_trie(std::string &key, int results) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    vector<Movie> matches(std::move(trie.find_nearest(key, results)));

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    long time = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();

    return {time, std::move(matches)};
}

DataComparison::DataComparison(std::string file) {
    ifstream in(file);
    string line;

    while (getline(in, line)) {
        pair<string, Movie> data = Helper::read_movie(line);
        map_build_time += insert_in_map(data);
        trie_build_time += insert_in_trie(data);
    }
}