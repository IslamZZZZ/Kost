#include <QApplication>      // Базовый класс для GUI-приложения
#include <QMessageBox>       // Простейшие диалоговые окна
#include <QtSql/QSqlDatabase> // Работа с базой данных
#include <QtSql/QSqlError>    // Для сообщений об ошибках
#include <QDebug>

#include "Database.h"

int main(int argc, char *argv[]) {
    // 1) Создаём объект и сразу пытаемся открыть БД
    Database exp("exp.db");
    if (!exp.open()) {
        qDebug() << "Не удалось открыть базу — выходим";
        return -1;
    }

    // 2) Создаём таблицу (если нужно)
    exp.initialize();
    QString desc1 = "Shop";
    QString desc2 = "Laptop";
    QString desc3 = "Restourant";
    QString cur = "RUB";
    QDate date = {2004, 4, 4};
    exp.addExpense(date, desc1, 500, cur);
    exp.addExpense({2005, 6, 5}, desc2, 150000, cur);
    exp.addExpense(date, desc3, 1500, cur);
    return 0;
}