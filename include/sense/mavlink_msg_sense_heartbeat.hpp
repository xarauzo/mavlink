// MESSAGE SENSE_HEARTBEAT support class

#pragma once

namespace mavlink {
namespace sense {
namespace msg {

/**
 * @brief SENSE_HEARTBEAT message
 *
 * Pipeline heartbeat with health report (updated at 1Hz)
 */
struct SENSE_HEARTBEAT : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50000;
    static constexpr size_t LENGTH = 1;
    static constexpr size_t MIN_LENGTH = 1;
    static constexpr uint8_t CRC_EXTRA = 176;
    static constexpr auto NAME = "SENSE_HEARTBEAT";


    uint8_t status; /*<  See the SENSE_STATE enum. */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  status: " << +status << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << status;                        // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> status;                        // offset: 0
    }
};

} // namespace msg
} // namespace sense
} // namespace mavlink
