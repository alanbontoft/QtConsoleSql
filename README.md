# QtConsoleSql
Very simple console app to test access to MS SQL Server from Raspberry Pi

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
