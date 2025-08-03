#include <QApplication>      // Базовый класс для GUI-приложения
#include <QMessageBox>       // Простейшие диалоговые окна
#include <QtSql/QSqlDatabase> // Работа с базой данных
#include <QtSql/QSqlError>    // Для сообщений об ошибках
#include <QDebug>
#include <QApplication>

#include "Database.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    // 1) Создаём объект и сразу пытаемся открыть БД
    QApplication app(argc, argv);

    MainWindow w;
    w.show();

    return app.exec();
}