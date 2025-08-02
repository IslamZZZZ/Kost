#include <QApplication>      // Базовый класс для GUI-приложения
#include <QMessageBox>       // Простейшие диалоговые окна
#include <QtSql/QSqlDatabase> // Работа с базой данных
#include <QtSql/QSqlError>    // Для сообщений об ошибках

int main(int argc, char *argv[]) {
    // 1) Создаём объект приложения. Без него Qt-виджеты не работают.
    QApplication app(argc, argv);

    // 2) Настраиваем соединение с SQLite
    //    QSQLITE — это драйвер, встроенный в Qt, который умеет работать с .db-файлом.
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");  // если файла нет, SQLite создаст его


    // 4) Всё ок — покажем простое сообщение “всё работает”
    QMessageBox::information(nullptr, "Qt ✔️", "Qt и SQLite работают!");

    // 5) Запускаем главный цикл обработки событий (нужно для GUI).
    return 0;
    return app.exec();
}