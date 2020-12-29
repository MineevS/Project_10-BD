#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "mainwindow_1.h"
#include "ui_mainwindow_1.h"

MainWindow_1::MainWindow_1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_1)
{
    ui->setupUi(this);
}

MainWindow_1::~MainWindow_1()
{
    delete ui;
}

void MainWindow_1::on_pushButton_2_clicked()
{
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit->clear();
}

template <class Container>
void Split(const std::string str, Container &cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>(), std::back_inserter(cont));
}

void func(std::string str, std::vector<std::vector<std::string>> &mas)
{
       std::vector<std::string> line;

       Split(str, line);

       mas.push_back(line);
}

void func_FROM(std::string str, std::vector<std::vector<std::string>> &mas, Ui::MainWindow_1* ui)
{
    std::vector<std:: vector<std::string>>  mas1;

   // QFile File_1;
    //File_1.open(QString::fromStdString(str)));
    std::ifstream file;
    file.open(str);

    if(!file.is_open())
    {
        ui->plainTextEdit_2->appendPlainText(QString::fromStdString("ERROR!"));

        //std::cout << "ERROR!" << std::endl;
        //std::cout << file.good() << std::endl;
        //std::cout << system("DIR") << std::endl;

    }else{

        setlocale(LC_ALL,"Russian");

        while(!file.eof())
        {
            std::string temp, word, word1;

            while(file >> temp)
            {
                temp += ";";

                std::stringstream s(temp);

                std::vector<std::string> line;

                while(!getline(s, word, ';').eof())
                {
                    line.push_back(word);
                }

                mas1.push_back(line);
            }
        }

        //std::cout << std::endl;

        /*
        for(size_t i=0; i < mas1.size(); i++)
        {
            for(size_t j = 0; j < mas1[i].size(); j++)
            {
                std::cout << mas1[i][j] << " ";
            }

            std::cout << std::endl;
        }
        */


        ////////////////////
        if(mas[2][0] == "WHERE")
        {
            // WHERE <>=<>
            std::string word_5[2];
            std::stringstream w(mas[2][1]);

            int i = 0;

            while(getline(w, word_5[i], '='))
            {
                i++;
            }

            std::string massege;

            for(size_t i = 0; i < mas1[0].size(); i++) //mas1[0] - заголовок таблицы Exel.
            {
                if(word_5[0] == mas1[0][i])
                {
                    for(size_t j = 0; j < mas1.size(); j++)
                    {
                        if(word_5[1] == mas1[j][i])
                        {
                            for(size_t s = 1; s < mas[0].size(); s++)
                            {
                                std::string sot;
                                std::stringstream r(mas[0][s]);

                                getline(r, sot,',');

                                if(s != 1)
                                {
                                   massege = massege + ", ";
                                }

                                for(size_t h = 0; h < mas1[0].size(); h++)
                                {
                                    if(sot == mas1[0][h])
                                    {
                                        //ui->plainTextEdit_2->appendPlainText(QString::fromStdString(mas1[j][h]));

                                        massege = massege + mas1[j][h];
                                    }
                                }
                            }
                        }
                    }
                }
            }

            ui->plainTextEdit_2->appendPlainText(QString::fromStdString(massege));
        }
    }
}

void func_SELECT(std::vector<std::vector<std::string>> &mas, Ui::MainWindow_1* ui)
{
    //std::vector<std::vector<std::string>> tab_1;

    if(mas[1][0] == "FROM")
    {
        func_FROM(mas[1][1], mas, ui);
    }
}

void func_ALL(std::vector<std::vector<std::string>> &mas, Ui::MainWindow_1* ui)
{
    if(mas[0][0] == "SELECT"){func_SELECT(mas, ui); }
}

void MainWindow_1::on_pushButton_clicked()
{
    ui->plainTextEdit_2->clear();
    //ui->plainTextEdit_2->appendPlainText(ui->plainTextEdit->toPlainText());
    //ui->plainTextEdit_2->appendPlainText(ui->plainTextEdit->toPlainText().split(QChar('\n')).at(1));

    std::string str;
    std::vector<std::vector<std::string>> mas;

    //QString str1;
    //str1 = ui->plainTextEdit->toPlainText().split(QChar('\n')).at(1);


    for(int i = 0; i < ui->plainTextEdit->toPlainText().split(QChar('\n')).length(); i++)
    {
        str = ui->plainTextEdit->toPlainText().split(QChar('\n')).at(i).toLocal8Bit().constData();

        func(str, mas);
    }

    for(size_t i = 0; i < mas.size(); i++){

        //std::cout << mas[i] << "  ";

        //ui->plainTextEdit_2->appendPlainText(QString::fromStdString(mas[i] + "  "));
        //ui->plainTextEdit_2->appendPlainText(QString::fromStdString("  "));
    }

    func_ALL(mas, ui);

    //ui->plainTextEdit->toPlainText().split(QChar('\n')).at(1);

}

