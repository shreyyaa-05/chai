#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Initial state: A, B, C and D are all on the table.
    cout << "QUESTION 1: BLOCKS WORLD\n\n";

    cout << "Predicates:\n";
    cout << "OnTable(x): x is on the table\n";
    cout << "On(x, y): x is on block y\n";
    cout << "Clear(x): no block is on x\n";
    cout << "Holding(x): the robot is holding x\n";
    cout << "HandEmpty: the robot is holding nothing\n\n";

    cout << "Initial state:\n";
    cout << "OnTable(A), OnTable(B), OnTable(C), OnTable(D)\n";
    cout << "Clear(A), Clear(B), Clear(C), Clear(D), HandEmpty\n\n";

    cout << "Goal state:\n";
    cout << "On(A, C) AND On(D, B)\n\n";

    cout << "Goal Stack (top to bottom):\n";
    cout << "1. On(A, C)\n";
    cout << "2. On(D, B)\n\n";

    cout << "Action sequence:\n";
    cout << "1. PickUp(A)\n";
    cout << "2. Stack(A, C)\n";
    cout << "3. PickUp(D)\n";
    cout << "4. Stack(D, B)\n\n";

    cout << "Final state:\n";
    cout << "On(A, C), On(D, B), OnTable(B), OnTable(C)\n";
    return 0;
}
