#pragma once

#include <QtWidgets/QGroupBox>

class QLabel;
class QSpinBox;
class QCheckBox;
class QFormLayout;
class ranged_widget;
class Ui_KillTeamCalculatorClass;

class attacker_widget : public QGroupBox
{
    Q_OBJECT

public:
    attacker_widget(QWidget *parent = nullptr);

    // Getters
    int getAttacks() const;
    int getWeaponScore() const;
    int getNormalDamage() const;
    int getCriticalDamage() const;
    int getAccurate() const;
    bool isBalanced() const;
    bool isCeaseless() const;
    int getDevastating() const;
    bool isLethality() const;
    int getLethalityValue() const;
    int getPiercing() const;
    bool isPunishing() const;
    bool isRelentless() const;
    bool isRending() const;
    bool isSevere() const;
    int getFactionRerolls() const;
    bool shouldRerollIntoCritsIfNotKilling() const;

    // Setters
    void setAttacks(int value);
    void setWeaponScore(int value);
    void setNormalDamage(int value);
    void setCriticalDamage(int value);
    void setAccurate(int value);
    void setBalanced(bool value);
    void setCeaseless(bool value);
    void setDevastating(int value);
    void setLethality(bool value);
    void setLethalityValue(int value);
    void setPiercing(int value);
    void setPunishing(bool value);
    void setRelentless(bool value);
    void setRending(bool value);
    void setSevere(bool value);
    void setFactionRerolls(int value);
    void setRerollIntoCritsIfNotKilling(bool value);

    void reset();

private:
    void setupUI(Ui_KillTeamCalculatorClass* ui);
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
