#pragma once

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDate>
#include <QString>

/**
 * @brief Обёртка для работы с SQLite (таблица expenses).
 */
class Database {
public:
    Database(const QString& path = "expenses.db");  // можно без аргумента
    QSqlDatabase& getDatabase();

    bool open();
    void initialize();

    bool addExpense(const QDate&   date,
                    const QString& description,
                    double         amount,
                    const QString& currency);

    bool deleteById(int id);

    QSqlQuery getByDate(const QDate& date);
    double    totalByCategory(const QString& description);

private:
    QSqlDatabase db_;
    QString      path_;
};
