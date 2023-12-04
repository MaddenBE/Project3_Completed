#include "Trie.h"

void Trie::insert_node(pair<string, Movie>& data) {
    insert_helper(&root, data, 0);
}

void Trie::insert_helper(Node* current, pair<string, Movie>& data, int index) {
    //End node with another movie
    if(current->children.empty() && current->contains_movie) {
        conflict_resolution(current, data, index);
        return;
    }
    //Max node for this key
    else if(index >= data.first.length()) {
        conflict_resolution(current, data, index);
        return;
    }

    //Character in question
    char& c = data.first[index];
    //Find next node
    auto child = current->children.find(c);

    //Next node found
    if(child != current->children.end()) {
        insert_helper(child->second, data, index + 1);
        return;
    }
    else {
        current->children[c] = new Node(data);
        return;
    }
}

void Trie::conflict_resolution(Node* current, pair<string, Movie>& new_movie, int index) {
    //Current is empty and there is no conflict
    if(!current->contains_movie) {
        return current->insert_movie(new_movie);
    }
    //They are equal and there is no conflict
    else if(current->movie.first == new_movie.first) {
        return;
    }
    //There is conflict
    else {
        //Empty original one
        current->contains_movie = false;
        pair<string, Movie> old_movie(std::move(current->movie));

        //Resolve conflict
        conflict_resolution_helper(current, old_movie, new_movie, index);
    }
}

void Trie::conflict_resolution_helper(Node* current, pair<std::string, Movie> &old_movie, pair<std::string, Movie> &new_movie, int index) {
    //Index out of bounds
    if( index >= old_movie.first.length() ) {
        current->insert_movie(old_movie);
        current->children[new_movie.first[index]] = new Node(new_movie);
    }
    else if( index >= new_movie.first.length() ) {
        current->insert_movie(new_movie);
        current->children[old_movie.first[index]] = new Node(old_movie);
    }
    //The characters are not equal
    else if( old_movie.first[index] != new_movie.first[index] ) {
        current->children[new_movie.first[index]] = new Node(new_movie);
        current->children[old_movie.first[index]] = new Node(old_movie);
    }
    else {
        Node* next = new Node();
        current->children[old_movie.first[index]] = next;
        conflict_resolution_helper(next, old_movie, new_movie, index + 1);
    }
}

Node* Trie::check_if_prefix(Node *current, string& key) {
    if( current->contains_movie && (current->movie.first).compare(0, key.size(), key) != 0 )
        return nullptr;
    return current;
}

Node* Trie::find_nearest_helper(Node* current, string& key, int index) {
    if( index >= key.length() ) {
        return check_if_prefix(current, key);
    }

    auto child = current->children.find(key[index]);

    if( child == current->children.end() ) {
        return check_if_prefix(current, key);
    }

    else {
        return find_nearest_helper(child->second, key, index + 1);
    }
}

vector<Movie> Trie::find_nearest(string& key, int max) {
    Node* current = find_nearest_helper(&root, key, 0);
    vector<Movie> matches;

    if(current == nullptr) {
        return std::move(matches);
    }

    queue<Node*> q;
    q.push(current);

    int count = 0;
    while( !q.empty() && count < max ) {
        current = q.front();

        if( current->contains_movie ) {
            matches.push_back(current->movie.second);
            count++;
        }
        for( auto child : current->children ) {
            q.push(child.second);
        }
        q.pop();
    }

    return std::move(matches);
}