#include "attacker_widget.h"
#include "ui_KillTeamCalculator.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QSpacerItem>
#include <QtCore/QSize>

attacker_widget::attacker_widget(QWidget *parent)
    : QGroupBox("Attacker", parent)
{
}

void attacker_widget::setupUI(Ui_KillTeamCalculatorClass* ui)
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

	rerollIntoCritsIfNotKillingCheckBox = ui->rerollIntoCritsIfNotKillingCheckBox;
	rerollIntoCritsIfNotKillingLabel = ui->rerollIntoCritsIfNotKillingLabel;

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

int attacker_widget::getAttacks() const { return attacksSpinBox->value(); }
int attacker_widget::getWeaponScore() const { return weaponScoreSpinBox->value(); }
int attacker_widget::getNormalDamage() const { return normalDamageSpinBox->value(); }
int attacker_widget::getCriticalDamage() const { return criticalDamageSpinBox->value(); }
int attacker_widget::getAccurate() const { return accurateSpinBox->value(); }
bool attacker_widget::isBalanced() const { return balancedCheckBox->isChecked(); }
bool attacker_widget::isCeaseless() const { return ceaselessCheckBox->isChecked(); }
int attacker_widget::getDevastating() const { return devastatingSpinBox->value(); }
bool attacker_widget::isLethality() const { return lethalityCheckBox->isChecked(); }
int attacker_widget::getLethalityValue() const { return lethalitySpinBox->value(); }
int attacker_widget::getPiercing() const { return piercingSpinBox->value(); }
bool attacker_widget::isPunishing() const { return punishingCheckBox->isChecked(); }
bool attacker_widget::isRelentless() const { return relentlessCheckBox->isChecked(); }
bool attacker_widget::isRending() const { return rendingCheckBox->isChecked(); }
bool attacker_widget::isSevere() const { return severeCheckBox->isChecked(); }
int attacker_widget::getFactionRerolls() const { return factionRerollsSpinBox->value(); }
bool attacker_widget::shouldRerollIntoCritsIfNotKilling() const { return rerollIntoCritsIfNotKillingCheckBox->isChecked(); }

void attacker_widget::setAttacks(int value) { attacksSpinBox->setValue(value); }
void attacker_widget::setWeaponScore(int value) { weaponScoreSpinBox->setValue(value); }
void attacker_widget::setNormalDamage(int value) { normalDamageSpinBox->setValue(value); }
void attacker_widget::setCriticalDamage(int value) { criticalDamageSpinBox->setValue(value); }
void attacker_widget::setAccurate(int value) { accurateSpinBox->setValue(value); }
void attacker_widget::setBalanced(bool value) { balancedCheckBox->setChecked(value); }
void attacker_widget::setCeaseless(bool value) { ceaselessCheckBox->setChecked(value); }
void attacker_widget::setDevastating(int value) { devastatingSpinBox->setValue(value); }
void attacker_widget::setLethality(bool value) { lethalityCheckBox->setChecked(value); }
void attacker_widget::setLethalityValue(int value) { lethalitySpinBox->setValue(value); }
void attacker_widget::setPiercing(int value) { piercingSpinBox->setValue(value); }
void attacker_widget::setPunishing(bool value) { punishingCheckBox->setChecked(value); }
void attacker_widget::setRelentless(bool value) { relentlessCheckBox->setChecked(value); }
void attacker_widget::setRending(bool value) { rendingCheckBox->setChecked(value); }
void attacker_widget::setSevere(bool value) { severeCheckBox->setChecked(value); }
void attacker_widget::setFactionRerolls(int value) { factionRerollsSpinBox->setValue(value); }
void attacker_widget::setRerollIntoCritsIfNotKilling(bool value) { rerollIntoCritsIfNotKillingCheckBox->setChecked(value); }

void attacker_widget::reset()
{
    setAttacks(3);
    setWeaponScore(3);
    setNormalDamage(3);
    setCriticalDamage(4);
    setAccurate(0);
    setBalanced(false);
    setCeaseless(false);
    setDevastating(0);
    setLethality(false);
    setLethalityValue(5);
    setPiercing(0);
    setPunishing(false);
    setRelentless(false);
    setRending(false);
    setSevere(false);
    setFactionRerolls(0);
    setRerollIntoCritsIfNotKilling(false);
}
