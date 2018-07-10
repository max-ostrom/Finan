#ifndef CURRENCYTYPE_H
#define CURRENCYTYPE_H

#include <QObject>

class CurrencyType : public QObject
{
    Q_OBJECT
public:
    explicit CurrencyType(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CURRENCYTYPE_H