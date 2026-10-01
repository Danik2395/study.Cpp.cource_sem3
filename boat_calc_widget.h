#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QDoubleValidator>
#include <qpushbutton.h>
#include "ui/ui_boat_calc_widget.h"
#include "boat_calc.h"

namespace Ui { class Boat_Calc_ui; }

namespace Calc_Widget_detail
{
class Boat_Edit_Validator : public QDoubleValidator
{
    Q_OBJECT

    public:
        using QDoubleValidator::QDoubleValidator;

        State validate(QString &input, int &pos) const override
        {
            if (input.isEmpty()) {
                return QValidator::Acceptable;
            }
            return QDoubleValidator::validate(input, pos);
        }
};
}

class Boat_Calc_Widget : public QWidget
{
    Q_OBJECT

    public:
        explicit Boat_Calc_Widget(QWidget* parent = nullptr) : QWidget(parent), ui(nullptr)
    {
        ui = new Ui::Boat_Calc_ui;
        ui->setupUi(this);


        auto boat_speed_edit_validator = new Calc_Widget_detail::Boat_Edit_Validator(-9999.9, 9999.9, 5, this);
        boat_speed_edit_validator->setNotation(QDoubleValidator::StandardNotation); // Not 1e5 format

        auto moveaway_time_edit_validator = new Calc_Widget_detail::Boat_Edit_Validator(0.0, 9999.9, 5, this);
        moveaway_time_edit_validator->setNotation(QDoubleValidator::StandardNotation);

        QLocale boat_data_edit_locale = QLocale::c();
        boat_data_edit_locale.setNumberOptions(QLocale::RejectGroupSeparator); // Reject 1,000,000 format
        boat_speed_edit_validator->setLocale(boat_data_edit_locale);
        moveaway_time_edit_validator->setLocale(boat_data_edit_locale);

        ui->edit_first_bs->setValidator(boat_speed_edit_validator);
        ui->edit_second_bs->setValidator(boat_speed_edit_validator);
        ui->edit_time->setValidator(moveaway_time_edit_validator);

        ui->label_moveaway_speed->setProperty("boat_label_property" ,ui->label_moveaway_speed->text() + " %1");
        ui->label_moveaway_distance->setProperty("boat_label_property" ,ui->label_moveaway_distance->text() + " %1");

        connect(
                ui->edit_first_bs,
                &QLineEdit::editingFinished,
                this,
                [this](){
                set_boat_speed(Boat_Calc::FIRST);
                update_labels();
                }
                );

        connect(
                ui->edit_second_bs,
                &QLineEdit::editingFinished,
                this,
                [this](){
                set_boat_speed(Boat_Calc::SECOND);
                update_labels();
                }
                );

        connect(
                ui->edit_time,
                &QLineEdit::editingFinished,
                this,
                [this](){
                set_time();
                update_labels();
                }
                );
    }

    ~Boat_Calc_Widget() { delete ui; };

private:
    Ui::Boat_Calc_ui* ui;
    Boat_Calc boat_calc;

    void set_boat_speed(Boat_Calc::Boat_Num num)
    {
        QLineEdit* target_edit;

        switch (num)
        {
            case Boat_Calc::FIRST:  target_edit = ui->edit_first_bs;  break;
            case Boat_Calc::SECOND: target_edit = ui->edit_second_bs; break;
            default: return;
        }

        if (target_edit->text().isEmpty())
        {
            boat_calc.set_boat_speed(num, 0);
            return;
        }

        bool ok_double = false;
        double boat_speed = target_edit->text().toDouble(&ok_double);
        if (ok_double)
        {
            boat_calc.set_boat_speed(num, boat_speed);
        }
    }

    void set_time()
    {
        if (ui->edit_time->text().isEmpty())
        {
            boat_calc.set_time_hours(0.0);
            return;
        }
        bool ok_double = false;
        double boat_time = ui->edit_time->text().toDouble(&ok_double);
        if (ok_double)
        {
            boat_calc.set_time_hours(boat_time);
        }
    }

    void update_labels()
    {
        auto speed_to_set = QString::number(boat_calc.get_moveaway_speed());
        auto moveaway_speed_property = ui->label_moveaway_speed->property("boat_label_property");
        ui->label_moveaway_speed->setText(moveaway_speed_property.toString().arg(speed_to_set));

        auto distance_to_set = QString::number(boat_calc.get_moveaway_distance());
        auto moveaway_distance_property = ui->label_moveaway_distance->property("boat_label_property");
        ui->label_moveaway_distance->setText(moveaway_distance_property.toString().arg(distance_to_set));
    }
};
