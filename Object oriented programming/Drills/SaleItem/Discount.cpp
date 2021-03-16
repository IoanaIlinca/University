#include "Discount.h"

double ItemDiscount::calc(Sale s)
{
    for (auto item : s.GetItems())
    {
        if (item.GetCode() == code)
            return (item.GetPrice() * percentage) / 100.0;
    }
}

int ItemDiscount::GetCode()
{
    return code;
}

void SumDiscount::add(shared_ptr<Discount> d)
{
    discounts.push_back(d);
}

double SumDiscount::calc(Sale s)
{
    double sum = 0.0;
    for (auto disc : discounts)
    {
        double d = disc->calc(s);
        sum += d;

    }
    return sum;
}
