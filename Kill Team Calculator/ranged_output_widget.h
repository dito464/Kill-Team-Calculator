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
    ranged_output_widget(QWidget *parent = nullptr);

    QPushButton* getCalculateButton() const;
    QPushButton* getResetButton() const;
    void setKillPercent(const QString &text);
    void setAverageWounds(const QString &text);
	void reset();

private:
    void setupUI(Ui_KillTeamCalculatorClass* ui);
    friend class ranged_widget;

    QPushButton *calculateButton;
    QPushButton *resetButton;
    QLabel *outKillPercentLabel;
    QLabel *outAverageWoundsLabel;
};
