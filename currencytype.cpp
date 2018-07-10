#include "currencytype.h"
CurrencyType::CurrencyType(QString CurrencyName, double_t Value, ExchangeType exchangeType)
    : _currencyName(CurrencyName), _value(Value), _exchangeType(exchangeType)
{

}
QString CurrencyType::getName() const
{
    return _currencyName;
}
double_t CurrencyType::getValue() const
{
    return _value;
}
ExchangeType CurrencyType::getType() const
{
    return _exchangeType;
}
