#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ctime>
#include <array>


std::vector<int> sieveVector(int n) {
    std::vector<bool> primeVector(n, true);
    std::vector<int> primeNumVector;
    for(int i = 2; pow(i,2) <= n; ++i)
    {
        if(primeVector.at(i-1))
        {
            for(int j = i*2; j<n; j+=i)
            {
                primeVector.at(j-1) = false;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(primeVector.at(i) && i != 0 && i != 999)
            primeNumVector.push_back(i+1);
    }
    return primeNumVector;
}

int main()
{
    std::srand(std::time(0));
    std::vector<int> myVector = sieveVector(1000);
    std::cout<<"Prime numbers in 1 to 1000 range: ";
    for(auto i : myVector)
    {
        std::cout<<i<<" ";
    }
    std::array<int, 100> numArray;
    auto array_it = numArray.begin();
    for(int i = 0; i < 100; ++i)
    {
        *array_it = std::modulus<int>()(std::rand(), 1000);
    }
    std::map<int, std::vector<int>> divisionMap;
    auto iterator = myVector.begin();
    std::for_each(myVector.begin(), myVector.end(),
                  [](auto iterator, std::vector<int>numArray, std::map<int, std::vector<int>>divisionMap) {
                            for(int i = 0; i < numArray.size(); ++i)
                            {
                                if(numArray.at(i) % *iterator)
                                    divisionMap.emplace(std::make_pair(*iterator, numArray.at(i)));
                            }
                        }
    );
    return 0;
}
