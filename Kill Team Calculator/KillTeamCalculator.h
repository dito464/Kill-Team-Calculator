/*#pragma once

#include <QtWidgets/QMainWindow>
#include "ranged_widget.h"

class kill_team_calculator : public QMainWindow
{
    Q_OBJECT

public:
    kill_team_calculator(QWidget *parent = nullptr);
    ~kill_team_calculator();

private:
    RangedWidget *rangedWidget;
};
*/

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_KillTeamCalculator.h"

class kill_team_calculator : public QMainWindow
{
    Q_OBJECT

public:
    kill_team_calculator(QWidget* parent = nullptr);
    ~kill_team_calculator();

private:
    Ui::KillTeamCalculatorClass ui;
};