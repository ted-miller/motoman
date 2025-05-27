
#include <vector>

#ifndef FLATHEADERS
#include "motoman_driver/simple_message/hc_feedback.h"
#include "simple_message/shared_types.h"
#include "simple_message/log_wrapper.h"
#else
#include "hc_feedback.h"  // NOLINT(build/include)
#include "shared_types.h"       // NOLINT(build/include)
#include "log_wrapper.h"        // NOLINT(build/include)
#endif

//using industrial::hc_feedback_message::HcFeedbackMessage;
using industrial::joint_feedback::JointFeedback;

namespace industrial
{
    namespace hc_feedback
    {

        HcFeedback::HcFeedback(void)
        {
            this->init();
        }

        HcFeedback::~HcFeedback(void)
        {
        }

        void HcFeedback::init()
        {
        }

        void HcFeedback::copyFrom(HcFeedback& src)
        {
            group_number = src.getGroupNumber();
            jointTorques = src.getJointTorques();
            tcpForces = src.getTcpForces();
        }

        bool HcFeedback::operator==(HcFeedback& rhs)
        {
            return (group_number == rhs.getGroupNumber() &&
                jointTorques == rhs.getJointTorques() &&
                tcpForces == rhs.getTcpForces());
        }

        bool HcFeedback::load(industrial::byte_array::ByteArray* buffer)
        {
            LOG_COMM("Executing hc feedback load");

            if (!buffer->load(this->group_number))
            {
                LOG_ERROR("Failed to load hc feedback groups_number");
                return false;
            }

            if (!buffer->load(this->jointTorques))
            {
                LOG_ERROR("Failed to load jointTorques");
                return false;
            }

            if (!buffer->load(this->tcpForces))
            {
                LOG_ERROR("Failed to load jointTorques");
                return false;
            }

            LOG_COMM("hc feedback successfully loaded");
            return true;
        }

        bool HcFeedback::unload(industrial::byte_array::ByteArray* buffer)
        {
            LOG_COMM("Executing joint feedback unload");

            if (!buffer->unload(this->group_number))
            {
                LOG_ERROR("Failed to unload hc feedback group_number");
                return false;
            }

            if (!buffer->unload(this->jointTorques))
            {
                LOG_ERROR("Failed to unload hc feedback jointTorques");
                return false;
            }

            if (!buffer->unload(this->tcpForces))
            {
                LOG_ERROR("Failed to unload hc feedback tcpForces");
                return false;
            }

            LOG_COMM("Joint feedback successfully unloaded");
            return true;
        }

    }  // namespace hc_feedback
}  // namespace industrial


