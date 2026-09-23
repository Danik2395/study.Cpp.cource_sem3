#include <QApplication>
#include "boat_calc_widget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Boat_Calc_Widget window;
    window.show();
    return app.exec();
}
