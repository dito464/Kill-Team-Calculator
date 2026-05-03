#include "KillTeamCalculator.h"
#include <QtWidgets/QApplication>
#include <omp.h>


int main(int argc, char *argv[])
{
    omp_set_num_threads(std::max(1, omp_get_max_threads() / 2));
    QApplication app(argc, argv);
    kill_team_calculator window;
    window.show();
    return app.exec();
}
