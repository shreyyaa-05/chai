#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> students = {"Ravi", "Anu"};
    vector<pair<string, string>> studies = {
        {"Ravi", "AI"}, {"Anu", "ML"}
    };
    vector<pair<string, string>> passed = {
        {"Ravi", "AI"}
    };
    vector<pair<string, string>> supervises = {
        {"DrSharma", "Ravi"}
    };

    vector<string> qualified, researcher, eligible;

    cout << "QUESTION 2: KNOWLEDGE-BASED SYSTEM\n\n";

    cout << "(i) First-Order Logic policies:\n";
    cout << "1. For every student x, there exists a course y such that "
            "Course(y) AND Studies(x, y).\n";
    cout << "2. For all x and y: (Student(x) AND Course(y) AND Studies(x, y) "
            "AND Passed(x, y)) -> Qualified(x).\n";
    cout << "3. For all x and p: (Qualified(x) AND Professor(p) AND "
            "Supervises(p, x)) -> Researcher(x).\n";
    cout << "4. For all x: Researcher(x) -> Eligible(x).\n\n";

    cout << "(ii) Explanation:\n";
    cout << "No. The statement only says that each student studies at least "
            "one course. The course can be different for different students.\n";
    cout << "No. We cannot conclude that every student studies AI. "
            "For example, Anu studies ML.\n\n";

    // Rule 1: a student is qualified if they study and pass the same course.
    for (const auto &s : studies) {
        for (const auto &p : passed) {
            if (s.first == p.first && s.second == p.second) {
                qualified.push_back(s.first);
            }
        }
    }

    cout << "(iii) Forward-chaining steps:\n";
    for (const string &s : qualified) {
        cout << "Rule 2: Qualified(" << s
             << ") because the student studies and passed the same course.\n";
    }

    // Rule 2: a qualified student supervised by a professor is a researcher.
    for (const string &s : qualified) {
        for (const auto &sp : supervises) {
            if (sp.second == s) {
                researcher.push_back(s);
                cout << "Rule 3: Researcher(" << s
                     << ") because " << sp.first << " supervises " << s << ".\n";
            }
        }
    }

    // Rule 3: every researcher is eligible.
    for (const string &s : researcher) {
        eligible.push_back(s);
        cout << "Rule 4: Eligible(" << s << ").\n";
    }

    cout << "\nConclusion: ";
    bool raviEligible = false;
    for (const string &s : eligible) {
        if (s == "Ravi") raviEligible = true;
    }

    if (raviEligible)
        cout << "Eligible(Ravi) can be derived.\n";
    else
        cout << "Eligible(Ravi) cannot be derived.\n";

    return 0;
}
