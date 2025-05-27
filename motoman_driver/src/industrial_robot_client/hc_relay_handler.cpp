
#include <vector>

#include "motoman_driver/industrial_robot_client/hc_relay_handler.h"

namespace industrial_robot_client
{
    namespace hc_relay_handler
    {

        bool HcRelayHandler::init(industrial::smpl_msg_connection::SmplMsgConnection* connection)
        {
            this->pub_hc_sensor_state = this->node_.advertise<motoman_msgs::HcFtSensor>("hc_sensor", 1);

            return MessageHandler::init(2019, connection);
        }

        bool HcRelayHandler::internalCB(SimpleMessage& msg_in)
        {
            motoman_msgs::HcFtSensor hc_sensor;
            bool rtn = true;

            if (create_messages(msg_in, &hc_sensor))
            {
                rtn = true;
            }
            else
                rtn = false;

            //// Reply back to the controller if the sender requested it.
            //if (CommTypes::SERVICE_REQUEST == msg_in.getMessageType())
            //{
            //    SimpleMessage reply;
            //    reply.init(msg_in.getMessageType(),
            //        CommTypes::SERVICE_REPLY,
            //        rtn ? ReplyTypes::SUCCESS : ReplyTypes::FAILURE);
            //    this->getConnection()->sendMsg(reply);
            //}

            return rtn;
        }

        bool HcRelayHandler::create_messages(SimpleMessage& msg_in, motoman_msgs::HcFtSensor* hc_sensor)
        {
            //HcFeedbackMessage message;

            //if (!message.init(msg_in))
            //{
            //    LOG_ERROR("Failed to initialize hc message");
            //    return false;
            //}

            industrial::byte_array::ByteArray bytes = msg_in.getData();

            industrial::shared_types::shared_int groupNo;
            industrial::shared_types::shared_real sreal;

            *hc_sensor = motoman_msgs::HcFtSensor();

            bytes.unload(sreal);
            hc_sensor->tcp.torque.z = sreal;
            bytes.unload(sreal);
            hc_sensor->tcp.torque.y = sreal;
            bytes.unload(sreal);
            hc_sensor->tcp.torque.x = sreal;

            bytes.unload(sreal);
            hc_sensor->tcp.force.z = sreal;
            bytes.unload(sreal);
            hc_sensor->tcp.force.y = sreal;
            bytes.unload(sreal);
            hc_sensor->tcp.force.x = sreal;
            
            hc_sensor->joints.resize(6);
            for (int i = 0; i < 6; i += 1)
            {
                bytes.unload(sreal);
                hc_sensor->joints[i] = sreal;
            }

            bytes.unload(groupNo);

            this->pub_hc_sensor_state.publish(*hc_sensor);

            return true;
        }
    }
}
