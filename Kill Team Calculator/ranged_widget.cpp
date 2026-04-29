#include "ranged_widget.h"
#include "attacker_widget.h"
#include "defender_widget.h"
#include "ranged_output_widget.h"
#include "ranged_calculations.h"
#include "ui_KillTeamCalculator.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QPushButton>

ranged_widget::ranged_widget(QWidget *parent)
    : QWidget(parent)
{
}

void ranged_widget::setupUI(Ui_KillTeamCalculatorClass* ui)
{
	attackerWidget = ui->attackerWidget;
	attackerWidget->setupUI(ui);
	defenderWidget = ui->defenderWidget;
	defenderWidget->setupUI(ui);
    outputWidget = ui->outputWidget;
	outputWidget->setupUI(ui);
}

void ranged_widget::ConnectButtons() const
{
	connect(outputWidget->getCalculateButton(), &QPushButton::clicked, this, &ranged_widget::CalculateAndDisplaySimulationResults);
	connect(outputWidget->getResetButton(), &QPushButton::clicked, this, &ranged_widget::reset);
}

void ranged_widget::CalculateAndDisplaySimulationResults() const
{
    auto result = ranged_calculations::test();
	outputWidget->setKillPercent(QString::fromStdString(result));
}

void ranged_widget::reset()
{
	attackerWidget->reset();
	defenderWidget->reset();
	outputWidget->reset();
}

attacker_widget* ranged_widget::getAttackerWidget() const
{
    return attackerWidget;
}

defender_widget* ranged_widget::getDefenderWidget() const
{
    return defenderWidget;
}

ranged_output_widget* ranged_widget::getOutputWidget() const
{
    return outputWidget;
}
