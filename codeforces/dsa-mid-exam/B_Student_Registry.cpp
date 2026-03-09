// Contest: https://codeforces.com/contests/677363  mid-term-exam 09/03/26
// Problem: B
// Link: https://codeforces.com/gym/677363/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

class Student
{
public:
    int id;
    string name;
    int age;

    Student(int id, string name, int age)
    {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    Student() {}
};

class StudentRegistry
{
    // vector<Student> reg;
    map<int, Student> mpp;

public:
    void addStudent(Student s)
    {
        if (mpp.count(s.id))
        {
            return;
        }
        mpp.insert({s.id, s});
    }

    void removeStudent(int id)
    {
        // vector<Student> copyreg;
        // for (int i = 0; i < reg.size(); i++)
        // {
        //     if (reg[i].id != id)
        //     {
        //         copyreg.push_back(reg[i]);
        //     }
        // }
        // reg = copyreg;
        mpp.erase(id);
    }

    bool exists(int id)
    {
        // for (int i = 0; i < reg.size(); i++)
        // {
        //     if (reg[i].id == id)
        //     {
        //         return true;
        //     }
        // }
        // return false
        if (mpp.count(id))
        {
            return true;
        }
        return false;
    }

    int totalStudents()
    {
        return mpp.size();
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    StudentRegistry registry;

    int q;
    cin >> q;

    while (q--)
    {

        string op;
        cin >> op;

        if (op == "add")
        {

            int id, age;
            string name;

            cin >> id >> name >> age;

            registry.addStudent(Student(id, name, age));
        }

        else if (op == "remove")
        {

            int id;
            cin >> id;

            registry.removeStudent(id);
        }

        else if (op == "exists")
        {

            int id;
            cin >> id;

            cout << (registry.exists(id) ? "YES" : "NO") << "\n";
        }

        else if (op == "total")
        {

            cout << registry.totalStudents() << "\n";
        }
    }
}