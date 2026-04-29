#include "KillTeamCalculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    KillTeamCalculator window;
    window.show();
    return app.exec();
}
