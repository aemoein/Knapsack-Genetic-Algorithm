#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

void readInputFromFile(const string& filename, int& numTestCases, vector<int>& KnapsackSize, vector< vector<Item> >& testCases) {
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

void initializePopulation(vector<vector<bool>>& population, int populationSize, int numItems) {
    population.resize(populationSize, vector<bool>(numItems));

    for (int i = 0; i < populationSize; ++i) {
        for (int j = 0; j < numItems; ++j) {
            population[i][j] = rand() % 2;
        }
    }
}

int calculateFitness(const vector<bool>& individual, const vector<Item>& items, int knapsackSize) {
    int totalValue = 0;
    int totalWeight = 0;

    for (int i = 0; i < items.size(); ++i) {
        if (individual[i]) {
            totalValue += items[i].value;
            totalWeight += items[i].weight;
        }
    }

    if (totalWeight > knapsackSize) {
        // Penalize infeasible solutions
        return 0;
    }

    return totalValue;
}

void rankBasedSelection(const vector<vector<bool>>& population, const vector<Item>& items, int knapsackSize, vector<vector<bool>>& selectedParents, int numParents) {
    vector<pair<int, int>> fitnessValues;
    
    for (int i = 0; i < population.size(); ++i) {
        int fitness = calculateFitness(population[i], items, knapsackSize);
        fitnessValues.emplace_back(i, fitness);
    }

    
    sort(fitnessValues.begin(), fitnessValues.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });
    
    selectedParents.clear();
    for (int i = 0; i < numParents; ++i) {
        selectedParents.push_back(population[fitnessValues[i].first]);
    }
}

void onePointCrossover(const vector<vector<bool>>& parents, vector<vector<bool>>& offspring) {
    int numParents = parents.size();
    int numGenes = parents[0].size();
    offspring.resize(numParents, vector<bool>(numGenes));

    for (int i = 0; i < numParents; i += 2) {
        int crossoverPoint = rand() % numGenes;
        for (int j = 0; j < numGenes; ++j) {
            if (j <= crossoverPoint) {
                offspring[i][j] = parents[i][j];
                offspring[i + 1][j] = parents[i + 1][j];
            } else {
                offspring[i][j] = parents[i + 1][j];
                offspring[i + 1][j] = parents[i][j];
            }
        }
    }
}

void mutation(vector<vector<bool>>& population, double mutationRate) {
    int numGenes = population[0].size();

    for (int i = 0; i < population.size(); ++i) {
        for (int j = 0; j < numGenes; ++j) {
            if (rand() / static_cast<double>(RAND_MAX) < mutationRate) {
                population[i][j] = !population[i][j]; // Flip the bit
            }
        }
    }
}

void replacePopulation(vector<vector<bool>>& population, const vector<vector<bool>>& offspring)
{
    int numToReplace = offspring.size();
    int numPopulation = population.size();
    for (int i = 0; i < numToReplace; ++i)  {
        population[numPopulation - 1 - i] = offspring[i];
    }
}

int main() {
    int numTestCases;
    vector<int> KnapsackSize;
    vector< vector<Item> > testCases;
    readInputFromFile("input.txt", numTestCases, KnapsackSize, testCases);

    srand(static_cast<unsigned>(time(0)));

    for (int testCaseIndex = 0; testCaseIndex < numTestCases; ++testCaseIndex) {
        int knapsackSize = KnapsackSize[testCaseIndex];
        vector<Item>& items = testCases[testCaseIndex];
        
        int populationSize = 100;
        int numGenerations = 100;
        double mutationRate = 0.01;

        vector< vector<bool> > population;
        
        cout << "Test Case " << testCaseIndex + 1 << ":\n";
        cout << "Knapsack Size: " << KnapsackSize[testCaseIndex] << endl;
        cout << endl;
    }
    cout << "Number of test cases: " << numTestCases << endl;

    return 0;
}
