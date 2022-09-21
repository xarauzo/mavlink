// MESSAGE SENSE_AR support class

#pragma once

namespace mavlink {
namespace sense {
namespace msg {

/**
 * @brief SENSE_AR message
 *
 * Avoidance request to Remote Pilot in Loop (RPiL).
 */
struct SENSE_AR : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50002;
    static constexpr size_t LENGTH = 10;
    static constexpr size_t MIN_LENGTH = 10;
    static constexpr uint8_t CRC_EXTRA = 224;
    static constexpr auto NAME = "SENSE_AR";


    uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time). */
    uint8_t request; /*<  Request flag */
    uint8_t maneuver_type; /*<  See the MANEUVER_TYPE enum. */


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
        ss << "  request: " << +request << std::endl;
        ss << "  maneuver_type: " << +maneuver_type << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_unix_usec;                // offset: 0
        map << request;                       // offset: 8
        map << maneuver_type;                 // offset: 9
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_unix_usec;                // offset: 0
        map >> request;                       // offset: 8
        map >> maneuver_type;                 // offset: 9
    }
};

} // namespace msg
} // namespace sense
} // namespace mavlink
