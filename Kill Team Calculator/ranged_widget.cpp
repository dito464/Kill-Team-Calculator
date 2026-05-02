#include "ranged_widget.h"
#include "attacker_widget.h"
#include "defender_widget.h"
#include "ranged_output_widget.h"
#include "ranged_calculations.h"
#include "ui_KillTeamCalculator.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QPushButton>
#include <format>

ranged_widget::ranged_widget(QWidget *parent)
    : QWidget(parent)
{
}

void ranged_widget::setupUI(Ui_KillTeamCalculatorClass* ui)
{
	attackerWidget = ui->attackerWidget;
	attackerWidget->setupUI(ui);
	defenderWidget = ui->defenderWidget;
	defenderWidget->setupUI(ui);
    outputWidget = ui->outputWidget;
	outputWidget->setupUI(ui);
}

void ranged_widget::ConnectButtons() const
{
	connect(outputWidget->getCalculateButton(), &QPushButton::clicked, this, &ranged_widget::CalculateAndDisplaySimulationResults);
	connect(outputWidget->getResetButton(), &QPushButton::clicked, this, &ranged_widget::reset);
}

void ranged_widget::CalculateAndDisplaySimulationResults() const
{
	ranged_config cf{};

	cf.attacker.attacks = attackerWidget->getAttacks();
	cf.attacker.ws = attackerWidget->getWeaponScore();
	cf.attacker.normal_dmg = attackerWidget->getNormalDamage();
	cf.attacker.crit_dmg = attackerWidget->getCriticalDamage();
	cf.attacker.faction_rerolls = attackerWidget->getFactionRerolls();
	cf.attacker.rerolling_agressively = attackerWidget->shouldRerollIntoCritsIfNotKilling();
	cf.attacker.accurate = attackerWidget->getAccurate();
	cf.attacker.balanced = attackerWidget->isBalanced();
	cf.attacker.ceaseless = attackerWidget->isCeaseless();
	cf.attacker.devestating = attackerWidget->getDevastating();
	cf.attacker.is_lethal = attackerWidget->isLethality();
	cf.attacker.lethality = attackerWidget->getLethalityValue();
	cf.attacker.piercing = attackerWidget->getPiercing();
	cf.attacker.punishing = attackerWidget->isPunishing();
	cf.attacker.relentless = attackerWidget->isRelentless();
	cf.attacker.rending = attackerWidget->isRending();
	cf.attacker.severe = attackerWidget->isSevere();

	cf.defender.wounds = defenderWidget->getWounds();
	cf.defender.save = defenderWidget->getSave();
	cf.defender.cover = defenderWidget->hasCover();
	cf.defender.obscured = defenderWidget->isObscured();
	cf.defender.faction_reroll = defenderWidget->getFactionRerolls();
	cf.defender.rerolling_aggressively = defenderWidget->isRerollAggressively();

	auto result = ranged_calculations::calculateKillChance(cf);
	outputWidget->setKillPercent(QString::fromStdString(std::format("{} {:.2f}", ranged_output_widget::KILL_CHANCE_TEXT, 100 * result.killChance)));
	outputWidget->setAverageWounds(QString::fromStdString(std::format("{} {:.2f}", ranged_output_widget::AVERAGE_WOUNDS_TEXT, result.averageWounds)));
}

void ranged_widget::reset()
{
	attackerWidget->reset();
	defenderWidget->reset();
	outputWidget->reset();
}

attacker_widget* ranged_widget::getAttackerWidget() const
{
    return attackerWidget;
}

defender_widget* ranged_widget::getDefenderWidget() const
{
    return defenderWidget;
}

ranged_output_widget* ranged_widget::getOutputWidget() const
{
    return outputWidget;
}
