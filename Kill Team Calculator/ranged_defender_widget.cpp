#include "ranged_defender_widget.h"
#include "ui_KillTeamCalculator.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtCore/QSize>

ranged_defender_widget::ranged_defender_widget(QWidget *parent)
    : QGroupBox("Defender", parent)
{
}
void ranged_defender_widget::setup_ui(Ui_KillTeamCalculatorClass* ui)
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

int ranged_defender_widget::get_wounds() const { return woundsSpinBox->value(); }
int ranged_defender_widget::get_save() const { return saveSpinBox->value(); }
bool ranged_defender_widget::has_cover() const { return coverCheckBox->isChecked(); }
bool ranged_defender_widget::is_obscured() const { return obscuredCheckBox->isChecked(); }
int ranged_defender_widget::get_faction_rerolls() const { return factionDefRerollsSpinBox->value(); }
bool ranged_defender_widget::is_reroll_aggressively() const { return rerollIntoCritsIfAnyCheckBox->isChecked(); }

void ranged_defender_widget::set_wounds(int value) { woundsSpinBox->setValue(value); }
void ranged_defender_widget::set_save(int value) { saveSpinBox->setValue(value); }
void ranged_defender_widget::set_cover(bool value) { coverCheckBox->setChecked(value); }
void ranged_defender_widget::set_obscured(bool value) { obscuredCheckBox->setChecked(value); }
void ranged_defender_widget::set_faction_rerolls(int value) { factionDefRerollsSpinBox->setValue(value); }
void ranged_defender_widget::set_reroll_aggressively(bool value) { rerollIntoCritsIfAnyCheckBox->setChecked(value); }

void ranged_defender_widget::reset()
{
    set_wounds(8);
    set_save(3);
    set_cover(false);
    set_obscured(false);
    set_faction_rerolls(0);
	set_reroll_aggressively(false);
}
