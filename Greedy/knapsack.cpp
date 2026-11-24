#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Item{
    string name;
    double value;
    double weight;
};


double fractional_knapsack(vector<Item>& items, double capacity, unordered_map<string, double>& knapsack){
    vector<pair<double, Item>> val;
    for (const auto& i : items)
    {
        val.push_back({i.value / i.weight, i});
    }

    sort(val.begin(), val.end(), [](const pair<double, Item>& a, const pair<double, Item>& b){
        return a.first > b.first;
    });

    double total_value = 0.0;

    for (const auto& vr : val)
    {
    const Item& item = vr.second;

    if (capacity >= item.weight)
    {
        knapsack[item.name] = item.weight;
        capacity -= item.weight;
        total_value += item.value;
    } else {
        double weight_taken = capacity;
        knapsack[item.name] = weight_taken;
        total_value += (vr. first * weight_taken);
        break;
    }
    }
    return total_value;
}







int main() {


    vector<Item> items = {
        {"Gold", 5000, 10}, {"Wheat", 1000, 20}, {"Oil", 1400, 14}
    };

    double capacity = 25;
    unordered_map<string, double> knapsack;

    double total_value = fractional_knapsack(items, capacity, knapsack);

    cout << "Items in the knapsack:\n";
    for (const auto& kv : knapsack)
    {
        cout << kv.first << ": " << kv.second << " units\n";
    }
    cout << "Total value: " << total_value << endl;


    return 0;

}