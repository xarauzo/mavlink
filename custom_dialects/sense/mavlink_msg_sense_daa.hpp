// MESSAGE SENSE_DAA support class

#pragma once

namespace mavlink {
namespace sense {
namespace msg {

/**
 * @brief SENSE_DAA message
 *
 * Detection and Avoidance data.
 */
struct SENSE_DAA : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50003;
    static constexpr size_t LENGTH = 54;
    static constexpr size_t MIN_LENGTH = 54;
    static constexpr uint8_t CRC_EXTRA = 185;
    static constexpr auto NAME = "SENSE_DAA";


    uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time). */
    uint8_t target_system; /*<  System ID */
    uint8_t target_component; /*<  Component ID */
    uint32_t frame_num; /*<  Frame number */
    uint16_t tracker_id; /*<  Tracker ID */
    std::array<float, 4> bbox; /*< [pix] Bounding Box dimensions [top, left, height, width]. */
    float confidence; /*< [%] Confidence (probability). */
    float target_range; /*< [m] Estimated distance to detected target. */
    std::array<float, 3> target_relative_vector; /*< [m] Estimated relative vector to detected target, defined in camera axes. */
    uint16_t threat_level; /*<  Threat level for detected object. */


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
        ss << "  frame_num: " << frame_num << std::endl;
        ss << "  tracker_id: " << tracker_id << std::endl;
        ss << "  bbox: [" << to_string(bbox) << "]" << std::endl;
        ss << "  confidence: " << confidence << std::endl;
        ss << "  target_range: " << target_range << std::endl;
        ss << "  target_relative_vector: [" << to_string(target_relative_vector) << "]" << std::endl;
        ss << "  threat_level: " << threat_level << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_unix_usec;                // offset: 0
        map << frame_num;                     // offset: 8
        map << bbox;                          // offset: 12
        map << confidence;                    // offset: 28
        map << target_range;                  // offset: 32
        map << target_relative_vector;        // offset: 36
        map << tracker_id;                    // offset: 48
        map << threat_level;                  // offset: 50
        map << target_system;                 // offset: 52
        map << target_component;              // offset: 53
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_unix_usec;                // offset: 0
        map >> frame_num;                     // offset: 8
        map >> bbox;                          // offset: 12
        map >> confidence;                    // offset: 28
        map >> target_range;                  // offset: 32
        map >> target_relative_vector;        // offset: 36
        map >> tracker_id;                    // offset: 48
        map >> threat_level;                  // offset: 50
        map >> target_system;                 // offset: 52
        map >> target_component;              // offset: 53
    }
};

} // namespace msg
} // namespace sense
} // namespace mavlink
