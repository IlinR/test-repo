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