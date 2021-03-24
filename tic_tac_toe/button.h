#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QPushButton>

class Button:public QPushButton
{
    Q_OBJECT
public:
    Button(int sor,int oszlop);
    int erintett;
    int sor;
    int oszlop;

};

#endif // BUTTON_H
