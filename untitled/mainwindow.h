#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <cpr/cpr.h>
#include <iostream>
#include "converter.h"
#include <map>
#include <string.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::map<std::string,double> conversionRates;
    void makeConnection();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();



private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
