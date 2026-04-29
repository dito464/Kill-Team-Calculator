/*#pragma once

#include <QtWidgets/QMainWindow>
#include "ranged_widget.h"

class KillTeamCalculator : public QMainWindow
{
    Q_OBJECT

public:
    KillTeamCalculator(QWidget *parent = nullptr);
    ~KillTeamCalculator();

private:
    RangedWidget *rangedWidget;
};
*/

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KillTeamCalculator.h"

class KillTeamCalculator : public QMainWindow
{
    Q_OBJECT

public:
    KillTeamCalculator(QWidget* parent = nullptr);
    ~KillTeamCalculator();

private:
    Ui::KillTeamCalculatorClass ui;
};