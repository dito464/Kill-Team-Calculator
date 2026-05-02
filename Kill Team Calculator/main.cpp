#include "KillTeamCalculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    kill_team_calculator window;
    window.show();
    return app.exec();
}
