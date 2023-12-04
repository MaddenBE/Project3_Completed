#pragma once

#include "IncludeStatements.h"

using namespace std;

struct Movie {
    string genre;
    string title;
    string year;
    string ID;

    bool valid;

    Movie() : genre(), title(), year(), ID(), valid(false) {}

    void set_data(array<string, 4> &data) {
        valid = true;
        title = data[0];
        ID = data[1];
        genre = data[2];
        year = data[3];
    }

    [[nodiscard]] string to_string() const {
        return title + '|' + ID + '|' + genre + '|' + year;
    }

};

