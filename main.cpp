#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Item {
    int weight;
    int value;
};

void readInputFromFile(const string& filename, int& numTestCases, vector<vector<Item>>& testCases) {
    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        exit(1);
    }

    input >> numTestCases;
    testCases.resize(numTestCases);

    for (int i = 0; i < numTestCases; ++i) {
        int knapsackSize, numItems;
        input >> knapsackSize >> numItems;
        testCases[i].resize(numItems);

        for (int j = 0; j < numItems; ++j) {
            input >> testCases[i][j].weight >> testCases[i][j].value;
        }
    }

    input.close();
}

int main() {

    return 0;
}