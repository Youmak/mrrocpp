
#ifndef WGTABSOLUTEBASE_H_
#define WGTABSOLUTEBASE_H_

#include "wgt_base.h"
#include <QGridLayout>
#include <QPushButton>
#include <iostream>

class WgtAbsoluteBase: public wgt_base
{
Q_OBJECT

public:
	WgtAbsoluteBase(QString _widget_label, mrrocpp::ui::common::Interface& _interface, mrrocpp::ui::common::UiRobot *robo, QWidget *parent = 0);
	~WgtAbsoluteBase();

	//void synchro_depended_init();
	//void init_and_copy();

protected:
	QVector <QDoubleSpinBox*> current_pos_spin_boxes;
	QDoubleSpinBox *step_spinbox;
    QPushButton *read_button;
    QPushButton *execute_button;
    QPushButton *import_button;
    QPushButton *export_button;
    QPushButton *copy_button;

	void create_buttons_and_spin_boxes();
	int synchro_depended_widgets_disable(bool set_disabled);
	void setup_ui(QGridLayout *layout);
	virtual void add_current_position_spin_box(QDoubleSpinBox *spin_box, int row);

private:
	void create_buttons();
	void create_step_spinbox();
	int copy();
	virtual int move_it(){return 0;}
	virtual int init(){return 0;}

	const static int desired_pos_column=6;
	const static int inc_move_column=10;

public slots:
	virtual void inc_move_left_button_clicked(int button);
	virtual void inc_move_right_button_clicked(int button);
	void read_button_clicked();
	void export_button_clicked();
	void import_button_clicked();
	void copy_button_clicked();
	void execute_button_clicked();
	void init_and_copy_slot();
};

#endif /* WGTABSOLUTEBASE_H_ */
