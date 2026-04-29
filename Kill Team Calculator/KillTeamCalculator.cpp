#include "KillTeamCalculator.h"

KillTeamCalculator::KillTeamCalculator(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	ui.rangedWidget->setupUI(&ui);
    ui.rangedWidget->ConnectButtons();
}

KillTeamCalculator::~KillTeamCalculator()
{
}