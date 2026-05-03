#pragma once

#include <QtWidgets/QGroupBox>

class QLabel;
class QSpinBox;
class QCheckBox;
class QFormLayout;
class ranged_widget;
class Ui_KillTeamCalculatorClass;

class ranged_defender_widget : public QGroupBox
{
    Q_OBJECT

public:
    ranged_defender_widget(QWidget *parent = nullptr);

    // Getters
    int get_wounds() const;
    int get_save() const;
    bool has_cover() const;
    bool is_obscured() const;
    int get_faction_rerolls() const;
	bool is_reroll_aggressively() const;

    // Setters
    void set_wounds(int value);
    void set_save(int value);
    void set_cover(bool value);
    void set_obscured(bool value);
    void set_faction_rerolls(int value);
	void set_reroll_aggressively(bool value);

    void reset();

private:
    void setup_ui(Ui_KillTeamCalculatorClass* ui);
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
	QLabel* defRerollNormalSuccessesLabel;
	QCheckBox* defRerollNormalSuccessesCheckBox;
};
