#include "ranged_widget.h"
#include "ranged_attacker_widget.h"
#include "ranged_defender_widget.h"
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

void ranged_widget::setup_ui(Ui_KillTeamCalculatorClass* ui)
{
	attackerWidget = ui->attackerWidget;
	attackerWidget->setup_ui(ui);
	defenderWidget = ui->defenderWidget;
	defenderWidget->setup_ui(ui);
    outputWidget = ui->outputWidget;
	outputWidget->setup_ui(ui);
}

void ranged_widget::connect_buttons() const
{
	connect(outputWidget->get_calculate_button(), &QPushButton::clicked, this, &ranged_widget::calculate_and_display_simulation_results);
	connect(outputWidget->get_reset_button(), &QPushButton::clicked, this, &ranged_widget::reset);
}

void ranged_widget::calculate_and_display_simulation_results() const
{
	ranged_config cf{};

	cf.attacker.attacks = attackerWidget->get_attacks();
	cf.attacker.ws = attackerWidget->get_weapon_score();
	cf.attacker.normal_dmg = attackerWidget->get_normal_damage();
	cf.attacker.crit_dmg = attackerWidget->get_critical_damage();
	cf.attacker.faction_rerolls = attackerWidget->get_faction_rerolls();
	cf.attacker.rerolling_agressively = attackerWidget->should_reroll_into_crits_if_not_killing();
	cf.attacker.accurate = attackerWidget->get_accurate();
	cf.attacker.balanced = attackerWidget->is_balanced();
	cf.attacker.ceaseless = attackerWidget->is_ceaseless();
	cf.attacker.devestating = attackerWidget->get_devastating();
	cf.attacker.is_lethal = attackerWidget->is_lethality();
	cf.attacker.lethality = attackerWidget->get_lethality_value();
	cf.attacker.piercing = attackerWidget->get_piercing();
	cf.attacker.punishing = attackerWidget->is_punishing();
	cf.attacker.relentless = attackerWidget->is_relentless();
	cf.attacker.rending = attackerWidget->is_rending();
	cf.attacker.severe = attackerWidget->is_severe();

	cf.defender.wounds = defenderWidget->get_wounds();
	cf.defender.save = defenderWidget->get_save();
	cf.defender.cover = defenderWidget->has_cover();
	cf.defender.obscured = defenderWidget->is_obscured();
	cf.defender.faction_reroll = defenderWidget->get_faction_rerolls();
	cf.defender.rerolling_aggressively = defenderWidget->is_reroll_aggressively();

	auto result = ranged_calculations::calculate_kill_chance(cf);
	outputWidget->set_kill_percent(QString::fromStdString(std::format("{} {:.2f}", ranged_output_widget::KILL_CHANCE_TEXT, 100 * result.kill_chance)));
	outputWidget->set_average_wounds(QString::fromStdString(std::format("{} {:.2f}", ranged_output_widget::AVERAGE_WOUNDS_TEXT, result.average_wounds)));
}

void ranged_widget::reset()
{
	attackerWidget->reset();
	defenderWidget->reset();
	outputWidget->reset();
}

ranged_attacker_widget* ranged_widget::get_attacker_widget() const
{
    return attackerWidget;
}

ranged_defender_widget* ranged_widget::get_defender_widget() const
{
    return defenderWidget;
}

ranged_output_widget* ranged_widget::get_output_widget() const
{
    return outputWidget;
}
