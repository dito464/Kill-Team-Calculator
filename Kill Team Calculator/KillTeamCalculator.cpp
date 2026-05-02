#include "KillTeamCalculator.h"

kill_team_calculator::kill_team_calculator(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	ui.rangedWidget->setup_ui(&ui);
    ui.rangedWidget->connect_buttons();
}

kill_team_calculator::~kill_team_calculator()
{
}