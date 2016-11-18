#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <ctime>
#include <array>


std::vector<bool> sieveVector(int n) {
    std::vector<bool> primeVector(n, true);
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
}

int main()
{
    std::srand(std::time(0));
    std::vector<bool> myVector = sieveVector(1000);
    for(int i = 0; i < myVector.size(); ++i)
    {
        if(myVector.at(i) && i != 0 && i != 999)
            std::cout<< i+1 << " ";
    }
    std::array<int, 100> numArray;
    auto array_it = numArray.begin();
    for(int i = 0; i < 100; ++i)
    {
        *array_it = std::modulus<int>()(std::rand(), 1000);
    }
    return 0;
}
