/*#include "KillTeamCalculator.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStatusBar>
#include <QtCore/QSize>

KillTeamCalculator::KillTeamCalculator(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("KillTeamCalculator");


    rangedWidget = new RangedWidget(this);
    setCentralWidget(rangedWidget);
}

KillTeamCalculator::~KillTeamCalculator()
{}

*/

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