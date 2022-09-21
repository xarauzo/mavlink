// MESSAGE SENSE_STATE_VECTOR support class

#pragma once

namespace mavlink {
namespace sense {
namespace msg {

/**
 * @brief SENSE_STATE_VECTOR message
 *
 * State vector of ownship UAS.
 */
struct SENSE_STATE_VECTOR : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50004;
    static constexpr size_t LENGTH = 50;
    static constexpr size_t MIN_LENGTH = 50;
    static constexpr uint8_t CRC_EXTRA = 59;
    static constexpr auto NAME = "SENSE_STATE_VECTOR";


    uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time). */
    uint8_t target_system; /*<  System ID */
    uint8_t target_component; /*<  Component ID */
    uint32_t longitude; /*< [degE7] Longitude */
    uint32_t latitude; /*< [degE7] Geodetic Latitude */
    uint32_t altitude; /*< [degE7] Ellipsoidal Altitude */
    std::array<float, 4> quaternion; /*<  Quaternion defining UAS orientation. */
    float roll; /*< [rad] Roll attitude angle. */
    float pitch; /*< [rad] Pitch attitude angle. */
    float yaw; /*< [rad] Yaw attitude angle. */


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
        ss << "  longitude: " << longitude << std::endl;
        ss << "  latitude: " << latitude << std::endl;
        ss << "  altitude: " << altitude << std::endl;
        ss << "  quaternion: [" << to_string(quaternion) << "]" << std::endl;
        ss << "  roll: " << roll << std::endl;
        ss << "  pitch: " << pitch << std::endl;
        ss << "  yaw: " << yaw << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_unix_usec;                // offset: 0
        map << longitude;                     // offset: 8
        map << latitude;                      // offset: 12
        map << altitude;                      // offset: 16
        map << quaternion;                    // offset: 20
        map << roll;                          // offset: 36
        map << pitch;                         // offset: 40
        map << yaw;                           // offset: 44
        map << target_system;                 // offset: 48
        map << target_component;              // offset: 49
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_unix_usec;                // offset: 0
        map >> longitude;                     // offset: 8
        map >> latitude;                      // offset: 12
        map >> altitude;                      // offset: 16
        map >> quaternion;                    // offset: 20
        map >> roll;                          // offset: 36
        map >> pitch;                         // offset: 40
        map >> yaw;                           // offset: 44
        map >> target_system;                 // offset: 48
        map >> target_component;              // offset: 49
    }
};

} // namespace msg
} // namespace sense
} // namespace mavlink
