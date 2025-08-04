#pragma once

#include <QMainWindow>
#include <QSqlQueryModel>
#include "Database.h"

namespace Ui{
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ExecuteButtonAdd_clicked();
    void on_ExecuteButtonDelete_clicked();


private:
    Ui::MainWindow *ui;
    QSqlQueryModel *expensesModel_;
    Database db_;

    void refreshTable();
};