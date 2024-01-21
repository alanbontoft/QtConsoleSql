# QtConsoleSql
Very simple console app to test access to MS SQL Server from Raspberry Pi & Linux

install following on RPi:

sudo apt install unixodbc
sudo apt install unixodbc-dev
sudo apt install freetds-dev
sudo apt install tdsodbc
sudo apt install freetds-bin 

copy following config files to /etc and /etc/freetds:

odbc.ini
odbcinst.ini
freetds.conf

Things I think are correct regarding ini/config files:
1) An entry is required in odbcinst.ini for use by the connection string Driver parameter.  Only odbcinst.ini is required for database access via Qt code.
2) When using the tsql utility, pass the section name (e.g. MySqlServer) from freetds.conf to the -S parameter, along with username and password
3) It appears odbc.ini is only needed by the isql utility
