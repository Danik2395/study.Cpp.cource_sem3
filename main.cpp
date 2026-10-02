#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include "boat_calc_widget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QFile file(":/styles/ui/boat_calc.qss");
    if (file.open(QFile::ReadOnly))
    {
        QFontDatabase::addApplicationFont(":/fonts/ui/Nunito-VariableFont_wght.ttf");
        QString styleSheet = QLatin1String(file.readAll());
        qApp->setStyleSheet(styleSheet);
    }

    Boat_Calc_Widget window;
    window.show();
    return app.exec();
}
