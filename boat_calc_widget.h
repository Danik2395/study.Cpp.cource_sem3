#pragma once
#include <QWidget>
#include "ui/ui_boat_calc_widget.h"

namespace Ui { class Boat_Calc_ui; }

class Boat_Calc_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Boat_Calc_Widget(QWidget* parent = nullptr) : QWidget(parent), ui(nullptr)
    {
        ui = new Ui::Boat_Calc_ui;
        ui->setupUi(this);
    }

    ~Boat_Calc_Widget() { delete ui; };

private:
    Ui::Boat_Calc_ui* ui;
};
