#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include "button.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int matrix[3][3],gyoztes,l=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matrix[i][j]=100-l;
            l++;
        }
    }

    QGridLayout *layout = new QGridLayout;
    QWidget *centralWidget = new QWidget;

    int lepes=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            Button* button=new Button(i,j);
            button->setStyleSheet("font-size: 100px;background-color:#8A39B8;color:white;");
            button->setMaximumSize(450,450);
            button->move(40*j, 40*i);
            button->show();
            layout->addWidget(button, i, j);
            connect(button,&QPushButton::clicked,this,[&](){
                button = qobject_cast<Button *>(sender());
                if(button->erintett==0){
                  if(lepes%2==0){
                      button->setText("X");
                      button->erintett=1;
                      matrix[button->sor][button->oszlop]=1;
                  }
                  else{
                      button->setText("O");
                      button->erintett=2;
                      matrix[button->sor][button->oszlop]=2;
                  }
                  lepes++;

                }


                if(dontetlen(matrix)==true){
                    QMessageBox::about(this,"Vege!","Dontetlen!");
                    QApplication::quit();
                }

                gyoztes=nyert(matrix);


                if(gyoztes==1){
                    QMessageBox::about(this,"Vege!","X nyert!");
                    QApplication::quit();
                }

                if(gyoztes==2){
                    QMessageBox::about(this,"Vege!","O nyert!");
                    QApplication::quit();
                }

            });
        }

    }


    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

}

int MainWindow::nyert(int m[][3]){


   if(m[0][0]==m[0][1] && m[0][1]==m[0][2])
       return m[0][0];

   if(m[1][0]==m[1][1] && m[1][1]==m[1][2])
       return m[1][0];

   if(m[2][0]==m[2][1] && m[2][1]==m[2][2])
       return m[2][0];


   if(m[0][0]==m[1][0] && m[1][0]==m[2][0])
       return m[0][0];

   if(m[0][1]==m[1][1] && m[1][1]==m[2][1])
       return m[0][1];

   if(m[0][2]==m[1][2] && m[1][2]==m[2][2])
       return m[0][2];

   if(m[0][0]==m[1][1] && m[1][1]==m[2][2])
       return m[0][0];

   if(m[2][0]==m[1][1] && m[1][1]==m[0][2])
       return m[2][0];


   return 0;
}

bool MainWindow::dontetlen(int m[][3]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!(m[i][j]==1 || m[i][j]==2))
                return false;
        }
    }

    return true;
}

MainWindow::~MainWindow()
{
    delete ui;
}




