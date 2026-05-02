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

void ranged_output_widget::setup_ui(Ui_KillTeamCalculatorClass* ui)
{
	calculateButton = ui->calculateButton;
	resetButton = ui->resetButton;

	outKillPercentLabel = ui->outKillPercentLable;
	outAverageWoundsLabel = ui->outAverageWoundsLabel;
}

QPushButton* ranged_output_widget::get_calculate_button() const
{
    return calculateButton;
}

QPushButton* ranged_output_widget::get_reset_button() const
{
    return resetButton;
}

void ranged_output_widget::set_kill_percent(const QString &text)
{
    outKillPercentLabel->setText(text);
}

void ranged_output_widget::set_average_wounds(const QString &text)
{
    outAverageWoundsLabel->setText(text);
}

void ranged_output_widget::reset()
{
    set_kill_percent(KILL_CHANCE_TEXT);
    set_average_wounds(AVERAGE_WOUNDS_TEXT);
}