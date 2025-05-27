//
//#ifndef FLATHEADERS
//#include "motoman_driver/simple_message/messages/hc_feedback_message.h"
//#include "simple_message/joint_data.h"
//#include "simple_message/byte_array.h"
//#include "simple_message/log_wrapper.h"
//#include "motoman_driver/simple_message/motoman_simple_message.h"
//#else
//#include "hc_feedback_message.h"  // NOLINT(build/include)
//#include "joint_data.h"                 // NOLINT(build/include)
//#include "byte_array.h"                 // NOLINT(build/include)
//#include "log_wrapper.h"                // NOLINT(build/include)
//#endif
//
//using industrial::byte_array::ByteArray;
//namespace MotomanMsgTypes = motoman::simple_message::MotomanMsgTypes;
//
//namespace industrial
//{
//    namespace hc_feedback_message
//    {
//
//        HcFeedbackMessage::HcFeedbackMessage(void)
//        {
//            this->init();
//        }
//
//        HcFeedbackMessage::~HcFeedbackMessage(void)
//        {
//        }
//
//        bool HcFeedbackMessage::init(industrial::simple_message::SimpleMessage& msg)
//        {
//            bool rtn = false;
//            ByteArray data = msg.getData();
//            this->init();
//
//            if (data.unload(this->data_))
//            {
//                rtn = true;
//            }
//            else
//            {
//                LOG_ERROR("Failed to unload hc feedback message data");
//            }
//            return rtn;
//        }
//
//        void HcFeedbackMessage::init(industrial::hc_feedback::HcFeedback& data)
//        {
//            this->init();
//            this->data_.copyFrom(data);
//        }
//
//        void HcFeedbackMessage::init()
//        {
//            this->setMessageType(MotomanMsgTypes::ROS_MSG_MOTO_HC_FEEDBACK);
//            this->data_.init();
//        }
//
//        bool HcFeedbackMessage::load(ByteArray* buffer)
//        {
//            bool rtn = false;
//            LOG_COMM("Executing hc feedback message load");
//            if (buffer->load(this->data_))
//            {
//                rtn = true;
//            }
//            else
//            {
//                rtn = false;
//                LOG_ERROR("Failed to load hc feedback message data");
//            }
//            return rtn;
//        }
//
//        bool HcFeedbackMessage::unload(ByteArray* buffer)
//        {
//            bool rtn = false;
//            LOG_COMM("Executing hc feedback message unload");
//
//            if (buffer->unload(this->data_))
//            {
//                rtn = true;
//            }
//            else
//            {
//                rtn = false;
//                LOG_ERROR("Failed to unload hc feedback message data");
//            }
//            return rtn;
//        }
//
//    }  // namespace hc_feedback_message
//}  // namespace industrial
//
//
