#include "ranged_attacker_widget.h"
#include "ui_KillTeamCalculator.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSpacerItem>
#include <QtCore/QSize>

ranged_attacker_widget::ranged_attacker_widget(QWidget *parent)
    : QGroupBox("Attacker", parent)
{
}

void ranged_attacker_widget::setup_ui(Ui_KillTeamCalculatorClass* ui)
{
	attacksSpinBox = ui->attacksSpinBox;
	attacksLabel = ui->attacksLabel;

	weaponScoreSpinBox = ui->weaponScoreSpinBox;
	weaponScoreLabel = ui->weaponScoreLabel;

	normalDamageSpinBox = ui->normalDamageSpinBox;
	normalDamageLabel = ui->normalDamageLabel;

	criticalDamageSpinBox = ui->criticalDamageSpinBox;
	criticalDamageLabel = ui->criticalDamageLabel;

	factionRerollsSpinBox = ui->factionAtkRerollsSpinBox;
	factionRerollsAtkLabel = ui->factionAtkRerollsLabel;

	atkRerollNormalSuccessesCheckBox = ui->atkRerollNormalSuccessesCheckBox;
	atkRerollNormalSuccessesLabel = ui->atkRerollNormalSuccessesLabel;

	accurateSpinBox = ui->accurateSpinBox;
	accurateLabel = ui->accurateLabel;

	balancedCheckBox = ui->balancedCheckBox;
	balancedLabel = ui->balancedLabel;

	ceaselessCheckBox = ui->ceaselessCheckBox;
	ceaselessLabel = ui->ceaselessLabel;

	devastatingSpinBox = ui->devastatingSpinBox;
	devastatingLabel = ui->devastatingLabel;

	lethalityCheckBox = ui->lethalityCheckBox;
	lethalitySpinBox = ui->lethalitySpinBox;
	lethalityLabel = ui->lethalityLabel;

	piercingSpinBox = ui->piercingSpinBox;
	piercingLabel = ui->piercingLabel;

	punishingCheckBox = ui->punishingCheckBox;
	punishingLabel = ui->punishingLabel;

	relentlessCheckBox = ui->relentlessCheckBox;
	relentlessLabel = ui->relentlessLabel;

	rendingCheckBox = ui->rendingCheckBox;
	rendingLabel = ui->rendingLabel;

	severeCheckBox = ui->severeCheckBox;
	severeLabel = ui->severeLabel;
}

int ranged_attacker_widget::get_attacks() const { return attacksSpinBox->value(); }
int ranged_attacker_widget::get_weapon_score() const { return weaponScoreSpinBox->value(); }
int ranged_attacker_widget::get_normal_damage() const { return normalDamageSpinBox->value(); }
int ranged_attacker_widget::get_critical_damage() const { return criticalDamageSpinBox->value(); }
int ranged_attacker_widget::get_accurate() const { return accurateSpinBox->value(); }
bool ranged_attacker_widget::is_balanced() const { return balancedCheckBox->isChecked(); }
bool ranged_attacker_widget::is_ceaseless() const { return ceaselessCheckBox->isChecked(); }
int ranged_attacker_widget::get_devastating() const { return devastatingSpinBox->value(); }
bool ranged_attacker_widget::is_lethality() const { return lethalityCheckBox->isChecked(); }
int ranged_attacker_widget::get_lethality_value() const { return lethalitySpinBox->value(); }
int ranged_attacker_widget::get_piercing() const { return piercingSpinBox->value(); }
bool ranged_attacker_widget::is_punishing() const { return punishingCheckBox->isChecked(); }
bool ranged_attacker_widget::is_relentless() const { return relentlessCheckBox->isChecked(); }
bool ranged_attacker_widget::is_rending() const { return rendingCheckBox->isChecked(); }
bool ranged_attacker_widget::is_severe() const { return severeCheckBox->isChecked(); }
int ranged_attacker_widget::get_faction_rerolls() const { return factionRerollsSpinBox->value(); }
bool ranged_attacker_widget::should_reroll_into_crits_if_not_killing() const { return atkRerollNormalSuccessesCheckBox->isChecked(); }

void ranged_attacker_widget::set_attacks(int value) { attacksSpinBox->setValue(value); }
void ranged_attacker_widget::set_weapon_score(int value) { weaponScoreSpinBox->setValue(value); }
void ranged_attacker_widget::set_normal_damage(int value) { normalDamageSpinBox->setValue(value); }
void ranged_attacker_widget::set_critical_damage(int value) { criticalDamageSpinBox->setValue(value); }
void ranged_attacker_widget::set_accurate(int value) { accurateSpinBox->setValue(value); }
void ranged_attacker_widget::set_balanced(bool value) { balancedCheckBox->setChecked(value); }
void ranged_attacker_widget::set_ceaseless(bool value) { ceaselessCheckBox->setChecked(value); }
void ranged_attacker_widget::set_devastating(int value) { devastatingSpinBox->setValue(value); }
void ranged_attacker_widget::set_lethality(bool value) { lethalityCheckBox->setChecked(value); }
void ranged_attacker_widget::set_lethality_value(int value) { lethalitySpinBox->setValue(value); }
void ranged_attacker_widget::set_piercing(int value) { piercingSpinBox->setValue(value); }
void ranged_attacker_widget::set_punishing(bool value) { punishingCheckBox->setChecked(value); }
void ranged_attacker_widget::set_relentless(bool value) { relentlessCheckBox->setChecked(value); }
void ranged_attacker_widget::set_rending(bool value) { rendingCheckBox->setChecked(value); }
void ranged_attacker_widget::set_severe(bool value) { severeCheckBox->setChecked(value); }
void ranged_attacker_widget::set_faction_rerolls(int value) { factionRerollsSpinBox->setValue(value); }
void ranged_attacker_widget::set_reroll_into_crits_if_not_killing(bool value) { atkRerollNormalSuccessesCheckBox->setChecked(value); }

void ranged_attacker_widget::reset()
{
    set_attacks(3);
    set_weapon_score(3);
    set_normal_damage(3);
    set_critical_damage(4);
    set_accurate(0);
    set_balanced(false);
    set_ceaseless(false);
    set_devastating(0);
    set_lethality(false);
    set_lethality_value(5);
    set_piercing(0);
    set_punishing(false);
    set_relentless(false);
    set_rending(false);
    set_severe(false);
    set_faction_rerolls(0);
    set_reroll_into_crits_if_not_killing(false);
}
