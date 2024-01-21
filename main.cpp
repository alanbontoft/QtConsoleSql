#include <QCoreApplication>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVariant>
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // check enough params passed, should be user, password, database name
    if (argc < 4)
    {
        std::cout << QString("3 parameters expected, %1 passed").arg(argc - 1).toStdString() << std::endl;
        return -1;
    }

    // create connection string
    // Driver name must match an entry in /etc/odbcinst.ini
    QString connStr;

    // Microsoft driver
    connStr = QStringLiteral("DRIVER={ODBC Driver 18 for SQL Server};SERVER=iot-server;PORT=1433;DATABASE=%1;TrustServerCertificate=yes;").arg(argv[3]);
    // TDS driver
    connStr = QStringLiteral("DRIVER={FreeTDS};SERVER=iot-server;PORT=1433;DATABASE=%1;TrustServerCertificate=yes;").arg(argv[3]);

    // display connection string
    std::cout << "Connection string: " << connStr.toStdString() << std::endl;


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    // apply connection string to database
    db.setDatabaseName(connStr);

    bool ok = false;

    // open connection, passing user and password
    ok = db.open(argv[1], argv[2]);

    // if connected, perfoem query on people table and display results
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
    else
    {
        // display error message
        std::cout << db.lastError().text().toStdString() << std::endl;
    }

    return a.exec();
}
