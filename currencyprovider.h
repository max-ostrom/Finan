#ifndef CURRENCYPROVIDER_H
#define CURRENCYPROVIDER_H

#include <QObject>

class CurrencyProvider : public QObject
{
    Q_OBJECT
public:
    explicit CurrencyProvider(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CURRENCYPROVIDER_H