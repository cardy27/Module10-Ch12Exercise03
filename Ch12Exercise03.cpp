// Kristoffer Carlino
// C++ 310
// Dr. Robert Flowers
// Ch12Exercise03.cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int numCandidates;

    cout << "Enter the number of candidates: ";
    cin >> numCandidates;
    cin.ignore();  // Clear newline for getline

    // Dynamically allocate arrays
    string* names = new string[numCandidates];
    int* votes = new int[numCandidates];
    double* percentages = new double[numCandidates];

    int totalVotes = 0;

    // Input candidate names and votes
    for (int i = 0; i < numCandidates; i++) {
        cout << "\nEnter candidate " << i + 1 << " name: ";
        getline(cin, names[i]);

        cout << "Enter votes received by " << names[i] << ": ";
        cin >> votes[i];
        cin.ignore();

        totalVotes += votes[i];
    }

    // Compute percentages
    for (int i = 0; i < numCandidates; i++) {
        percentages[i] = (static_cast<double>(votes[i]) / totalVotes) * 100.0;
    }

    // Determine winner
    int winnerIndex = 0;
    for (int i = 1; i < numCandidates; i++) {
        if (votes[i] > votes[winnerIndex]) {
            winnerIndex = i;
        }
    }

    // Display results
    cout << fixed << setprecision(2);
    cout << "\n\nElection Results:\n";
    cout << "--------------------------------------------\n";
    cout << left << setw(20) << "Candidate"
        << setw(10) << "Votes"
        << setw(10) << "Percent" << endl;
    cout << "--------------------------------------------\n";

    for (int i = 0; i < numCandidates; i++) {
        cout << left << setw(20) << names[i]
            << setw(10) << votes[i]
            << setw(10) << percentages[i] << endl;
    }

    cout << "--------------------------------------------\n";
    cout << "Total Votes: " << totalVotes << endl;
    cout << "Winner: " << names[winnerIndex] << endl << endl;

    // Free memory
    delete[] names;
    delete[] votes;
    delete[] percentages;

    return 0;
}
