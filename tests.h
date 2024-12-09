#pragma once
#include "candle.h"

bool test_body_contains_insideCandle()
{
    Candle candle{ 0.0, 4.0, -2.0, 3.0 };
    return candle.body_contains(2.0);
}

bool test_body_contains_outsideCandle()
{
    Candle candle{ 0.0, 4.0, -2.0, 3.0 };
    return !candle.body_contains(4.0);
}

bool test_body_contains_onEdges()
{
    Candle candle{ 0.0, 4.0, -2.0, 3.0 };
    return candle.body_contains(3.0) && candle.body_contains(0.0);
}
bool test_contains_insideBody()
{
    Candle candle{ 0.0, 4.0, -2.0, 3.0 };
    return candle.contains(1.0);
}
bool test_contains_insideShadow()
{
    Candle candle{ 0.0, 4.0, -2.0, 3.0 };
    return candle.contains(3.5);
}
bool test_contains_outsideCandle()
{
    Candle candle{ 0.0, 4.0, -2.0, 3.0 };
    return !candle.contains(-5.0);
}
bool test_full_size_zero()
{
    Candle candle{ 2.0, 2.0, 2.0, 2.0 };
    return candle.full_size() == 0;
}
bool test_full_size_posValue()
{
    Candle candle{ 2.0, 4.0, 0.0, 2.0 };
    return candle.full_size() == 4;
}
bool test_full_size_negValue()
{
    Candle candle{ 2.0, 0.0, 4.0, 2.0 };
    return candle.full_size() == 4;
}
bool test_body_size_zero()
{
    Candle candle{ 2.0, 2.0, 2.0, 2.0 };
    return candle.full_size() == 0;
}
bool test_body_size_posValue()
{
    Candle candle{ 0.0, 4.0, 0.0, 4.0 };
    return candle.full_size() == 4;
}
bool test_body_size_negValue()
{
    Candle candle{ 4.0, 0.0, 4.0, 0.0 };
    return candle.full_size() == 4;
}
//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;
void initTests()
{
    tests.push_back(test_body_contains_insideCandle);
    tests.push_back(test_body_contains_outsideCandle);
    tests.push_back(test_body_contains_onEdges);
    tests.push_back(test_contains_insideBody);
    tests.push_back(test_contains_insideShadow);
    tests.push_back(test_contains_outsideCandle);
    tests.push_back(test_full_size_zero);
    tests.push_back(test_full_size_posValue);
    tests.push_back(test_full_size_negValue);
    tests.push_back(test_body_size_zero);
    tests.push_back(test_body_size_posValue);
    tests.push_back(test_body_size_negValue);
}

int launchTests()
{
    int total = 0;
    int passed = 0;

    for (const auto& test : tests)
    {
        std::cout << "test #" << (total + 1);
        if (test())
        {
            passed += 1;
            std::cout << " passed\n";
        }
        else
        {
            std::cout << " failed\n";
        }
        total += 1;
    }

    std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

    //0 = success
    return total - passed;
}