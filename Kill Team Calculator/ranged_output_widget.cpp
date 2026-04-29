#include "ranged_output_widget.h"
#include "ui_KillTeamCalculator.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtCore/QSize>

ranged_output_widget::ranged_output_widget(QWidget *parent)
    : QWidget(parent)
{
}

void ranged_output_widget::setupUI(Ui_KillTeamCalculatorClass* ui)
{
	calculateButton = ui->calculateButton;
	resetButton = ui->resetButton;

	outKillPercentLabel = ui->outKillPercentLable;
	outAverageWoundsLabel = ui->outAverageWoundsLabel;
}

QPushButton* ranged_output_widget::getCalculateButton() const
{
    return calculateButton;
}

QPushButton* ranged_output_widget::getResetButton() const
{
    return resetButton;
}

void ranged_output_widget::setKillPercent(const QString &text)
{
    outKillPercentLabel->setText(text);
}

void ranged_output_widget::setAverageWounds(const QString &text)
{
    outAverageWoundsLabel->setText(text);
}

void ranged_output_widget::reset()
{
    setKillPercent(KILL_CHANCE_TEXT);
    setAverageWounds(AVERAGE_WOUNDS_TEXT);
}