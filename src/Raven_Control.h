#ifndef RAVEN_CONTROL_H_
#define RAVEN_CONTROL_H_

#include "/usr/include/dhdc.h"				//AMIT
#include "/usr/include/drdc.h"				//AMIT
#include "Robot_State.h"
#include "ati_fsensor/ati_data.h"

// RUN LEVELS
#define RL_E_STOP 0
#define RL_INIT 1
#define RL_PEDAL_UP 2
#define RL_PEDAL_DN 3

#define SL_PD_CTRL 0
#define SL_DAC_CTRL 1
#define SL_AUTO_INIT 3

class Raven_Control
{
	private:
		int RADIUS;
		int SPEED;
		int SCALE = 5;
		int DIRECTION;
		int BASE_PLANE;
		int PUB_COUNT;
		int SUB_COUNT;
		bool SHOW_STATUS;
		bool RECEIVED_FIRST;
		bool PAUSE;
		bool update_surgeon_mode = false;
		bool HAPTIC_FEEDBACK = false;
		bool GRIP_FORCE_FEEDBACK = false;
		bool TRANS_FORCE_FEEDBACK = false;
		pthread_t console_thread;
		pthread_t ros_thread;

		ros::Publisher raven_publisher;
		ros::Publisher haptic_publisher;

		ros::Publisher raven_publisher_tester;

		ros::Subscriber raven_subscriber;
		ros::Subscriber haptic_subscriber;
		ros::Subscriber ati_subscriber;
		raven_state CURR_RAVEN_STATE;
		haptic_device CURR_HAPTIC_STATE;
		haptic_commands CURR_HAPTIC_COMMANDS;
		ati_fsensor::ati_data CURR_FORCE_SENSOR;
		tf::Transform TF_INCR[2];
		tfScalar GRASP_INCR[2];
		force_feedback FORCES[2];
		haptic_locks LOCKS;
		
		bool LEFT_ARM_STATUS;
		Robot_State LEFT_ARM_RAVEN;
		bool RIGHT_ARM_STATUS;
		Robot_State RIGHT_ARM_RAVEN;

		Robot_State LEFT_ARM_HAPTIC;
		Robot_State RIGHT_ARM_HAPTIC;

		pthread_t gravity_thread;
		pthread_t haptic_thread;

		int current_surgeon_mode = 0;


	public:
		Raven_Control();		// constructor
		void initial(int, char**);	// initialization and console display
		void init_sys();
		bool init_ros(int, char**);
		void init_pathplanner();
		void init_words();
		bool menu_words(bool);
		void final_words();

		void start_thread();		// thread management
		void join_thread();
		void *console_process(void);
		void *ros_process(void);
		static void *static_console_process(void*);
		static void *static_ros_process(void*);

		void publish_raven_automove();			 // ROS publish

		void publish_haptic_commands();
		void callback_raven_state(raven_state); // ROS subscribe
		void callback_haptic_state(haptic_device); // ROS subscribe
		void callback_ati_data(ati_fsensor::ati_data); // ROS subscribe

		void output_STATUS();		// show ROS and raven state
		void output_PATHinfo();
		void output_PUBinfo();
		void output_SUBinfo();


		int getKey();

		void init_haptic();			//AMIT
		void *gravity_process(void); 	//AMIT
		void *haptic_process(void); 	//AMIT
		static void *static_haptic_process(void*);
		static void *static_gravity_process(void*);
		void publish_haptic_device(double px, double py, double pz, double gripper);
		void publish_raven_control();
		float* computeOrientationMatch();
}; //end of class definition

#endif
