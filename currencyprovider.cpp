#include "currencyprovider.h"
#include <QXmlStreamReader>
CurrencyProvider::CurrencyProvider(QObject *parent) : QObject(parent)
{
    _manager= QSharedPointer<QNetworkAccessManager>::create(this);
    connect(_manager.operator ->(), SIGNAL(finished(QNetworkReply*)),
            this, SLOT(responseFromNetwork(QNetworkReply*)));
}
void CurrencyProvider::responseFromNetwork(QNetworkReply* reply)
{
    emit started();
    QString replyText(reply->readAll().toStdString().c_str());
    int start = replyText.indexOf("table-response mfm-table mfcur-table-lg mfcur-table-lg-currency has-no-tfoot",0);
    if(start != -1)
    {
        int end = start;
        for(; replyText.mid(end,6) != "table>" && end < replyText.size();end++)
        {
        }
        QString param = replyText.mid(start -14, end-start+6);
        qDebug() << start << " " << end-start << "\n" << param << " " << param.size();
        emit testFinish(param);
    }

    /*
    QXmlStreamReader xml(replyText.mid(start, end-start));
    while (!xml.atEnd() && !xml.hasError())
        {
            QXmlStreamReader::TokenType token = xml.readNext();
            if (token == QXmlStreamReader::StartDocument)
                continue;
            if (token == QXmlStreamReader::StartElement)
            {
                if (xml.name() == "etaps")
                    continue;
                if (xml.name() == "etap")
                    XMLConf.append(parseEtap(xml));
            }
        }
    QVector<CurrencyType> types;
    emit finished(types);*/
}
void CurrencyProvider::start()
{
    _manager->get(QNetworkRequest(QUrl("https://minfin.com.ua/currency/")));
}
