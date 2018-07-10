#ifndef CURRENCYTYPE_H
#define CURRENCYTYPE_H
#include <QString>
enum ExchangeType
{
    BLACK,
    CASH,
    NATIONAL
};
class CurrencyType
{
public:
    CurrencyType(const QString CurrencyName, const double_t Value,
                 ExchangeType ExchangeType);
QString getName() const;
double_t getValue() const;
ExchangeType getType() const;
private:
    const QString _currencyName;
    const double_t _value;
    const ExchangeType _exchangeType;
};

#endif // CURRENCYTYPE_H
