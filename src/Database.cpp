#include "Database.h"
#include <QDebug>

Database::Database(const QString& path)
    : db_(QSqlDatabase::addDatabase("QSQLITE"))
    , path_(path)
{}

bool Database::open() {
    db_.setDatabaseName(path_);
    if (!db_.open()) {
        qDebug() << "Ошибка открытия БД:" << db_.lastError().text();
        return false;
    }
    return true;
}

void Database::initialize() {
    QSqlQuery query(db_);
    // Схема таблицы. Обрати внимание: после каждого фрагмента
    // есть пробел в конце или в начале, чтобы SQL строка не «слипалась».
    const QString sql =
        "CREATE TABLE IF NOT EXISTS expenses ("
        " id           INTEGER PRIMARY KEY AUTOINCREMENT, "
        " description  TEXT, "
        " date         TEXT, "
        " amount       REAL, "
        " currency     TEXT"
        ");";
    if (!query.exec(sql)) {
        qDebug() << "Ошибка создания таблицы:" << query.lastError().text();
    }
}

bool Database::addExpense(const QDate&   date,
                          const QString& description,
                          double         amount,
                          const QString& currency)
{
    QSqlQuery query(db_);
    // Плейсхолдеры :desc, :d, :am, :cur
    query.prepare(
        "INSERT INTO expenses (description, date, amount, currency) "
        "VALUES (:desc, :d, :am, :cur)"
    );
    query.bindValue(":desc", description);
    // Здесь можно любой формат, например "dd-MM-yyyy":
    query.bindValue(":d",    date.toString("dd-MM-yyyy"));
    query.bindValue(":am",   amount);
    query.bindValue(":cur",  currency);

    if (!query.exec()) {
        qDebug() << "Ошибка вставки:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQuery Database::getByDate(const QDate& date) {
    QSqlQuery query(db_);
    query.prepare(
        "SELECT id, description, date, amount, currency "
        "FROM expenses "
        "WHERE date = :d "
        "ORDER BY id ASC"
    );
    // Дата должна совпадать с тем же форматом
    query.bindValue(":d", date.toString("dd-MM-yyyy"));
    query.exec();
    return query;
}

double Database::totalByCategory(const QString& description) {
    QSqlQuery query(db_);
    query.prepare(
        "SELECT SUM(amount) "
        "FROM expenses "
        "WHERE description = :desc"
    );
    query.bindValue(":desc", description);
    query.exec();
    if (query.next()) {
        // value(0) — потому что единственная колонка SUM(amount)
        return query.value(0).toDouble();
    }
    return 0.0;
}
