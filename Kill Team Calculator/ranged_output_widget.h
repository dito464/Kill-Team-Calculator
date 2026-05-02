#pragma once

#include <QtWidgets/QWidget>

class QLabel;
class QPushButton;
class QVBoxLayout;
class ranged_widget;
class Ui_KillTeamCalculatorClass;

class ranged_output_widget : public QWidget
{
    Q_OBJECT

public:

    constexpr static auto KILL_CHANCE_TEXT = "Kill Chance:";
    constexpr static auto AVERAGE_WOUNDS_TEXT = "Average Wounds:";

    ranged_output_widget(QWidget *parent = nullptr);

    QPushButton* get_calculate_button() const;
    QPushButton* get_reset_button() const;
    void set_kill_percent(const QString &text);
    void set_average_wounds(const QString &text);
	void reset();

private:
    void setup_ui(Ui_KillTeamCalculatorClass* ui);
    friend class ranged_widget;

    QPushButton *calculateButton;
    QPushButton *resetButton;
    QLabel *outKillPercentLabel;
    QLabel *outAverageWoundsLabel;
};
