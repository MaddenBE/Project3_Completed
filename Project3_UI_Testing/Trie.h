#pragma once

#include "HelperFunctions.h"

struct Node {
    unordered_map<char, Node*> children;
    pair<string, Movie> movie;
    bool contains_movie;

    Node() : children(), contains_movie(false), movie(){}
    Node(pair<string, Movie>& data) : contains_movie(true), movie(data){}

    void insert_movie(pair<string, Movie>& data) {contains_movie = true; movie = data;}
};

class Trie {
    Node root;
    bool ok = false;

    void conflict_resolution_helper(Node* current, pair<string, Movie>& old_movie, pair<string, Movie>& new_movie, int index);
    void insert_helper(Node* current, pair<string, Movie>& data, int index);
    Node* find_nearest_helper(Node* current, string& key, int index);
    Node* check_if_prefix(Node* current, string& key);

public:
    Trie() : root() {}

    void conflict_resolution(Node* current, pair<string, Movie>& new_movie, int index);
    void insert_node(pair<string, Movie>& data);
    vector<Movie> find_nearest(string& key, int max);

};
