# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "raven_control: 2 messages, 0 services")

set(MSG_I_FLAGS "-Iraven_control:/home/bgusigma/amit_raven/src/raven_control/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(raven_control_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg" NAME_WE)
add_custom_target(_raven_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "raven_control" "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg" NAME_WE)
add_custom_target(_raven_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "raven_control" "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg" "geometry_msgs/Quaternion:geometry_msgs/Vector3:std_msgs/Header:geometry_msgs/Transform"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/raven_control
)
_generate_msg_cpp(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/raven_control
)

### Generating Services

### Generating Module File
_generate_module_cpp(raven_control
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/raven_control
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(raven_control_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(raven_control_generate_messages raven_control_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_cpp _raven_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_cpp _raven_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(raven_control_gencpp)
add_dependencies(raven_control_gencpp raven_control_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS raven_control_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/raven_control
)
_generate_msg_eus(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/raven_control
)

### Generating Services

### Generating Module File
_generate_module_eus(raven_control
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/raven_control
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(raven_control_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(raven_control_generate_messages raven_control_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_eus _raven_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_eus _raven_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(raven_control_geneus)
add_dependencies(raven_control_geneus raven_control_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS raven_control_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/raven_control
)
_generate_msg_lisp(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/raven_control
)

### Generating Services

### Generating Module File
_generate_module_lisp(raven_control
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/raven_control
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(raven_control_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(raven_control_generate_messages raven_control_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_lisp _raven_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_lisp _raven_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(raven_control_genlisp)
add_dependencies(raven_control_genlisp raven_control_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS raven_control_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/raven_control
)
_generate_msg_nodejs(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/raven_control
)

### Generating Services

### Generating Module File
_generate_module_nodejs(raven_control
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/raven_control
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(raven_control_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(raven_control_generate_messages raven_control_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_nodejs _raven_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_nodejs _raven_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(raven_control_gennodejs)
add_dependencies(raven_control_gennodejs raven_control_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS raven_control_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/raven_control
)
_generate_msg_py(raven_control
  "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Transform.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/raven_control
)

### Generating Services

### Generating Module File
_generate_module_py(raven_control
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/raven_control
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(raven_control_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(raven_control_generate_messages raven_control_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_state.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_py _raven_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/bgusigma/amit_raven/src/raven_control/msg/raven_automove.msg" NAME_WE)
add_dependencies(raven_control_generate_messages_py _raven_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(raven_control_genpy)
add_dependencies(raven_control_genpy raven_control_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS raven_control_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/raven_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/raven_control
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(raven_control_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(raven_control_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/raven_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/raven_control
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(raven_control_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(raven_control_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/raven_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/raven_control
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(raven_control_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(raven_control_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/raven_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/raven_control
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(raven_control_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(raven_control_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/raven_control)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/raven_control\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/raven_control
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(raven_control_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(raven_control_generate_messages_py geometry_msgs_generate_messages_py)
endif()
