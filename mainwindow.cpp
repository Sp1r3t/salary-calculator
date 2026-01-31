#include "mainwindow.h"
#include "ui_mainwindow.h"

CalculateSalary::CalculateSalary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalculateSalary)
    , money(new Money)
{
    ui->setupUi(this);
    this->setWindowTitle("SalaryCalculater for my Cami");
}

CalculateSalary::~CalculateSalary()
{
    delete ui;
    delete money;
}

void Money::SetSalary(int money) {
    salary_ = money;
}

int Money::GetSalary()  const{
    return salary_;
}

int Money::GetMoneyForTravel() const{
    return (GetSalary() * 0.5);
}

int Money::GetMoneyForEat() const{
    return (GetSalary() * 0.17);
}

int Money::GetMoneyForGym() const{
    return (GetSalary() * 0.03);
}

int Money::GetMoneyForPresent() const{
    return (GetSalary() * 0.08);
}

int Money::GetMoneyForReserve() const{
    return (GetSalary() * 0.05);
}

int Money::GetMoneyForCredit() const{
    return (GetSalary() * 0.12);
}

int Money::GetMoneyForSmth() const{
    return (GetSalary() * 0.05);
}

void CalculateSalary::on_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    int salary = arg1.toInt(&ok);
    if (arg1.isEmpty()) {
        money->SetSalary(0);

        ui->tl_travel->setText("0");
        ui->tl_eat->setText("0");
        ui->tl_credit->setText("0");
        ui->tl_present->setText("0");
        ui->tl_gym->setText("0");
        ui->tl_smth->setText("0");
        ui->tl_reserve->setText("0");
        return;
    }

    if (ok) {
        money->SetSalary(salary);

        ui->tl_travel->setText(QString::number(money->GetMoneyForTravel()));
        ui->tl_eat->setText(QString::number(money->GetMoneyForEat()));
        ui->tl_credit->setText(QString::number(money->GetMoneyForCredit()));
        ui->tl_present->setText(QString::number(money->GetMoneyForPresent()));
        ui->tl_gym->setText(QString::number(money->GetMoneyForGym()));
        ui->tl_smth->setText(QString::number(money->GetMoneyForSmth()));
        ui->tl_reserve->setText(QString::number(money->GetMoneyForReserve()));
    }
    else {
        ui->tl_travel->setText("Error!");
        ui->tl_eat->setText("Error!");
        ui->tl_credit->setText("Error!");
        ui->tl_present->setText("Error!");
        ui->tl_gym->setText("Error!");
        ui->tl_smth->setText("Error!");
        ui->tl_reserve->setText("Error!");
    }
}

