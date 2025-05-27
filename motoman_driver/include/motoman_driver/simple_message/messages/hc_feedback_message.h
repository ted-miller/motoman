//
//#ifndef MOTOMAN_DRIVER_SIMPLE_MESSAGE_MESSAGES_HC_FEEDBACK_MESSAGE_H
//#define MOTOMAN_DRIVER_SIMPLE_MESSAGE_MESSAGES_HC_FEEDBACK_MESSAGE_H
//
//#include <vector>
//
//#ifndef FLATHEADERS
//#include "simple_message/typed_message.h"
//#include "simple_message/simple_message.h"
//#include "simple_message/shared_types.h"
//#include "motoman_driver/simple_message/hc_feedback.h"
//#else
//#include "typed_message.h"      // NOLINT(build/include)
//#include "simple_message.h"     // NOLINT(build/include)
//#include "shared_types.h"       // NOLINT(build/include)
//#include "hc_feedback.h"  // NOLINT(build/include)
//#endif
//
//namespace industrial
//{
//    namespace hc_feedback_message
//    {
//        class HcFeedbackMessage : public industrial::typed_message::TypedMessage
//        {
//        public:
//            /**
//             * \brief Default constructor
//             *
//             * This method creates an empty message.
//             *
//             */
//            HcFeedbackMessage(void);
//            /**
//             * \brief Destructor
//             *
//             */
//            ~HcFeedbackMessage(void);
//            /**
//             * \brief Initializes message from a simple message
//             *
//             * \param simple message to construct from
//             *
//             * \return true if message successfully initialized, otherwise false
//             */
//            bool init(industrial::simple_message::SimpleMessage& msg);
//
//            /**
//             * \brief Initializes message from a HcFeedback structure
//             *
//             * \param joint feedback data structure
//             *
//             */
//            void init(industrial::hc_feedback::HcFeedback& data);
//
//            /**
//             * \brief Initializes a new message
//             *
//             */
//            void init();
//
//            // Overrides - SimpleSerialize
//            bool load(industrial::byte_array::ByteArray* buffer);
//            bool unload(industrial::byte_array::ByteArray* buffer);
//
//            unsigned int byteLength()
//            {
//                return this->data_.byteLength();
//            }
//
//            std::vector<industrial::shared_types::shared_real> getJointTorques()
//            {
//                return this->data_.getJointTorques();
//            }
//
//            std::vector<industrial::shared_types::shared_real> getTcpForces()
//            {
//                return this->data_.getTcpForces();
//            }
//
//        private:
//            industrial::hc_feedback::HcFeedback data_;
//        };
//    }  // namespace 
//}  // namespace industrial
//
//
//#endif  // MOTOMAN_DRIVER_SIMPLE_MESSAGE_MESSAGES_HC_FEEDBACK_MESSAGE_H
