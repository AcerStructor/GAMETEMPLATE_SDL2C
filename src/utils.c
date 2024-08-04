#include "utils.h"

float Get_RectMidPoint(const float centerVal, const float ScaleVal)
{
    const float midPointVal = (ScaleVal / 2); // calculate to get the middle
                                              // point
    return (centerVal - midPointVal);
}

