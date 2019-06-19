// Generated by gencpp from file raven_2/raven_state.msg
// DO NOT EDIT!


#ifndef RAVEN_2_MESSAGE_RAVEN_STATE_H
#define RAVEN_2_MESSAGE_RAVEN_STATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace raven_2
{
template <class ContainerAllocator>
struct raven_state_
{
  typedef raven_state_<ContainerAllocator> Type;

  raven_state_()
    : hdr()
    , runlevel(0)
    , sublevel(0)
    , last_seq(0)
    , type()
    , pos()
    , ori()
    , ori_d()
    , pos_d()
    , dt()
    , encVals()
    , dac_val()
    , tau()
    , mpos()
    , jpos()
    , mvel()
    , jvel()
    , mpos_d()
    , jpos_d()
    , grasp()
    , grasp_d()
    , encoffsets()
    , jac_vel()
    , jac_f()  {
      type.assign(0);

      pos.assign(0);

      ori.assign(0.0);

      ori_d.assign(0.0);

      pos_d.assign(0);

      encVals.assign(0);

      dac_val.assign(0);

      tau.assign(0.0);

      mpos.assign(0.0);

      jpos.assign(0.0);

      mvel.assign(0.0);

      jvel.assign(0.0);

      mpos_d.assign(0.0);

      jpos_d.assign(0.0);

      grasp.assign(0.0);

      grasp_d.assign(0.0);

      encoffsets.assign(0.0);

      jac_vel.assign(0.0);

      jac_f.assign(0.0);
  }
  raven_state_(const ContainerAllocator& _alloc)
    : hdr(_alloc)
    , runlevel(0)
    , sublevel(0)
    , last_seq(0)
    , type()
    , pos()
    , ori()
    , ori_d()
    , pos_d()
    , dt()
    , encVals()
    , dac_val()
    , tau()
    , mpos()
    , jpos()
    , mvel()
    , jvel()
    , mpos_d()
    , jpos_d()
    , grasp()
    , grasp_d()
    , encoffsets()
    , jac_vel()
    , jac_f()  {
  (void)_alloc;
      type.assign(0);

      pos.assign(0);

      ori.assign(0.0);

      ori_d.assign(0.0);

      pos_d.assign(0);

      encVals.assign(0);

      dac_val.assign(0);

      tau.assign(0.0);

      mpos.assign(0.0);

      jpos.assign(0.0);

      mvel.assign(0.0);

      jvel.assign(0.0);

      mpos_d.assign(0.0);

      jpos_d.assign(0.0);

      grasp.assign(0.0);

      grasp_d.assign(0.0);

      encoffsets.assign(0.0);

      jac_vel.assign(0.0);

      jac_f.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _hdr_type;
  _hdr_type hdr;

   typedef int32_t _runlevel_type;
  _runlevel_type runlevel;

   typedef int32_t _sublevel_type;
  _sublevel_type sublevel;

   typedef int32_t _last_seq_type;
  _last_seq_type last_seq;

   typedef boost::array<int32_t, 2>  _type_type;
  _type_type type;

   typedef boost::array<int32_t, 6>  _pos_type;
  _pos_type pos;

   typedef boost::array<float, 18>  _ori_type;
  _ori_type ori;

   typedef boost::array<float, 18>  _ori_d_type;
  _ori_d_type ori_d;

   typedef boost::array<int32_t, 6>  _pos_d_type;
  _pos_d_type pos_d;

   typedef ros::Duration _dt_type;
  _dt_type dt;

   typedef boost::array<int32_t, 16>  _encVals_type;
  _encVals_type encVals;

   typedef boost::array<int32_t, 16>  _dac_val_type;
  _dac_val_type dac_val;

   typedef boost::array<float, 16>  _tau_type;
  _tau_type tau;

   typedef boost::array<float, 16>  _mpos_type;
  _mpos_type mpos;

   typedef boost::array<float, 16>  _jpos_type;
  _jpos_type jpos;

   typedef boost::array<float, 16>  _mvel_type;
  _mvel_type mvel;

   typedef boost::array<float, 16>  _jvel_type;
  _jvel_type jvel;

   typedef boost::array<float, 16>  _mpos_d_type;
  _mpos_d_type mpos_d;

   typedef boost::array<float, 16>  _jpos_d_type;
  _jpos_d_type jpos_d;

   typedef boost::array<float, 2>  _grasp_type;
  _grasp_type grasp;

   typedef boost::array<float, 2>  _grasp_d_type;
  _grasp_d_type grasp_d;

   typedef boost::array<float, 16>  _encoffsets_type;
  _encoffsets_type encoffsets;

   typedef boost::array<float, 12>  _jac_vel_type;
  _jac_vel_type jac_vel;

   typedef boost::array<float, 12>  _jac_f_type;
  _jac_f_type jac_f;





  typedef boost::shared_ptr< ::raven_2::raven_state_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::raven_2::raven_state_<ContainerAllocator> const> ConstPtr;

}; // struct raven_state_

typedef ::raven_2::raven_state_<std::allocator<void> > raven_state;

typedef boost::shared_ptr< ::raven_2::raven_state > raven_statePtr;
typedef boost::shared_ptr< ::raven_2::raven_state const> raven_stateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::raven_2::raven_state_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::raven_2::raven_state_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace raven_2

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'raven_2': ['/home/bguraven/catkin_ws/src/raven2/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::raven_2::raven_state_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::raven_2::raven_state_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::raven_2::raven_state_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::raven_2::raven_state_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::raven_2::raven_state_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::raven_2::raven_state_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::raven_2::raven_state_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9ce1ad1b2f12389e3fcd1b17df92e086";
  }

  static const char* value(const ::raven_2::raven_state_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9ce1ad1b2f12389eULL;
  static const uint64_t static_value2 = 0x3fcd1b17df92e086ULL;
};

template<class ContainerAllocator>
struct DataType< ::raven_2::raven_state_<ContainerAllocator> >
{
  static const char* value()
  {
    return "raven_2/raven_state";
  }

  static const char* value(const ::raven_2::raven_state_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::raven_2::raven_state_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header      	hdr\n\
int32       	runlevel\n\
int32       	sublevel\n\
int32       	last_seq\n\
int32[2]    	type\n\
int32[6]    	pos\n\
float32[18]   	ori\n\
float32[18]   	ori_d\n\
int32[6]    	pos_d\n\
duration    	dt\n\
int32[16]   	encVals\n\
int32[16]       dac_val\n\
float32[16] 	tau\n\
float32[16] 	mpos\n\
float32[16] 	jpos\n\
float32[16] 	mvel\n\
float32[16] 	jvel\n\
float32[16] 	mpos_d\n\
float32[16] 	jpos_d\n\
float32[2]  	grasp\n\
float32[2]  	grasp_d\n\
float32[16] 	encoffsets\n\
float32[12] 	jac_vel\n\
float32[12] 	jac_f\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::raven_2::raven_state_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::raven_2::raven_state_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.hdr);
      stream.next(m.runlevel);
      stream.next(m.sublevel);
      stream.next(m.last_seq);
      stream.next(m.type);
      stream.next(m.pos);
      stream.next(m.ori);
      stream.next(m.ori_d);
      stream.next(m.pos_d);
      stream.next(m.dt);
      stream.next(m.encVals);
      stream.next(m.dac_val);
      stream.next(m.tau);
      stream.next(m.mpos);
      stream.next(m.jpos);
      stream.next(m.mvel);
      stream.next(m.jvel);
      stream.next(m.mpos_d);
      stream.next(m.jpos_d);
      stream.next(m.grasp);
      stream.next(m.grasp_d);
      stream.next(m.encoffsets);
      stream.next(m.jac_vel);
      stream.next(m.jac_f);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct raven_state_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::raven_2::raven_state_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::raven_2::raven_state_<ContainerAllocator>& v)
  {
    s << indent << "hdr: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.hdr);
    s << indent << "runlevel: ";
    Printer<int32_t>::stream(s, indent + "  ", v.runlevel);
    s << indent << "sublevel: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sublevel);
    s << indent << "last_seq: ";
    Printer<int32_t>::stream(s, indent + "  ", v.last_seq);
    s << indent << "type[]" << std::endl;
    for (size_t i = 0; i < v.type.size(); ++i)
    {
      s << indent << "  type[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.type[i]);
    }
    s << indent << "pos[]" << std::endl;
    for (size_t i = 0; i < v.pos.size(); ++i)
    {
      s << indent << "  pos[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.pos[i]);
    }
    s << indent << "ori[]" << std::endl;
    for (size_t i = 0; i < v.ori.size(); ++i)
    {
      s << indent << "  ori[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.ori[i]);
    }
    s << indent << "ori_d[]" << std::endl;
    for (size_t i = 0; i < v.ori_d.size(); ++i)
    {
      s << indent << "  ori_d[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.ori_d[i]);
    }
    s << indent << "pos_d[]" << std::endl;
    for (size_t i = 0; i < v.pos_d.size(); ++i)
    {
      s << indent << "  pos_d[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.pos_d[i]);
    }
    s << indent << "dt: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.dt);
    s << indent << "encVals[]" << std::endl;
    for (size_t i = 0; i < v.encVals.size(); ++i)
    {
      s << indent << "  encVals[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.encVals[i]);
    }
    s << indent << "dac_val[]" << std::endl;
    for (size_t i = 0; i < v.dac_val.size(); ++i)
    {
      s << indent << "  dac_val[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.dac_val[i]);
    }
    s << indent << "tau[]" << std::endl;
    for (size_t i = 0; i < v.tau.size(); ++i)
    {
      s << indent << "  tau[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.tau[i]);
    }
    s << indent << "mpos[]" << std::endl;
    for (size_t i = 0; i < v.mpos.size(); ++i)
    {
      s << indent << "  mpos[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.mpos[i]);
    }
    s << indent << "jpos[]" << std::endl;
    for (size_t i = 0; i < v.jpos.size(); ++i)
    {
      s << indent << "  jpos[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.jpos[i]);
    }
    s << indent << "mvel[]" << std::endl;
    for (size_t i = 0; i < v.mvel.size(); ++i)
    {
      s << indent << "  mvel[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.mvel[i]);
    }
    s << indent << "jvel[]" << std::endl;
    for (size_t i = 0; i < v.jvel.size(); ++i)
    {
      s << indent << "  jvel[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.jvel[i]);
    }
    s << indent << "mpos_d[]" << std::endl;
    for (size_t i = 0; i < v.mpos_d.size(); ++i)
    {
      s << indent << "  mpos_d[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.mpos_d[i]);
    }
    s << indent << "jpos_d[]" << std::endl;
    for (size_t i = 0; i < v.jpos_d.size(); ++i)
    {
      s << indent << "  jpos_d[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.jpos_d[i]);
    }
    s << indent << "grasp[]" << std::endl;
    for (size_t i = 0; i < v.grasp.size(); ++i)
    {
      s << indent << "  grasp[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.grasp[i]);
    }
    s << indent << "grasp_d[]" << std::endl;
    for (size_t i = 0; i < v.grasp_d.size(); ++i)
    {
      s << indent << "  grasp_d[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.grasp_d[i]);
    }
    s << indent << "encoffsets[]" << std::endl;
    for (size_t i = 0; i < v.encoffsets.size(); ++i)
    {
      s << indent << "  encoffsets[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.encoffsets[i]);
    }
    s << indent << "jac_vel[]" << std::endl;
    for (size_t i = 0; i < v.jac_vel.size(); ++i)
    {
      s << indent << "  jac_vel[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.jac_vel[i]);
    }
    s << indent << "jac_f[]" << std::endl;
    for (size_t i = 0; i < v.jac_f.size(); ++i)
    {
      s << indent << "  jac_f[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.jac_f[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // RAVEN_2_MESSAGE_RAVEN_STATE_H