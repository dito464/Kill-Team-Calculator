#pragma once

#include <QtWidgets/QWidget>

class ranged_attacker_widget;
class ranged_defender_widget;
class ranged_output_widget;
class Ui_KillTeamCalculatorClass;
class kill_team_calculator;

class ranged_widget : public QWidget
{
    Q_OBJECT

public:
    ranged_widget(QWidget *parent = nullptr);

    ranged_attacker_widget* get_attacker_widget() const;
    ranged_defender_widget* get_defender_widget() const;
    ranged_output_widget* get_output_widget() const;
    void connect_buttons() const;
	void calculate_and_display_simulation_results() const;
    void reset();

private:
    void setup_ui(Ui_KillTeamCalculatorClass* ui);
	friend class kill_team_calculator;

    ranged_attacker_widget *attackerWidget;
    ranged_defender_widget *defenderWidget;
    ranged_output_widget *outputWidget;
};
