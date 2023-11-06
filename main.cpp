#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Item {
    int weight;
    int value;
};

void readInputFromFile(const string& filename, int& numTestCases, vector<int>& KnapsackSize, vector<vector<Item>>& testCases) {
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
    KnapsackSize.resize(numTestCases);

    for (int i = 0; i < numTestCases; ++i) {
        int knapsackSizeAtIndex, numItems;
        input >> KnapsackSize[i] >> numItems;
        
        
        cout << "knapsack size: " << KnapsackSize[i] << endl;
        cout << "number of items " << numItems << endl;
        testCases[i].resize(numItems);

        for (int j = 0; j < numItems; ++j) {
            input >> testCases[i][j].weight >> testCases[i][j].value;
        }
    }

    input.close();
}

int main() {
    int numTestCases;
    
    vector<int> KnapsackSize;
    vector<vector<Item>> testCases;
    readInputFromFile("input.txt", numTestCases, KnapsackSize, testCases);
    

    for (int testCaseIndex = 0; testCaseIndex < numTestCases; ++testCaseIndex) {
        vector<Item>& items = testCases[testCaseIndex];
        
        
        
        cout << "Test Case " << testCaseIndex + 1 << ":\n";
        cout << "Knapsack Size: " << KnapsackSize[testCaseIndex] << endl;
        cout << endl;
    }
    cout << "Number of test cases: " << numTestCases << endl;

    return 0;
}