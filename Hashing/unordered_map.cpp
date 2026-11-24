#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, string> person = {
        {"name", "Cristiano"},
        {"age", "40"},
        {"jersey", "7"}
    };

    cout << person["name"] << endl;

    person["club"] = "Al Nassr";

    person.erase("age");

    for (const auto& p : person)
    {
        cout << p.first << " : " << p.second << endl;
    }

    if (person.find("jersey") != person.end())
    {
        cout << "kit: " << person["jersey"] << endl;
    }


return 0;



}