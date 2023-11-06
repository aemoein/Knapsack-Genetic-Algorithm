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
        cerr << "Error: Unable to open input file" << endl;
        exit(1);
    }
    else {
        cout << "file openned successfully" << endl;
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
    int numTestCases;
    vector<vector<Item>> testCases;
    readInputFromFile("input.txt", numTestCases, testCases);

    for (int testCaseIndex = 0; testCaseIndex < numTestCases; ++testCaseIndex) {
        
        int knapsackSize = testCases[testCaseIndex][0].weight;
        vector<Item>& items = testCases[testCaseIndex];
        
        
        
        cout << "Test Case " << testCaseIndex + 1 << ":\n";
    }
    cout << "Number of test cases: " << numTestCases << endl;

    return 0;
}