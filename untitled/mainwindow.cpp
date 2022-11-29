#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include <QPixmap>

std::vector<std::string> Codes = {"AUD","INR","NPR","CAD","CNY","KWD","SGD","QAR","CZK","MYR","RUB","RAD","NZD","JPY","STG","EGP","IRR","HKD","BZD","BHD","SAR"};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pic("E:/back up without api/CurrencyConverter/pic/ku");
    ui ->label_7 ->setPixmap(pic.scaled(70,70,Qt::KeepAspectRatio));

    QPixmap pix("E:/back up without api/CurrencyConverter/pic/bg");
    int w =ui ->label_9->width() ;
    int h= ui ->label_9 ->height() ;;
    ui ->label_9 ->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pi("E:/back up without api/CurrencyConverter/pic/robo");
    int l =ui ->label_8 ->width() ;
    int b= ui ->label_8 ->height() ;;
    ui ->label_8 ->setPixmap(pi.scaled(l,b,Qt::KeepAspectRatio));
    ui ->label_8->setStyleSheet("QLabel{ background-color: transparent;}");

    for(auto e:Codes){
        ui->comboBox->addItem(QString::fromLocal8Bit(e));
        ui->comboBox_2->addItem(QString::fromLocal8Bit(e));
    }
    ui->Status->setText("<font color='white'>No Conversion Done!!");
    makeConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::makeConnection(){
    std::string KEY = "7f901f5db2084e6d9f2fdbe72ec3b551";
    std::string URL = "https://api.currencyfreaks.com/latest?apikey=";
    URL+=KEY;
    URL+="&format=json";
    cpr::Response r = cpr::Get(cpr::Url{URL});
    std::cout << "Status code: " << r.status_code << '\n';
    std::string response = r.text;
    std::cout<<response<<endl;
    this->conversionRates = parseString(response);
}

void MainWindow::on_pushButton_clicked(){
    QString inCurr = ui->comboBox->currentText();
    QString outCurr = ui->comboBox_2->currentText();
    QString amount = ui->input->displayText();

    double result = giveConversion(inCurr.toLocal8Bit().constData(),outCurr.toLocal8Bit().constData(),amount.toDouble(),conversionRates);
    std::string s_result = std::to_string(result);
    std::cout<<s_result<<std::endl;
    ui->output->setText(QString::fromLocal8Bit(s_result));
    ui->Status->setText("<font color='white'>Conversion Success!!!");
}
void MainWindow::on_pushButton_2_clicked(){
    close();
}

