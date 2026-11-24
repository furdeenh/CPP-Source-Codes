#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int, int>> coin_change(vector<int>& coins_denomination, int target_value){
    // Sort the coins in descending order
    sort(coins_denomination.rbegin(), coins_denomination.rend());
    vector<pair<int, int>> coin_count;

    for (int coin : coins_denomination)
    {
        if (target_value >= coin)
        {
            int count = target_value / coin;         // 62 / 25 = 2;
            target_value %= coin;                   // 62 % 25 = 12;
            coin_count.push_back({coin, count});
        }
    }
    if(target_value == 0)
    {
        return coin_count;
    }
    return {};
}

int main()
{
    vector<int> coins_denomination = {1, 5, 10, 25};
    int target_value = 62;

    vector<pair<int, int>> coin_count = coin_change(coins_denomination, target_value);

    if(!coin_count.empty())
    {
        for (const auto& cp : coin_count)
        {
            cout << "Use " << cp.second << " coins of $" << cp.first << endl;
        }
    } else {
        cout << "It is not possible to achieve the target value with the given denominatrions." << endl;
    }
    return 0;
}