// MESSAGE SENSE_TIME support class

#pragma once

namespace mavlink {
namespace sense {
namespace msg {

/**
 * @brief SENSE_TIME message
 *
 * Time of startup/termination of Sense-Air service.
 */
struct SENSE_TIME : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50001;
    static constexpr size_t LENGTH = 9;
    static constexpr size_t MIN_LENGTH = 9;
    static constexpr uint8_t CRC_EXTRA = 241;
    static constexpr auto NAME = "SENSE_TIME";


    uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time). */
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
        ss << "  time_unix_usec: " << time_unix_usec << std::endl;
        ss << "  status: " << +status << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_unix_usec;                // offset: 0
        map << status;                        // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_unix_usec;                // offset: 0
        map >> status;                        // offset: 8
    }
};

} // namespace msg
} // namespace sense
} // namespace mavlink
