#include <vector>
#include <future>
#include <mutex>
#include <iostream>

using namespace std;

struct Account {
    int balance = 0;
    vector<int> history;
    mutex m;

    bool Spend(int value){
        lock_guard<mutex> g(m);
        if (value <= balance) {
            balance -= value;
            history.push_back(value);
            return true;
        }
        return false;
    }
};

int SpendMoney(Account& account){
    int totalSpent = 0;
    for(int i = 0; i < 10'000; ++i){
        if(account.Spend(1)){
            ++totalSpent;
        }
    }
    return totalSpent;
}


int main()
{
    Account familyCash{10'000};

    auto husband  = async(SpendMoney, ref(familyCash));
    auto wife     = async(SpendMoney, ref(familyCash));
    auto son      = async(SpendMoney, ref(familyCash));
    auto daughter = async(SpendMoney, ref(familyCash));

    int  spent = husband.get() + wife.get() + son.get() + daughter.get();

    cout << "Total spent: " << spent << "\n" << "Balance: " << familyCash.balance << "\n";
    return 0;
}
