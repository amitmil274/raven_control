#ifndef ROBOT_STATE_H_
#define ROBOT_STATE_H_

#include <string>
#include <vector>
#include <map>
#include <ostream>
#include <tf/transform_datatypes.h>
#include <stdio.h>
#include <iomanip>
#include <ros/ros.h>
#include <ros/ros.h>
#include <ros/transport_hints.h>
#include <sstream>
#include <pthread.h>
#include <termios.h>
#include <queue>
#include "raven_control/raven_automove.h"
#include "raven_state.h"
#include "sigma_ros/haptic_device.h"
#include "sigma_ros/haptic_commands.h"

//#include "raven_2/haptic_device.h"

#define LEFT_ARM 0
#define RIGHT_ARM 1

#define RAVEN 0
#define HAPTIC 1

#define MAX_RADIUS 6   // 6 different radius levels
#define MAX_SPEED 60   // 60 different speed levels
#define MIN_RADIUS 1
#define MIN_SPEED 1
#define SMALL_RADIUS 2
#define SMALL_RADIUS_MAX_SPEED 50
#define VERTICLE_CIRCLE_MAX_SPEED 40
#define CHANGE_BASEPLANE_MAX_SPEED 10

#define RADIUS_level_TO_microm 3000  //in micro meter (= 3mm = 0.3cm)

#define DEL_POS_THRESHOLD 180	// in micro meter (= 0.18mm = 0.018cm)
#define STATE_THRESHOLD 300
#define DEL_ROT_THRESHOLD 0.25 	// in degrees
#define ROS_PUBLISH_RATE 1000 	// in Hz

#define YZ_PLANE 0    // circluate around X axis
#define XZ_PLANE 1    // circluate around Y axis
#define XY_PLANE 2    // circluate around Z axis

// [DANGER]: for modification parameter tuning only
#define DEFAULT_MODIFICATION_SCALE  	  	0.000001
#define DEFAULT_MODIFICATION_SPEED_POWER  	0.7
#define DEFAULT_MODIFICATION_DISTANCE_POWER  	1

using namespace raven_2;
using namespace std;
using namespace sigma_ros;
using namespace raven_control;

#define KP    100.0
#define KVP    10.0
#define MAXF    4.0
#define KR      0.1
#define KWR     0.02
#define MAXT    0.1
#define KG    100.0
#define KVG     5.0
#define MAXG    1.0

struct force_feedback
{
tf::Vector3 force_trans;
tf::Vector3 force_torque;
tfScalar force_grip;
};
struct haptic_locks
{
	bool lock_position;
	bool lock_orientation;
	bool lock_grasp;
};

enum PATH_STATE{
	AROUND_CIRCLE,	// go along circle trajectory
	MOVETO_CIRCLE	// move to the new circle (when radius or center change)
};


class Robot_State
{
	private:
		tfScalar Modi_Scale;
		tfScalar Modi_Speed_Pow;
		tfScalar Modi_Dista_Pow;
		
		tf::Vector3 X_AXIS;
		tf::Vector3 Y_AXIS;
		tf::Vector3 Z_AXIS;

		// POSITION
		tf::Vector3 Current_Pos;	// current raven position
		tf::Vector3 Previous_Pos;	// current raven position
		tf::Vector3 Delta_Pos;
		tf::Vector3 Center;		// the center of the circle
		tf::Vector3 Velocity_Pos;

		// ORIENTATION
		tf::Quaternion Current_Ori;	// current raven rotation quaternion
		tf::Matrix3x3 Current_Ori_mat; // current orientation matrix
		tf::Quaternion Previous_Ori;	// previous raven rotation quaternion
		tf::Matrix3x3 Previous_Ori_mat; // previous orientation matrix
		tf::Vector3 Velocity_Orientation;

		// FORCE FEEDBACKS
		force_feedback forces;

		// GRASP
		tfScalar Current_Grasp;	// current raven rotation
		tfScalar Previous_Grasp;	// current raven rotation
		tfScalar Delta_Grasp;
		tfScalar CenterGrasp;
		tfScalar Velocity_Grasp;

		tfScalar Radius;		// in mm
		tfScalar Speed;
		tfScalar Scale = 0.5;
		tfScalar GraspScale = 5;
		tfScalar Distance;		// the distance between current pos and center
		tfScalar Error;			// the difference between radius and distance
		PATH_STATE PathState;
	
		pthread_mutexattr_t data1MutexAttr;
		pthread_mutex_t data1Mutex;

		pthread_mutexattr_t data2MutexAttr;
		pthread_mutex_t data2Mutex;

		int Direction;
		int Base_Plane;
		int ArmType;
		int DeviceType;
		bool FIRST_SEND;
		bool DISABLED;
		tfScalar last_y,last_z;
		tfScalar K;
		tfScalar Kp;
		tfScalar sign(tfScalar);
		void checkPathState();
		void AutoCircleMotion1();		// algorithm 1 : kind of unstable
		void AutoCircleMotion2();		// algorithm 2 : better!
		void AutoCircleMotion3();		// algorithm 3 : even better! 
		tf::Vector3 AutoCircleMotion4();	// algorithm 4 : the best so far! (in use!!)	
		tf::Vector3 TuneRadiusMotion();

	public:
		Robot_State();
		bool set_Radius(int);
		bool set_Speed(int);
		bool set_Scale(int);
		void set_Disabled(bool);
		bool get_Disabled();

		bool set_Direction(int);
		bool set_BasePlane(int);
		bool set_ArmType(int);
		bool set_DeviceType(int);

		bool set_Center(boost::array<int, 6>, boost::array<float, 2>);
		bool set_Center(boost::array<float, 6>, boost::array<float, 2>);

		bool set_Current_Pos(boost::array<int, 6>);
		bool set_Current_Pos(boost::array<float, 6>,boost::array<float, 6>);
		bool set_Current_Grasp(boost::array<float, 2>,boost::array<float, 2>);

		bool set_Current_Ori(boost::array<float, 18>);
		bool set_Current_Ori(boost::array<float, 18>,boost::array<float, 6>);
		tfScalar get_Radius();
		tfScalar get_Radius_Range();
		tfScalar get_Speed();
		tfScalar get_Scale();
		tfScalar get_K();
		tfScalar get_Current_grasp();
		void show_PathState();
		void show_Distance();
		void show_Center();
		void show_delPos();
/*
		// [DANGER]: for modification parameter tuning only
		bool set_Modi_Scale(int);
		bool set_Modi_Speed_Pow(int);
		bool set_Modi_Dista_Pow(int);
		tfScalar get_Modi_Scale();
		tfScalar get_Modi_Speed_Pow();
		tfScalar get_Modi_Dista_Pow();
*/

		tfScalar DistanceOf(tf::Vector3,tf::Vector3);
		tf::Transform ComputeCircleTrajectory();
		tf::Transform ComputeTeleoperation(Robot_State);
		force_feedback ComputeForces(Robot_State, haptic_locks);
		tf::Transform ComputeNullTrajectory();
		tfScalar ComputeGrasp(Robot_State);
};
#endif
