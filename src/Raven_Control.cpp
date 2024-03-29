#include "Raven_Control.h"



Raven_Control::Raven_Control()
{

}




void Raven_Control::initial(int argc, char** argv)
{
	init_sys();
	if(!init_ros(argc,argv))
	{
		ROS_ERROR("Fail to initialize ROS. Exiting!");
		exit(1);
	}

	init_pathplanner();
	//print the welcome greets on console
	init_words();
	//init_haptic();
}


void Raven_Control::init_pathplanner()
{
	if(!LEFT_ARM_RAVEN.set_ArmType(LEFT_ARM) || !RIGHT_ARM_RAVEN.set_ArmType(RIGHT_ARM))
	{
		ROS_ERROR("Fail to set RAVEN arm type. Exiting!");
		exit(1);
	}
	if(!LEFT_ARM_HAPTIC.set_ArmType(LEFT_ARM) || !RIGHT_ARM_HAPTIC.set_ArmType(RIGHT_ARM))
	{
		ROS_ERROR("Fail to set HAPTIC arm type. Exiting!");
		exit(1);
	}
	if(!LEFT_ARM_RAVEN.set_DeviceType(RAVEN) || !RIGHT_ARM_RAVEN.set_DeviceType(RAVEN))
	{
		ROS_ERROR("Fail to set RAVEN arm type. Exiting!");
		exit(1);
	}
	if(!LEFT_ARM_HAPTIC.set_DeviceType(HAPTIC) || !RIGHT_ARM_HAPTIC.set_DeviceType(HAPTIC))
	{
		ROS_ERROR("Fail to set RAVEN arm type. Exiting!");
		exit(1);
	}
}
/**
 *	\fn void init_sys()
 *
 *	\brief initialize default system parameter settings.
 *
 * 	\param void
 *
 *	\return void
 */
void Raven_Control::init_sys()  
{
	this->PUB_COUNT = 0;
	this->SUB_COUNT = 0;
	this->SPEED = 1;
	this->SCALE = 5;
	this->RECEIVED_FIRST = false;
	this->SHOW_STATUS = false;
	this->PAUSE = false;

}



/**
 *	\fn int init_ros(int argc, char** argv)
 *
 *	\brief initialize ROS and connect the pub & sub relation.
 *
 * 	\param int argc, char** argv
 *
 *	\return bool
 */
bool Raven_Control::init_ros(int argc, char** argv) 
{
	//initialize ROS
	ros::init(argc, argv, "raven_control");

	static ros::NodeHandle n;
	raven_publisher = n.advertise<raven_automove>("raven_automove", 1);
	raven_publisher_tester = n.advertise<raven_automove>("raven_tester", 1);
	haptic_publisher = n.advertise<haptic_commands>("haptic_commands", 1);
	raven_subscriber   = n.subscribe("ravenstate",1,&Raven_Control::callback_raven_state,this);
	haptic_subscriber = n.subscribe("haptic_msg",1,&Raven_Control::callback_haptic_state,this);

	//HapticDevice_publisher = n.advertise<raven_automove>("haptic_device", 1);
	return true;
}

void Raven_Control::init_words()  
{
	string start = "0";
	do
	{
		cout<<endl<<endl;
		cout<<"Welcome to the Auto Circle Generator for RAVEN2"<<endl<<endl;
		cout<<"Default settings: RADIUS = "<<RADIUS<<endl;
		cout<<"                  SPEED = "<<SPEED<<endl;
		cout<<"                  DIRECTION = "<<DIRECTION<<endl;
		cout<<"                  BASE = Y-Z plane"<<endl<<endl;
		cout<<"Please press \"Enter\" to start!";
		cin.clear();
		getline(std::cin,start);
	}while(start!="");

	cout<<"Auto Circle Generator starting..."<<endl;
}



/**
 *	\fn void menu_words()
 *
 *	\brief show menu words on console.
 *
 * 	\param void
 *
 *	\return void
 */
bool Raven_Control::menu_words(bool print_menu)  
{
	if(print_menu)
	{
		cout<<endl;
		cout<<"Auto Circle Generator Selection Menu:"<<endl;
		cout<<"----------------------------------------------------"<<endl;
		cout<<"\t'1' : Increase Circle Radius"<<endl;
		cout<<"\t'2' : Decrease Circle Radius"<<endl;
		cout<<"\t'3' : Increase Raven Moving Speed"<<endl;
		cout<<"\t'4' : Decrease Raven Moving Speed"<<endl;
		cout<<"\t'5' : Toggle circling direction"<<endl;
		cout<<"\t'6' : Toggle pause/resume "<<endl;
		cout<<"\t'7' : Toggle console messages"<<endl;
		cout<<"\t'8' : Set as Circle Center."<<endl;
		cout<<"\t'9' : Change Circle Base Plane."<<endl;
		cout<<"\t'^C': Quit"<<endl<<endl;
	}
	return false;
}



/**
 *	\fn void final_words()
 *
 *	\brief show goodbye words on console.
 *
 * 	\param void
 *
 *	\return void
 */
void Raven_Control::final_words()  
{
	cout<<"Terminating the AutoCircle_generator." <<endl;
	cout<<"----------------------------------------------------"<<endl;
	cout<<"GoodBye!"<<endl<<endl<<endl;
}




/**
 *	\fn void start_thread()
 *
 * 	\brief start the console_thread and ros_thread
 *
 * 	\param void
 *
 *	\return void
 */
void Raven_Control::start_thread()
{
	pthread_create(&console_thread,NULL,Raven_Control::static_console_process,this);
	pthread_create(&ros_thread,NULL,Raven_Control::static_ros_process,this);
}



/**
 *	\fn void join_thread()namespace raven_control
 *
 * 	\brief join the console_thread and ros_thread
 *
 * 	\param void
 *
 *	\return void
 */
void Raven_Control::join_thread()
{
	pthread_join(console_thread,NULL);
	pthread_join(ros_thread,NULL);
	final_words();
}



/**
 *	\fn void *console_process(void)
 *
 * 	\brief this thread is dedicated to console io
 *
 * 	\param a pointer to void
 *
 *	\return void
 */
void* Raven_Control::console_process(void)
{
	if(ros::isInitialized())
	{
		int theKey;
		bool print_menu = true;
		ros::Time time;
		time = time.now();

		while(ros::ok())
		{
			print_menu = menu_words(print_menu);
			theKey = getKey();

			switch(theKey)
			{

			case '3': //TODO use for SCALING
			{
				// SPEED = (SPEED+1 > MAX_SPEED) ? MAX_SPEED : SPEED+1;

				// [DANGER]: related to modification parameter tuning
				// observation from experiments
				//if(BASE_PLANE != YZ_PLANE)
				//SPEED = (SPEED > VERTICLE_CIRCLE_MAX_SPEED) ? VERTICLE_CIRCLE_MAX_SPEED : SPEED;
				//if(RADIUS < SMALL_RADIUS)
				//SPEED = (SPEED > SMALL_RADIUS_MAX_SPEED) ? SMALL_RADIUS_MAX_SPEED : SPEED;

				//LEFT_PATH.set_Speed(SPEED);
				//RIGHT_PATH.set_Speed(SPEED);

				SCALE++;
				//RIGHT_ARM_RAVEN.set_Scale(SCALE);
				//LEFT_ARM_RAVEN.set_Scale(SCALE);

				cout<<"You chose 3 : Increase Raven Moving Speed."<<endl;
				printf("new Scale = %d",RIGHT_ARM_RAVEN.get_Scale());
				print_menu = true;
				break;
			}
			case '4': //TODO use for SCALING
			{
				//					SPEED = (SPEED-1 < MIN_SPEED) ? MIN_SPEED : SPEED-1;
				//					LEFT_PATH.set_Speed(SPEED);
				//					RIGHT_PATH.set_Speed(SPEED);
				SCALE--;
				//RIGHT_ARM_RAVEN.set_Scale(SCALE);
				//LEFT_ARM_RAVEN.set_Scale(SCALE);

				cout<<"You chose 4 : Decrease Raven Moving Speed."<<endl;
				printf("new Scale = %d",RIGHT_ARM_RAVEN.get_Scale());

				print_menu = true;
				break;
			}
			case '5':
			{

				//					DIRECTION = DIRECTION*(-1);
				//					LEFT_PATH.set_Direction(DIRECTION);
				//					RIGHT_PATH.set_Direction(DIRECTION);
				//
				//					cout<<"You chose 5 : Toggle circling direction."<<endl;
				//					if(DIRECTION > 0)
				//						cout<<"\tChange to counter-clockwise circle trajectory."<<endl;
				//					else
				//						cout<<"\tChange to clockwise circle trajectory."<<endl;
				print_menu = true;
				break;
			}
			case '6':
			{
				PAUSE = !PAUSE;

				cout<<"You chose 6 : Toggle pause/resume."<<endl;
				if(PAUSE)
					cout<<"\tAutoCircling is paused."<<endl;
				else
					cout<<"\tAutoCircling is resumed."<<endl;
				print_menu = true;
				break;
			}
			case '7':
			{
				SHOW_STATUS = !SHOW_STATUS;

				cout<<"You chose 7 : Toggle console messages."<<endl;
				if(SHOW_STATUS)
					cout<<"\tConsole message turned on."<<endl;
				else
					cout<<"\tConsole message turned off."<<endl;
				print_menu = true;
				break;
			}
			case '8':
			{

				LEFT_ARM_RAVEN.set_Center(CURR_RAVEN_STATE.pos,CURR_RAVEN_STATE.grasp);
				LEFT_ARM_HAPTIC.set_Center(CURR_HAPTIC_STATE.position,CURR_HAPTIC_STATE.gripper);

				RIGHT_ARM_RAVEN.set_Center(CURR_RAVEN_STATE.pos,CURR_RAVEN_STATE.grasp);
				RIGHT_ARM_HAPTIC.set_Center(CURR_HAPTIC_STATE.position,CURR_HAPTIC_STATE.gripper);

				cout<<"You chose 8 : Set as Circle Center."<<endl;
				cout<<"\tnew Center[LEFT]: X,Y,Z = ("<<CURR_RAVEN_STATE.pos[0]<<",";
				cout<<CURR_RAVEN_STATE.pos[1]<<","<<CURR_RAVEN_STATE.pos[2]<<")"<<endl;
				cout<<"\tnew Center[RIGHT]: X,Y,Z = ("<<CURR_RAVEN_STATE.pos[3]<<",";
				cout<<CURR_RAVEN_STATE.pos[4]<<","<<CURR_RAVEN_STATE.pos[5]<<")"<<endl;

				cout<<"\tnew HAPTIC Center[LEFT]: X,Y,Z = ("<<CURR_HAPTIC_STATE.position[0]<<",";
								cout<<CURR_HAPTIC_STATE.position[1]<<","<<CURR_HAPTIC_STATE.position[2]<<")"<<endl;
								cout<<"\tnew HAPTIC Center[RIGHT]: X,Y,Z = ("<<CURR_HAPTIC_STATE.position[3]<<",";
								cout<<CURR_HAPTIC_STATE.position[4]<<","<<CURR_HAPTIC_STATE.position[5]<<")"<<endl;
				print_menu = true;
				break;
			}
			case 'z': // lock haptic position
			{
				CURR_HAPTIC_COMMANDS.lock_position = !CURR_HAPTIC_COMMANDS.lock_position;
				publish_haptic_commands();
				break;
			}
			case 'x': // lock haptic orientation
			{
				CURR_HAPTIC_COMMANDS.lock_orientation = !CURR_HAPTIC_COMMANDS.lock_orientation;
				publish_haptic_commands();
				break;
			}
			case 'c': // lock haptic grasper
			{
				CURR_HAPTIC_COMMANDS.lock_grasp = !CURR_HAPTIC_COMMANDS.lock_grasp;
				publish_haptic_commands();
				break;
			}
			case 'd': // update runlevel to start teleop + set new center
			{
				LEFT_ARM_RAVEN.set_Center(CURR_RAVEN_STATE.pos,CURR_RAVEN_STATE.grasp);
								LEFT_ARM_HAPTIC.set_Center(CURR_HAPTIC_STATE.position,CURR_HAPTIC_STATE.gripper);

								RIGHT_ARM_RAVEN.set_Center(CURR_RAVEN_STATE.pos,CURR_RAVEN_STATE.grasp);
								RIGHT_ARM_HAPTIC.set_Center(CURR_HAPTIC_STATE.position,CURR_HAPTIC_STATE.gripper);

								cout<<"You chose 8 : Set as Circle Center."<<endl;
								cout<<"\tnew Center[LEFT]: X,Y,Z = ("<<CURR_RAVEN_STATE.pos[0]<<",";
								cout<<CURR_RAVEN_STATE.pos[1]<<","<<CURR_RAVEN_STATE.pos[2]<<")"<<endl;
								cout<<"\tnew Center[RIGHT]: X,Y,Z = ("<<CURR_RAVEN_STATE.pos[3]<<",";
								cout<<CURR_RAVEN_STATE.pos[4]<<","<<CURR_RAVEN_STATE.pos[5]<<")"<<endl;

								cout<<"\tnew HAPTIC Center[LEFT]: X,Y,Z = ("<<CURR_HAPTIC_STATE.position[0]<<",";
												cout<<CURR_HAPTIC_STATE.position[1]<<","<<CURR_HAPTIC_STATE.position[2]<<")"<<endl;
												cout<<"\tnew HAPTIC Center[RIGHT]: X,Y,Z = ("<<CURR_HAPTIC_STATE.position[3]<<",";
												cout<<CURR_HAPTIC_STATE.position[4]<<","<<CURR_HAPTIC_STATE.position[5]<<")"<<endl;
								print_menu = true;
                                                                update_surgeon_mode = true;
								current_surgeon_mode = 1;
								CURR_HAPTIC_COMMANDS.lock_grasp = CURR_HAPTIC_COMMANDS.lock_position = CURR_HAPTIC_COMMANDS.lock_orientation = false;
				break;
			}
			case 'u': // update runlevel to stop teleop
			{

				CURR_HAPTIC_COMMANDS.lock_grasp = CURR_HAPTIC_COMMANDS.lock_position = CURR_HAPTIC_COMMANDS.lock_orientation = true;;
                                update_surgeon_mode = true;
                                current_surgeon_mode = 0;
				publish_haptic_commands();
				break;
			}
			/*
				// [DANGER]: for modification parameter tuning only
				case 'a':
				{	cout<<"You chose a : increase Modi_Scale."<<endl;
					LEFT_PATH.set_Modi_Scale(1);
					print_menu = true;
					break;
				}
				case 'z':
				{	cout<<"You chose z : decrease Modi_Scale."<<endl;
					LEFT_PATH.set_Modi_Scale(-1);
					print_menu = true;
					break;
				}
				case 's':
				{	cout<<"You chose s : increase Modi_Speed_Pow."<<endl;
					LEFT_PATH.set_Modi_Speed_Pow(1);
					print_menu = true;
					break;
				}
				case 'x':
				{	cout<<"You chose x : decrease Modi_Speed_Pow."<<endl;
					LEFT_PATH.set_Modi_Speed_Pow(-1);
					print_menu = true;
					break;
				}
				case 'd':
				{	cout<<"You chose d : increase Modi_Dista_Pow."<<endl;
					LEFT_PATH.set_Modi_Dista_Pow(1);
					print_menu = true;
					break;
				}
				case 'c':
				{	cout<<"You chose c : decrease Modi_Dista_Pow."<<endl;
					LEFT_PATH.set_Modi_Dista_Pow(-1);
					print_menu = true;
					break;
				}
			 */

			}

			if(SHOW_STATUS && (time.now()-time).toSec() > 1)
			{
				output_STATUS();
				time = time.now();
			}
		}
		cout<<"console_process is shutdown."<<endl;

	}
	return 0;
}



/**
 *	\fn void *ros_process(void)
 *
 * 	\brief this thread is dedicated to ros pub & sub
 *
 * 	\param a pointer to void
 *
 *	\return void
 */
void* Raven_Control::ros_process(void)
{
	if(ros::isInitialized())
	{
		if(!RECEIVED_FIRST)
			cout<<endl<<"Waiting for the first receive of raven_state..."<<endl;
		else
		{
			cout<<"First raven_state received."<<endl;
			cout<<"Save as default center potition."<<endl;

			LEFT_ARM_RAVEN.set_Center(CURR_RAVEN_STATE.pos,CURR_RAVEN_STATE.grasp);
			LEFT_ARM_HAPTIC.set_Center(CURR_HAPTIC_STATE.position,CURR_HAPTIC_STATE.gripper);

			RIGHT_ARM_RAVEN.set_Center(CURR_RAVEN_STATE.pos,CURR_RAVEN_STATE.grasp);
			RIGHT_ARM_HAPTIC.set_Center(CURR_HAPTIC_STATE.position,CURR_HAPTIC_STATE.gripper);

		}

		while(ros::ok())// && RECEIVED_FIRST)
		{
			// (1) update current raven_state (for future computation uses)
			LEFT_ARM_RAVEN.set_Current_Pos(CURR_RAVEN_STATE.pos);
			LEFT_ARM_RAVEN.set_Current_Ori(CURR_RAVEN_STATE.ori);

			RIGHT_ARM_RAVEN.set_Current_Pos(CURR_RAVEN_STATE.pos);
			RIGHT_ARM_RAVEN.set_Current_Ori(CURR_RAVEN_STATE.ori);



			LEFT_ARM_HAPTIC.set_Current_Pos(CURR_HAPTIC_STATE.position);
			LEFT_ARM_HAPTIC.set_Current_Ori(CURR_HAPTIC_STATE.orientation);
			LEFT_ARM_HAPTIC.set_Current_Grasp(CURR_HAPTIC_STATE.gripper);

			RIGHT_ARM_HAPTIC.set_Current_Pos(CURR_HAPTIC_STATE.position);
			RIGHT_ARM_HAPTIC.set_Current_Ori(CURR_HAPTIC_STATE.orientation);
			RIGHT_ARM_HAPTIC.set_Current_Grasp(CURR_HAPTIC_STATE.gripper);


			// (2) generate new command (plan trajectory)
			if(PAUSE) 
			{
				// stop raven

				TF_INCR[LEFT_ARM] = LEFT_ARM_RAVEN.ComputeTrajectory(LEFT_ARM_HAPTIC);
				TF_INCR[RIGHT_ARM] = RIGHT_ARM_RAVEN.ComputeTrajectory(RIGHT_ARM_HAPTIC);
				GRASP_INCR[RIGHT_ARM] = RIGHT_ARM_RAVEN.ComputeGrasp(RIGHT_ARM_HAPTIC);
				GRASP_INCR[LEFT_ARM] = RIGHT_ARM_RAVEN.ComputeGrasp(LEFT_ARM_HAPTIC);
				publish_raven_control();
				TF_INCR[LEFT_ARM] = LEFT_ARM_RAVEN.ComputeNullTrajectory(); 
				TF_INCR[RIGHT_ARM] = RIGHT_ARM_RAVEN.ComputeNullTrajectory();
				GRASP_INCR[RIGHT_ARM] = 0;
				GRASP_INCR[LEFT_ARM] = 0;


			}

			// (3) publish new command (send it out)
			else 
			{
				// normal moving case
				//TF_INCR[LEFT_ARM] = LEFT_PATH.ComputeNullTrajectory(); 
				//TF_INCR[LEFT_ARM] = LEFT_ARM_RAVEN.ComputeCircleTrajectory();
				//TF_INCR[RIGHT_ARM] = RIGHT_ARM_RAVEN.ComputeCircleTrajectory();
				TF_INCR[LEFT_ARM] = LEFT_ARM_RAVEN.ComputeTrajectory(LEFT_ARM_HAPTIC);
				TF_INCR[RIGHT_ARM] = RIGHT_ARM_RAVEN.ComputeTrajectory(RIGHT_ARM_HAPTIC);
				GRASP_INCR[RIGHT_ARM] = RIGHT_ARM_RAVEN.ComputeGrasp(RIGHT_ARM_HAPTIC);
				GRASP_INCR[LEFT_ARM] = RIGHT_ARM_RAVEN.ComputeGrasp(LEFT_ARM_HAPTIC);
				if (orientation _matching)
				{
					CURR_HAPTIC_COMMANDS.torque = computeOrientationMatch();
					publish_haptic_commands();
				}

				publish_raven_control();


			}

			// (3) publish new command (send it out)
//			publish_raven_control();

		}

		if(RECEIVED_FIRST)
			cout<<"ros_process is shutdown."<<endl;
	}
	return 0;
}



void * Raven_Control::static_console_process(void* classRef)
{
	return ((Raven_Control *)classRef)->console_process();
}



void * Raven_Control::static_ros_process(void* classRef)
{
	return ((Raven_Control *)classRef)->ros_process();
}


/**
 *	\fn void publish_raven_automove()
 *
 *	\brief publish the auto circle command to raven_automove topic on ROS.
 *
 * 	\param int
 *
 *	\return void
 */
void Raven_Control::publish_raven_control()
{
	static ros::Rate loop_rate(ROS_PUBLISH_RATE);
	static raven_automove msg_raven_control;	
	// (1) wrap up the new command	
	msg_raven_control.hdr.stamp = msg_raven_control.hdr.stamp.now(); //hdr

	tf::transformTFToMsg(TF_INCR[LEFT_ARM], msg_raven_control.tf_incr[LEFT_ARM]);   //tf_incr
	tf::transformTFToMsg(TF_INCR[RIGHT_ARM], msg_raven_control.tf_incr[RIGHT_ARM]);
	msg_raven_control.grasp[0] = GRASP_INCR[0];
	msg_raven_control.grasp[1] = GRASP_INCR[1];

//cout<<"I am here"<<endl;
	// (2) send new command
	//raven_publisher.publish(msg_raven_control);
       //msg_raven_control.surgeon_mode= CURR_RAVEN_STATE.surgeon_mode;
        if (update_surgeon_mode)
	{
                update_surgeon_mode = false;
                msg_raven_control.surgeon_mode = current_surgeon_mode;
	}
	raven_publisher_tester.publish(msg_raven_control);
	ros::spinOnce();

	//(3) prepare for next publish
	loop_rate.sleep();
	PUB_COUNT ++;
}

void Raven_Control::publish_haptic_commands()
{
	static ros::Rate loop_rate(ROS_PUBLISH_RATE);

	// (1) wrap up the new command

//cout<<"I am here"<<endl;
	// (2) send new command
	//raven_publisher.publish(msg_raven_control);

	haptic_publisher.publish(CURR_HAPTIC_COMMANDS);

	ros::spinOnce();

	//(3) prepare for next publish
	loop_rate.sleep();
	//PUB_COUNT ++;
}

/**
 *	\fn void autoRavenStateCallback(raven_2::raven_state msg)
 *
 *	\brief This function is automatically called whenever someone publish to raven_state topic
 *
 * 	\param raven_2::raven_state msg
 *
 *	\return void
 */
void Raven_Control::callback_raven_state(raven_state msg) 
{
	// (1) save the updated raven_state 
	CURR_RAVEN_STATE.runlevel = msg.runlevel;
	CURR_RAVEN_STATE.sublevel = msg.sublevel;
	CURR_RAVEN_STATE.last_seq = msg.last_seq;
	CURR_RAVEN_STATE.dt = msg.dt;

	for(int i=0; i<2; i++)
	{
		CURR_RAVEN_STATE.type[i] = msg.type[i];
		CURR_RAVEN_STATE.grasp_d[i] = msg.grasp_d[i];
		CURR_RAVEN_STATE.grasp[i] = msg.grasp[i];
	}

	for(int i=0; i<6; i++)
	{
		CURR_RAVEN_STATE.pos[i] = msg.pos[i];
		CURR_RAVEN_STATE.pos_d[i] = msg.pos_d[i];
	}

	for(int i=0; i<18; i++)
	{
		CURR_RAVEN_STATE.ori[i] = msg.ori[i];
		CURR_RAVEN_STATE.ori_d[i] = msg.ori_d[i];
	}
	//std::cout<<"i am here"<<endl;
	// (2) update recieved data count
	SUB_COUNT ++;
	RECEIVED_FIRST = true;
}
void Raven_Control::callback_haptic_state(haptic_device msg) 
{
	// (1) save the updated raven_state 
	//	CURR_HAPTIC_STATE.runlevel = msg.runlevel;
	//	CURR_HAPTIC_STATE.sublevel = msg.sublevel;
	//	CURR_HAPTIC_STATE.last_seq = msg.last_seq;
	//	CURR_HAPTIC_STATE.dt = msg.dt;

	for(int i=0; i<2; i++)
	{
		//	CURR_HAPTIC_STATE.type[i] = msg.type[i];
		CURR_HAPTIC_STATE.gripper[i] = msg.gripper[i];
	}

	for(int i=0; i<6; i++)
	{
		CURR_HAPTIC_STATE.position[i] = msg.position[i];
	}

	for(int i=0; i<18; i++)
	{
		CURR_HAPTIC_STATE.orientation[i] = msg.orientation[i];
	}

	// (2) update recieved data count
	SUB_COUNT ++;
	RECEIVED_FIRST = true;
}

float* computeOrientationMatch()
{

}

// pointer version of callback function (not working for now)
//..

/**
 *	\fn void autoRavenStateCallback(boost::shared_ptr< ::raven_state_<ContainerAllocator> const> msg)
 *
 *	\brief This function is automatically called whenever someone publish to raven_state topic
 *
 * 	\param boost::shared_ptr< ::raven_state_<ContainerAllocator> const
 *
 *	\return void
 */
/*
void autoRavenStateCallback(boost::shared_ptr< ::raven_state_<ContainerAllocator> const> msg) 
{
	// (1) save the updated raven_state 
	CURR_RAVEN_STATE.runlevel = msg->runlevel;
	CURR_RAVEN_STATE.sublevel = msg->sublevel;
	CURR_RAVEN_STATE.last_seq = msg->last_seq;
	CURR_RAVEN_STATE.dt = msg->dt;

	for(int i=0; i<2; i++)
	{
		CURR_RAVEN_STATE.type[i] = msg->type[i];
		CURR_RAVEN_STATE.grasp_d[i] = msg->grasp_d[i];
	}

	for(int i=0; i<6; i++)
	{
		CURR_RAVEN_STATE.pos[i] = msg->pos[i];
		CURR_RAVEN_STATE.pos_d[i] = msg->pos_d[i];
	}


	for(int i=0; i<18; i++)
	{
		CURR_RAVEN_STATE.ori[i] = msg->ori[i];
		CURR_RAVEN_STATE.ori_d[i] = msg->ori_d[i];
	}

	// (2) update recieved data count
	SUB_COUNT ++;
}
 */



/**
 *	\fn void output_fSTATUS()
 *
 * 	\brief shows the AutoCircle generator status (display every one sec)
 *
 * 	\param void
 *
 *	\return void
 */
void Raven_Control::output_STATUS()
{
	//	tfScalar R = LEFT_PATH.get_Radius(); 		// in cm
	//	tfScalar dR = LEFT_PATH.get_Radius_Range();	// in cm
	//	tfScalar SP = LEFT_PATH.get_Speed(); 		// in cm/sec
	//	tfScalar k = LEFT_PATH.get_K();
	//
	//        cout<<"current AutoCircle status :"<<endl;
	//
	//	switch(BASE_PLANE)
	//	{
	//		case YZ_PLANE:
	//			cout<<"\tBASE   = Y-Z plane";
	//		break;
	//		case XZ_PLANE:
	//			cout<<"\tBASE   = X-Z plane";
	//		break;
	//		case XY_PLANE:
	//			cout<<"\tBASE   = X-Y plane";
	//		break;
	//	}
	//
	//	if(DIRECTION > 0)
	//		cout<<"\t(Counter-Clockwise circle)"<<endl;
	//	else
	//		cout<<"\t(Clockwise circle)"<<endl;
	//
	//	cout<<"\tRADIUS = "<<R<<"~"<<(R+dR)<<" cm \t(level "<<RADIUS<<")"<<endl;
	//	cout<<"\tSPEED  = "<<SP<<" cm/sec\t(level "<<SPEED<<")"<<endl;
	//	cout<<"\tK      = "<<k<<" \t(Regulating Term: 0~1)"<<endl<<endl;
	//
	//	/*
	//	// [DANGER]: for modification parameter tuning only
	//	tfScalar modi_scale = LEFT_PATH.get_Modi_Scale();
	//	tfScalar modi_speed_pow = LEFT_PATH.get_Modi_Speed_Pow();
	//	tfScalar modi_dista_pow = LEFT_PATH.get_Modi_Dista_Pow();

	//	cout<<"\tscale="<<modi_scale<<" speedPow="<<modi_speed_pow<<" disPow="<<modi_dista_pow<<endl;
	//	*/

	output_PATHinfo();
	output_PUBinfo();
	output_SUBinfo();
}



/**
 *	\fn void output_PATHinfo()
 *
 * 	\brief shows the publish status (display every one sec)
 *
 * 	\param void
 *
 *	\return void
 */
void Raven_Control::output_PATHinfo()
{
	cout<<"current PathPlanner status : "<<endl;

	//LEFT_PATH.show_delPos();
	//RIGHT_PATH.show_delPos(); 	//(RIGHT_ARM unused right now)

	RIGHT_ARM_RAVEN.show_Center();
	LEFT_ARM_RAVEN.show_Center();
	RIGHT_ARM_HAPTIC.show_Center();
	LEFT_ARM_HAPTIC.show_Center();
	//RIGHT_PATH.show_Center(); 	//(RIGHT_ARM unused right now)

	//LEFT_PATH.show_Distance();
	//RIGHT_PATH.show_Distance(); 	//(RIGHT_ARM unused right now)

	//LEFT_PATH.show_PathState();
	//RIGHT_PATH.show_PathState(); 	//(RIGHT_ARM unused right now)
	cout<<endl<<endl;

}




/**
 *	\fn void output_PUBinfo()
 *
 * 	\brief shows the publish status (display every one sec)
 *
 * 	\param void
 *
 *	\return void
 */
void Raven_Control::output_PUBinfo()
{
	ROS_INFO("talkerAutoCircle publish: raven_automove[%d]", PUB_COUNT);
}



/**
 *	\fn void output_SUBinfo()
 *
 * 	\brief shows the subscribe status (display every one sec)
 *
 * 	\param void
 *
 *	\return void
 */
void Raven_Control::output_SUBinfo()
{
	ROS_INFO("talkerAutoCircle subscribe: raven_state[%d]", SUB_COUNT);

	//raven position
	cout<<"\t"<<"pos[LEFT] = ("<<CURR_RAVEN_STATE.pos[0]<<","<<CURR_RAVEN_STATE.pos[1];
	cout<<","<<CURR_RAVEN_STATE.pos[2]<<")"<<endl;
	cout<<"\t"<<"grasp[LEFT] = ("<<CURR_RAVEN_STATE.grasp[0]<<")"<<endl;

	cout<<"\t"<<"pos[RIGHT] = ("<<CURR_RAVEN_STATE.pos[3]<<","<<CURR_RAVEN_STATE.pos[4];
	cout<<","<<CURR_RAVEN_STATE.pos[5]<<")"<<endl;
	cout<<"\t"<<"grasp[RIGHT] = ("<<CURR_RAVEN_STATE.grasp[1]<<")"<<endl;

	// raven rotation
	//cout<<"\t"<<"ori[LEFT] = \t\t\tori[RIGHT] = "<<endl;
	cout<<"\t"<<"ori[LEFT] = "<<endl;
	for(int orii=0; orii<3; orii++)
	{
		cout<<"\t\t";
		for(int orij=0; orij<3; orij++)
		{
			cout<<CURR_RAVEN_STATE.ori[RIGHT_ARM*9+orii*3+orij]<<"\t";
		}
		cout<<"\t";
		cout<<endl;
	}
	cout<<"\t"<<"ori[RIGHT] = "<<endl;
	for(int orii=0; orii<3; orii++)
	{
		cout<<"\t\t";
		for(int orij=0; orij<3; orij++)
		{
			cout<<CURR_RAVEN_STATE.ori[LEFT_ARM*9+orii*3+orij]<<"\t";
		}

		cout<<"\t";
		cout<<endl;
	}

	//haptic position


	// haptic rotation
	//cout<<"\t"<<"ori[LEFT] = \t\t\tori[RIGHT] = "<<endl;
	cout<<endl<<endl<<"\t"<<"HAPTIC DEVICE"<<endl;
	cout<<"\t"<<"pos[LEFT] = ("<<CURR_HAPTIC_STATE.position[0]<<","<<CURR_HAPTIC_STATE.position[1];
	cout<<","<<CURR_HAPTIC_STATE.position[2]<<")"<<endl;

	cout<<"\t"<<"pos[RIGHT] = ("<<CURR_HAPTIC_STATE.position[3]<<","<<CURR_HAPTIC_STATE.position[4];
	cout<<","<<CURR_HAPTIC_STATE.position[5]<<")"<<endl;

	cout<<"\t"<<"ori[LEFT] = "<<endl;
	for(int orii=0; orii<3; orii++)
	{
		cout<<"\t\t";
		for(int orij=0; orij<3; orij++)
		{
			cout<<CURR_HAPTIC_STATE.orientation[LEFT_ARM*9+orii*3+orij]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\t"<<"ori[RIGHT] = "<<endl;
	for(int orii=0; orii<3; orii++)
	{
		cout<<"\t";
		for(int orij=0; orij<3; orij++)
		{
			cout<<CURR_HAPTIC_STATE.orientation[RIGHT_ARM*9+orii*3+orij]<<"\t";
		}
		cout<<endl;
	}

	cout<<endl;

	/* 
	// raven desired rotation (not important)
	cout<<"\t"<<"ori_d[LEFT_ARM] = \t\tori_d[RIGHT_ARM] = "<<endl;
	for(int orii=0; orii<3; orii++)
	{
		cout<<"\t\t";
		for(int orij=0; orij<3; orij++)
		{
			cout<<CURR_RAVEN_STATE.ori_d[LEFT_ARM*9+orii*3+orij]<<"\t";
		}
		cout<<"\t";
		for(int orij=0; orij<3; orij++)
		{
			cout<<CURR_RAVEN_STATE.ori_d[RIGHT_ARM*9+orii*3+orij]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl
	 */

	cout<<endl;
}



/**
 *	\fn int getKey()
 *
 *	\brief gets keyboard character for switch case's of console_process()
 *
 * 	\param void
 *
 *	\return character int
 */
int Raven_Control::getKey()
{
	int character;
	struct termios orig_term_attr;
	struct termios new_term_attr;

	// set the terminal to raw mode
	tcgetattr(fileno(stdin), &orig_term_attr);
	memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
	new_term_attr.c_lflag &= ~(ECHO|ICANON);
	new_term_attr.c_cc[VTIME] = 0;
	new_term_attr.c_cc[VMIN] = 0;
	tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

	// read a character from the stdin stream without blocking
	//   returns EOF (-1) if no character is available
	character = fgetc(stdin);

	// restore the original terminal attributes
	tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

	return character;
}
