#pragma once

#include <QtWidgets/QGroupBox>

class QLabel;
class QSpinBox;
class QCheckBox;
class QFormLayout;
class ranged_widget;
class Ui_KillTeamCalculatorClass;

class ranged_attacker_widget : public QGroupBox
{
    Q_OBJECT

public:
    ranged_attacker_widget(QWidget *parent = nullptr);

    // Getters
    int get_attacks() const;
    int get_weapon_score() const;
    int get_normal_damage() const;
    int get_critical_damage() const;
    int get_accurate() const;
    bool is_balanced() const;
    bool is_ceaseless() const;
    int get_devastating() const;
    bool is_lethality() const;
    int get_lethality_value() const;
    int get_piercing() const;
    bool is_punishing() const;
    bool is_relentless() const;
    bool is_rending() const;
    bool is_severe() const;
    int get_faction_rerolls() const;
    bool should_reroll_into_crits_if_not_killing() const;

    // Setters
    void set_attacks(int value);
    void set_weapon_score(int value);
    void set_normal_damage(int value);
    void set_critical_damage(int value);
    void set_accurate(int value);
    void set_balanced(bool value);
    void set_ceaseless(bool value);
    void set_devastating(int value);
    void set_lethality(bool value);
    void set_lethality_value(int value);
    void set_piercing(int value);
    void set_punishing(bool value);
    void set_relentless(bool value);
    void set_rending(bool value);
    void set_severe(bool value);
    void set_faction_rerolls(int value);
    void set_reroll_into_crits_if_not_killing(bool value);

    void reset();

private:
    void setup_ui(Ui_KillTeamCalculatorClass* ui);
    friend class ranged_widget;

    QFormLayout *attackerForm;
    QLabel *attacksLabel;
    QSpinBox *attacksSpinBox;
    QLabel *weaponScoreLabel;
    QSpinBox *weaponScoreSpinBox;
    QLabel *normalDamageLabel;
    QSpinBox *normalDamageSpinBox;
    QLabel *criticalDamageLabel;
    QSpinBox *criticalDamageSpinBox;
    QLabel *accurateLabel;
    QSpinBox *accurateSpinBox;
    QLabel *balancedLabel;
    QCheckBox *balancedCheckBox;
    QLabel *ceaselessLabel;
    QCheckBox *ceaselessCheckBox;
    QLabel *devastatingLabel;
    QSpinBox *devastatingSpinBox;
    QLabel *lethalityLabel;
    QCheckBox *lethalityCheckBox;
    QSpinBox *lethalitySpinBox;
    QLabel *piercingLabel;
    QSpinBox *piercingSpinBox;
    QLabel *punishingLabel;
    QCheckBox *punishingCheckBox;
    QLabel *relentlessLabel;
    QCheckBox *relentlessCheckBox;
    QLabel *rendingLabel;
    QCheckBox *rendingCheckBox;
    QLabel *severeLabel;
    QCheckBox *severeCheckBox;
    QLabel *factionRerollsAtkLabel;
    QSpinBox *factionRerollsSpinBox;
    QLabel *rerollIntoCritsIfNotKillingLabel;
    QCheckBox *rerollIntoCritsIfNotKillingCheckBox;
};
