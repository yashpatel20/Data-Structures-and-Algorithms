#include <bits/stdc++.h>
using namespace std;

//sorting for custom classes
struct Student
{
    string name;
    double gpa;
    //overload operator<
    bool operator<(const Student &that)
    {
        return name < that.name;
    }
};

void sortByName(vector<Student> &students)
{
    sort(students.begin(), students.end());
}

void sortByGpa(vector<Student> &students)
{
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) { return a.gpa >= b.gpa; });
}

int main()
{
}