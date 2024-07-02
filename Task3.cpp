//
// На рынок было приглашено N продавцов с пирогами, 
// каждый должен был принести заранее заданное количество пирогов. 
// К сожалению один продавец не пришел. Распечатайте по возрастанию 
// все возможные варианты суммарного количества пирогов на рынке (C++ 17):
// 
// Пример ввода:
// 10 5 2 7 1 4 4 3 2 1 9
// Первое число 10 – количество торговцев, далее идет сколько каждый из них должен был принести пирогов.
//

#include <iostream>
#include <vector>
#include <algorithm>

void calculate(std::vector<int>& pies)
{
    std::sort(pies.begin(), pies.end(), std::greater<int>());
    int sum = 0;
    for (auto it : pies)
    {
        sum += it;
    }
    for (auto& it : pies)
    {
        it = sum - it;
    }
}

int main() {

 while (true)
    {
        int numSellers;
        std::cout << "Enter number of sellers and pies: ";

        while (!(std::cin >> numSellers))
        {
            std::cin.clear();
            std::string clear;
            getline(std::cin, clear);
            std::cout << "Please enter the correct number of sellers: ";
        }

        if (numSellers < 1)
        {
            std::cout << "Please enter only positive values!" << std::endl;
            std::string clear;
            getline(std::cin, clear);
            continue;
        }

        std::vector<int> pies(numSellers);

        bool noPositiveValue = false;

        for (int i = 0; i < numSellers; ++i) {
            while (!(std::cin >> pies[i]))
            {
                std::cout << "Please enter the correct number of sellers and pies: ";
                i = 0;
                std::cin.clear();
                std::string clear;
                getline(std::cin, clear);
            }
            if (pies[i] < 0)
            {
                noPositiveValue = true;
                break;
            }
        }

        if (noPositiveValue)
        {
            std::cout << "Please enter only positive values" << std::endl;
            std::string clear;
            getline(std::cin, clear);
            continue;
        }

        calculate(pies);

        std::cout << "Sum pies: ";
        for (const auto& sumPies : pies) {
            std::cout << sumPies << " ";
        }
        std::cout << std::endl;
        std::string clear;
        getline(std::cin, clear);
    }
   return 0;
}