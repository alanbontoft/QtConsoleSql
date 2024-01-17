#include <QCoreApplication>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString connStr = QStringLiteral("PROBEDB");


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName(connStr);

    bool ok = false;

    ok = db.open(argv[1], argv[2]);

    if (ok)
    {
        QSqlQuery query;
        QVariant value;

        query.exec("select * from people");

        while(query.next())
        {
            value = query.value("Name");

            std::cout << value.toString().toStdString() << std::endl;

            value = query.value("Age");
            std::cout << value.toInt() << std::endl;
        }


    }

    return a.exec();
}
