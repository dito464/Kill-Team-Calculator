#pragma once

#include <QtWidgets/QWidget>

class attacker_widget;
class defender_widget;
class ranged_output_widget;
class Ui_KillTeamCalculatorClass;
class KillTeamCalculator;

class ranged_widget : public QWidget
{
    Q_OBJECT

public:
    ranged_widget(QWidget *parent = nullptr);

    attacker_widget* getAttackerWidget() const;
    defender_widget* getDefenderWidget() const;
    ranged_output_widget* getOutputWidget() const;
    void ConnectButtons() const;
	void CalculateAndDisplaySimulationResults() const;
    void reset();

private:
    void setupUI(Ui_KillTeamCalculatorClass* ui);
	friend class KillTeamCalculator;

    attacker_widget *attackerWidget;
    defender_widget *defenderWidget;
    ranged_output_widget *outputWidget;
};
