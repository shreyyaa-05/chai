#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<double>> T = {
        {0.5, 0.25, 0.25},
        {1.0 / 3, 0, 2.0 / 3},
        {0.5, 0.5, 0}
    };

    vector<double> state = {0, 1, 0};

    cout << fixed << setprecision(6);

    cout << "Transition Probability Matrix:\n";
    for (auto row : T) {
        for (double x : row)
            cout << x << " ";
        cout << "\n";
    }

    cout << "\nDay 0: ";
    for (double x : state)
        cout << x << " ";

    for (int day = 1; day <= 10000; day++) {
        vector<double> next(3, 0);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                next[j] += state[i] * T[i][j];
            }
        }

        double diff = 0;

        for (int i = 0; i < 3; i++)
            diff = max(diff, abs(next[i] - state[i]));

        state = next;

        cout << "\nDay " << day << ": ";
        for (double x : state)
            cout << x << " ";

        if (diff < 1e-10)
            break;
    }

    cout << "\n";
    return 0;
}
