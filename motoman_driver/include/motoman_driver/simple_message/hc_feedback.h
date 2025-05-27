
#ifndef MOTOMAN_DRIVER_SIMPLE_MESSAGE_HC_FEEDBACK_H
#define MOTOMAN_DRIVER_SIMPLE_MESSAGE_HC_FEEDBACK_H

#ifndef FLATHEADERS
#include "simple_message/joint_data.h"
#include "simple_message/simple_message.h"
#include "simple_message/simple_serialize.h"
#include "simple_message/shared_types.h"
#include "simple_message/joint_feedback.h"
#include "simple_message/messages/hc_feedback_message.h"
#else
#include "joint_data.h"        // NOLINT(build/include)
#include "simple_message.h"    // NOLINT(build/include)
#include "simple_serialize.h"  // NOLINT(build/include)
#include "shared_types.h"      // NOLINT(build/include)
#include "joint_feedback.h"    // NOLINT(build/include)
#include "messages/hc_feedback_message.h"
#endif

#include<vector>

namespace industrial
{
    namespace hc_feedback
    {

        class HcFeedback : public industrial::simple_serialize::SimpleSerialize
        {
        public:
            /**
             * \brief Default constructor
             *
             * This method creates empty data.
             *
             */
            HcFeedback(void);
            /**
             * \brief Destructor
             *
             */
            ~HcFeedback(void);

            /**
             * \brief Initializes a empty hc feedback
             *
             */
            void init();

            /**
             * \brief Copies the passed in value
             *
             * \param src (value to copy)
             */
            void copyFrom(HcFeedback& src);

            /**
             * \brief == operator implementation
             *
             * \return true if equal
             */
            bool operator==(HcFeedback& rhs);

            industrial::shared_types::shared_int getGroupNumber();

            std::vector<industrial::shared_types::shared_real> getJointTorques();

            std::vector<industrial::shared_types::shared_real> getTcpForces();

            /**
             * \brief check the validity state for a given field
             * @param field field to check
             * @return true if specified field contains valid data
             */

             // Overrides - SimpleSerialize
            bool load(industrial::byte_array::ByteArray* buffer);
            bool unload(industrial::byte_array::ByteArray* buffer);
            unsigned int byteLength()
            {
                return sizeof(industrial::shared_types::shared_int) + 12 * sizeof(industrial::shared_types::shared_real);
            }

        private:
            /**
             * \brief Number of groups attached to the controller
             */
            industrial::shared_types::shared_int group_number;

            std::vector<industrial::shared_types::shared_real> jointTorques;

            std::vector<industrial::shared_types::shared_real> tcpForces;
        };
    }  // namespace 
}  // namespace industrial


#endif  // MOTOMAN_DRIVER_SIMPLE_MESSAGE_HC_FEEDBACK_H
