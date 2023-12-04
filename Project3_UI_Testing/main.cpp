#include "IncludeStatements.h"
#include "DataComparison.h"
#include "Main_page.h"
#include "Results_Page.h"

#define file "MovieData.txt"


int main() {
    DataComparison structures(file);
    Results_Page result_UI;
    Main_Page ui;
    while(true) {
        string key = ui.initialize();

        if(key == "|") break;

        pair<long, vector<Movie>> results;
        result_UI.result_initialize(key, results);


    }

    return 0;
}
