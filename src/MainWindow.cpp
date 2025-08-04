#include "MainWindow.h"
#include "../build/ui_MainWindow.h"
#include <QPushButton>
#include <qt5/QtWidgets/qmessagebox.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , db_("expenses.db")
{
    ui->setupUi(this);

    db_.open();

    expensesModel_ = new QSqlQueryModel(this);
    ui->tableView->setModel(expensesModel_);
    
    refreshTable();

    ui->tableView->setColumnWidth(0, 30);
    ui->tableView->setColumnWidth(1, 130);
    ui->tableView->setColumnWidth(2, 120);
    ui->tableView->setColumnWidth(3, 90);
    ui->tableView->setColumnWidth(4, 50);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    
    
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_ExecuteButtonAdd_clicked() {
    QString category = ui->comboBoxCategory->currentText();
    QDate date = ui->dateEdit->date();
    QString amountStr = ui->lineEditAmount->text();
    QString currency = ui->comboBoxCurrency->currentText();

    bool ok = false;
    double amount = amountStr.toDouble(&ok);

    if(!ok || amount == 0) {
        QMessageBox::warning(this, "Ошибка", "Введите положительное число в поле Amount!");
        return;
    }

    db_.addExpense(date, category, amount, currency);

    ui->lineEditAmount->clear();

    refreshTable();
}

void MainWindow::refreshTable() {
    expensesModel_->setQuery(
        "SELECT id, description AS category, date, amount, currency FROM expenses",
        db_.getDatabase()
    );
}

void MainWindow::on_ExecuteButtonDelete_clicked() {
    QString idStr = ui->lineEditID->text();

    bool ok = false;
    int id = idStr.toDouble(&ok);

    if(!ok || id == 0) {
        QMessageBox::warning(this, "Ошибка", "Введите положительное число в поле Amount!");
        return;
    }

    db_.deleteById(id);

    ui->lineEditID->clear();

    refreshTable();
}