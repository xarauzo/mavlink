// MESSAGE SENSE_AV_MAN support class

#pragma once

namespace mavlink {
namespace sense {
namespace msg {

/**
 * @brief SENSE_AV_MAN message
 *
 * Avoidance Maneuver trajectory data.
 */
struct SENSE_AV_MAN : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50005;
    static constexpr size_t LENGTH = 70;
    static constexpr size_t MIN_LENGTH = 70;
    static constexpr uint8_t CRC_EXTRA = 198;
    static constexpr auto NAME = "SENSE_AV_MAN";


    uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time). */
    uint8_t target_system; /*<  System ID */
    uint8_t target_component; /*<  Component ID */
    std::array<float, 5> waypoint_x; /*< [degE7] X-coordinate of waypoint in sphericals state type (Longitude) */
    std::array<float, 5> waypoint_y; /*< [degE7] Y-coordinate of waypoint in sphericals state type (Latitude) */
    std::array<float, 5> waypoint_z; /*< [degE7] Z-coordinate of waypoint in sphericals state type (Altitude) */


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
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;
        ss << "  waypoint_x: [" << to_string(waypoint_x) << "]" << std::endl;
        ss << "  waypoint_y: [" << to_string(waypoint_y) << "]" << std::endl;
        ss << "  waypoint_z: [" << to_string(waypoint_z) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_unix_usec;                // offset: 0
        map << waypoint_x;                    // offset: 8
        map << waypoint_y;                    // offset: 28
        map << waypoint_z;                    // offset: 48
        map << target_system;                 // offset: 68
        map << target_component;              // offset: 69
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_unix_usec;                // offset: 0
        map >> waypoint_x;                    // offset: 8
        map >> waypoint_y;                    // offset: 28
        map >> waypoint_z;                    // offset: 48
        map >> target_system;                 // offset: 68
        map >> target_component;              // offset: 69
    }
};

} // namespace msg
} // namespace sense
} // namespace mavlink
