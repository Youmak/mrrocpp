#include "base/mp/mp_task.h"
#include "mp_t_swarm_demo.h"

#include "base/lib/mrmath/mrmath.h"

#include "robot/irp6_tfg/dp_tfg.h"
#include "robot/irp6ot_tfg/const_irp6ot_tfg.h"
#include "robot/irp6p_tfg/const_irp6p_tfg.h"
#include "robot/irp6ot_m/const_irp6ot_m.h"
#include "robot/irp6p_m/const_irp6p_m.h"

#include "base/lib/typedefs.h"
#include "base/lib/impconst.h"
#include "base/lib/com_buf.h"
#include <iostream>
#include <string>
#include <sstream>
#include "base/lib/sr/srlib.h"

#include "ecp_mp_t_swarm_demo.h"
#include "application/swarm_demo/ecp_mp_st_smooth_joint.h"


#include "robot/irp6ot_m/mp_r_irp6ot_m.h"
#include "robot/irp6p_m/mp_r_irp6p_m.h"

namespace mrrocpp {
namespace mp {
namespace task {

task* return_created_mp_task(lib::configurator &_config)
{
	return new swarm_demo(_config);
}

// powolanie robotow w zaleznosci od zawartosci pliku konfiguracyjnego
void swarm_demo::create_robots()
{
	ACTIVATE_MP_ROBOT(irp6ot_m);
	ACTIVATE_MP_ROBOT(irp6p_m);
}

swarm_demo::swarm_demo(lib::configurator &_config) :
	task(_config)
{
}

void swarm_demo::main_task_algorithm(void)
{

	sr_ecp_msg->message("Swarm Demo (MP) START");

	lib::robot_name_t manipulator_name;
	lib::robot_name_t gripper_name;

	// Track

	/*if (config.value <int> ("is_irp6ot_m_active", lib::UI_SECTION)) {
		//------------------- SMOOTH GENERATOR -------------------
		set_next_ecps_state(ecp_mp::sub_task::ECP_ST_SMOOTH_GEN_TEST, (int) 5, "", 0, 1, lib::irp6ot_m::ROBOT_NAME.c_str());

		run_extended_empty_gen_and_wait(1, 1, lib::irp6ot_m::ROBOT_NAME.c_str(), lib::irp6ot_m::ROBOT_NAME.c_str());
		//------------------- SMOOTH GENERATOR END -------------------
	}

	// Postument

	if (config.value <int> ("is_irp6p_m_active", lib::UI_SECTION)) {
		//------------------- SMOOTH GENERATOR -------------------
		set_next_ecps_state(ecp_mp::sub_task::ECP_ST_SMOOTH_JOINT, (int) 5, "", 0, 1, lib::irp6p_m::ROBOT_NAME.c_str());

		run_extended_empty_gen_and_wait(1, 1, lib::irp6p_m::ROBOT_NAME.c_str(), lib::irp6p_m::ROBOT_NAME.c_str());
		//------------------- SMOOTH GENERATOR END -------------------
	}*/

	sr_ecp_msg->message("Swarm Demo END");

}

} // namespace task
} // namespace mp
} // namespace mrrocpp
