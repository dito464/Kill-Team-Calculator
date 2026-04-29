#include "defender_widget.h"
#include "ui_KillTeamCalculator.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtCore/QSize>

defender_widget::defender_widget(QWidget *parent)
    : QGroupBox("Defender", parent)
{
}
void defender_widget::setupUI(Ui_KillTeamCalculatorClass* ui)
{
	woundsSpinBox = ui->woundsSpinBox;
	woundsLabel = ui->woundsLabel;

	saveSpinBox = ui->saveSpinBox;
	saveLabel = ui->saveLabel;

	coverCheckBox = ui->coverCheckBox;
	coverLabel = ui->coverLabel;

	obscuredCheckBox = ui->obscuredCheckBox;
	obscuredLabel = ui->obscuredLabel;

	factionDefRerollsSpinBox = ui->factionDefRerollsSpinBox;
	factionDefRerollsLabel = ui->factionDefRerollsLabel;

	rerollIntoCritsIfAnyCheckBox = ui->rerollIntoCritsIfAnyCheckBox;
	rerollIntoCritsIfAnyLabel = ui->rerollIntoCritsIfAnyLabel;
}

int defender_widget::getWounds() const { return woundsSpinBox->value(); }
int defender_widget::getSave() const { return saveSpinBox->value(); }
bool defender_widget::hasCover() const { return coverCheckBox->isChecked(); }
bool defender_widget::isObscured() const { return obscuredCheckBox->isChecked(); }
int defender_widget::getFactionRerolls() const { return factionDefRerollsSpinBox->value(); }
bool defender_widget::isRerollAggressively() const { return rerollIntoCritsIfAnyCheckBox->isChecked(); }

void defender_widget::setWounds(int value) { woundsSpinBox->setValue(value); }
void defender_widget::setSave(int value) { saveSpinBox->setValue(value); }
void defender_widget::setCover(bool value) { coverCheckBox->setChecked(value); }
void defender_widget::setObscured(bool value) { obscuredCheckBox->setChecked(value); }
void defender_widget::setFactionRerolls(int value) { factionDefRerollsSpinBox->setValue(value); }
void defender_widget::setRerollAggressively(bool value) { rerollIntoCritsIfAnyCheckBox->setChecked(value); }

void defender_widget::reset()
{
    setWounds(8);
    setSave(3);
    setCover(false);
    setObscured(false);
    setFactionRerolls(0);
	setRerollAggressively(false);
}
