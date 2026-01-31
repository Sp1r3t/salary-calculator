#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CalculateSalary;
}
QT_END_NAMESPACE

class Money {
public:
    void SetSalary(int money);
    int GetSalary() const;

    int GetMoneyForTravel() const;
    int GetMoneyForEat() const;
    int GetMoneyForGym() const;
    int GetMoneyForPresent() const;
    int GetMoneyForReserve() const;
    int GetMoneyForCredit() const;
    int GetMoneyForSmth() const;
private:
    int salary_ = 0;
    int travel_ = 0;
    int eat_ = 0;
    int credit_ = 0;
    int gym_ = 0;
    int present_ = 0;
    int smth_ = 0;
    int reserve_ = 0;
};

class CalculateSalary : public QMainWindow
{
    Q_OBJECT

public:
    CalculateSalary(QWidget *parent = nullptr);
    ~CalculateSalary();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::CalculateSalary *ui;
    Money* money;
};

#endif // MAINWINDOW_H
