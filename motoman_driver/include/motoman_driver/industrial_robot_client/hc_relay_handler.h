
#ifndef MOTOMAN_DRIVER_INDUSTRIAL_ROBOT_CLIENT_HC_RELAY_HANDLER_H
#define MOTOMAN_DRIVER_INDUSTRIAL_ROBOT_CLIENT_HC_RELAY_HANDLER_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "ros/ros.h"
#include "simple_message/message_handler.h"
#include "simple_message/messages/joint_message.h"
#include "motoman_driver/industrial_robot_client/robot_group.h"
#include "motoman_msgs/HcFtSensor.h"

namespace industrial_robot_client
{
    namespace hc_relay_handler
    {
        using industrial::simple_message::SimpleMessage;
        using motoman_msgs::HcFtSensor;

        class HcRelayHandler : public industrial::message_handler::MessageHandler
        {
        public:
            HcRelayHandler() {}

            bool init(industrial::smpl_msg_connection::SmplMsgConnection* connection);

        protected:
            ros::Publisher pub_hc_sensor_state;
            ros::NodeHandle node_;
            
            bool create_messages(SimpleMessage& msg_in, motoman_msgs::HcFtSensor* hc_sensor);

            bool internalCB(SimpleMessage& in);

        };  // class HcRelayHandler

    }  // namespace joint_relay_handler
}  // namespace industrial_robot_client


#endif  // MOTOMAN_DRIVER_INDUSTRIAL_ROBOT_CLIENT_HC_RELAY_HANDLER_H
