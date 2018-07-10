#ifndef CURRENCYPROVIDER_H
#define CURRENCYPROVIDER_H

#include "currencytype.h"

#include <QObject>
#include <QVector>
#include <QSharedPointer>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QByteArray>
#include <QNetworkReply>
class CurrencyProvider : public QObject
{
    Q_OBJECT
public:
    explicit CurrencyProvider(QObject *parent = nullptr);
    void start();
signals:
    void started();
    void finished(QVector<CurrencyType> vector);
    void testFinish(QString string);
public slots:
    void responseFromNetwork(QNetworkReply* reply);

private:
    QSharedPointer<QNetworkAccessManager> _manager;
};

#endif // CURRENCYPROVIDER_H
