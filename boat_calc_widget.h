#pragma once
#include <QWidget>

namespace Ui { class Boat_Calc_ui; }

class Boat_Calc_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Boat_Calc_Widget(QWidget* parent = nullptr) : QWidget(parent), ui(nullptr)
    {

    }

    ~Boat_Calc_Widget() { delete ui; };

private:
    Ui::Boat_Calc_ui* ui;
};
