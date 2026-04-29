#pragma once

#include <QtWidgets/QGroupBox>

class QLabel;
class QSpinBox;
class QCheckBox;
class QFormLayout;
class ranged_widget;
class Ui_KillTeamCalculatorClass;

class defender_widget : public QGroupBox
{
    Q_OBJECT

public:
    defender_widget(QWidget *parent = nullptr);

    // Getters
    int getWounds() const;
    int getSave() const;
    bool hasCover() const;
    bool isObscured() const;
    int getFactionRerolls() const;
	bool isRerollAggressively() const;

    // Setters
    void setWounds(int value);
    void setSave(int value);
    void setCover(bool value);
    void setObscured(bool value);
    void setFactionRerolls(int value);
	void setRerollAggressively(bool value);

    void reset();

private:
    void setupUI(Ui_KillTeamCalculatorClass* ui);
    friend class ranged_widget;

    QFormLayout *defenderForm;
    QLabel *woundsLabel;
    QSpinBox *woundsSpinBox;
    QLabel *saveLabel;
    QSpinBox *saveSpinBox;
    QLabel *coverLabel;
    QCheckBox *coverCheckBox;
    QLabel *obscuredLabel;
    QCheckBox *obscuredCheckBox;
    QLabel *factionDefRerollsLabel;
    QSpinBox *factionDefRerollsSpinBox;
	QLabel* rerollIntoCritsIfAnyLabel;
	QCheckBox* rerollIntoCritsIfAnyCheckBox;
};
