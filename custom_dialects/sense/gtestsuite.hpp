/** @file
 *	@brief MAVLink comm testsuite protocol generated from sense.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "sense.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(sense, SENSE_HEARTBEAT)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::sense::msg::SENSE_HEARTBEAT packet_in{};
    packet_in.status = 5;

    mavlink::sense::msg::SENSE_HEARTBEAT packet1{};
    mavlink::sense::msg::SENSE_HEARTBEAT packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.status, packet2.status);
}

#ifdef TEST_INTEROP
TEST(sense_interop, SENSE_HEARTBEAT)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sense_heartbeat_t packet_c {
         5
    };

    mavlink::sense::msg::SENSE_HEARTBEAT packet_in{};
    packet_in.status = 5;

    mavlink::sense::msg::SENSE_HEARTBEAT packet2{};

    mavlink_msg_sense_heartbeat_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.status, packet2.status);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(sense, SENSE_TIME)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::sense::msg::SENSE_TIME packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.status = 29;

    mavlink::sense::msg::SENSE_TIME packet1{};
    mavlink::sense::msg::SENSE_TIME packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet1.status, packet2.status);
}

#ifdef TEST_INTEROP
TEST(sense_interop, SENSE_TIME)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sense_time_t packet_c {
         93372036854775807ULL, 29
    };

    mavlink::sense::msg::SENSE_TIME packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.status = 29;

    mavlink::sense::msg::SENSE_TIME packet2{};

    mavlink_msg_sense_time_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet_in.status, packet2.status);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(sense, SENSE_AR)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::sense::msg::SENSE_AR packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.request = 29;
    packet_in.maneuver_type = 96;

    mavlink::sense::msg::SENSE_AR packet1{};
    mavlink::sense::msg::SENSE_AR packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet1.request, packet2.request);
    EXPECT_EQ(packet1.maneuver_type, packet2.maneuver_type);
}

#ifdef TEST_INTEROP
TEST(sense_interop, SENSE_AR)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sense_ar_t packet_c {
         93372036854775807ULL, 29, 96
    };

    mavlink::sense::msg::SENSE_AR packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.request = 29;
    packet_in.maneuver_type = 96;

    mavlink::sense::msg::SENSE_AR packet2{};

    mavlink_msg_sense_ar_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet_in.request, packet2.request);
    EXPECT_EQ(packet_in.maneuver_type, packet2.maneuver_type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(sense, SENSE_DAA)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::sense::msg::SENSE_DAA packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.target_system = 161;
    packet_in.target_component = 228;
    packet_in.frame_num = 963497880;
    packet_in.tracker_id = 19731;
    packet_in.bbox = {{ 101.0, 102.0, 103.0, 104.0 }};
    packet_in.confidence = 213.0;
    packet_in.target_range = 241.0;
    packet_in.target_relative_vector = {{ 269.0, 270.0, 271.0 }};
    packet_in.threat_level = 19835;

    mavlink::sense::msg::SENSE_DAA packet1{};
    mavlink::sense::msg::SENSE_DAA packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.frame_num, packet2.frame_num);
    EXPECT_EQ(packet1.tracker_id, packet2.tracker_id);
    EXPECT_EQ(packet1.bbox, packet2.bbox);
    EXPECT_EQ(packet1.confidence, packet2.confidence);
    EXPECT_EQ(packet1.target_range, packet2.target_range);
    EXPECT_EQ(packet1.target_relative_vector, packet2.target_relative_vector);
    EXPECT_EQ(packet1.threat_level, packet2.threat_level);
}

#ifdef TEST_INTEROP
TEST(sense_interop, SENSE_DAA)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sense_daa_t packet_c {
         93372036854775807ULL, 963497880, { 101.0, 102.0, 103.0, 104.0 }, 213.0, 241.0, { 269.0, 270.0, 271.0 }, 19731, 19835, 161, 228
    };

    mavlink::sense::msg::SENSE_DAA packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.target_system = 161;
    packet_in.target_component = 228;
    packet_in.frame_num = 963497880;
    packet_in.tracker_id = 19731;
    packet_in.bbox = {{ 101.0, 102.0, 103.0, 104.0 }};
    packet_in.confidence = 213.0;
    packet_in.target_range = 241.0;
    packet_in.target_relative_vector = {{ 269.0, 270.0, 271.0 }};
    packet_in.threat_level = 19835;

    mavlink::sense::msg::SENSE_DAA packet2{};

    mavlink_msg_sense_daa_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.frame_num, packet2.frame_num);
    EXPECT_EQ(packet_in.tracker_id, packet2.tracker_id);
    EXPECT_EQ(packet_in.bbox, packet2.bbox);
    EXPECT_EQ(packet_in.confidence, packet2.confidence);
    EXPECT_EQ(packet_in.target_range, packet2.target_range);
    EXPECT_EQ(packet_in.target_relative_vector, packet2.target_relative_vector);
    EXPECT_EQ(packet_in.threat_level, packet2.threat_level);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(sense, SENSE_STATE_VECTOR)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::sense::msg::SENSE_STATE_VECTOR packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.target_system = 149;
    packet_in.target_component = 216;
    packet_in.longitude = 963497880;
    packet_in.latitude = 963498088;
    packet_in.altitude = 963498296;
    packet_in.quaternion = {{ 157.0, 158.0, 159.0, 160.0 }};
    packet_in.roll = 269.0;
    packet_in.pitch = 297.0;
    packet_in.yaw = 325.0;

    mavlink::sense::msg::SENSE_STATE_VECTOR packet1{};
    mavlink::sense::msg::SENSE_STATE_VECTOR packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.longitude, packet2.longitude);
    EXPECT_EQ(packet1.latitude, packet2.latitude);
    EXPECT_EQ(packet1.altitude, packet2.altitude);
    EXPECT_EQ(packet1.quaternion, packet2.quaternion);
    EXPECT_EQ(packet1.roll, packet2.roll);
    EXPECT_EQ(packet1.pitch, packet2.pitch);
    EXPECT_EQ(packet1.yaw, packet2.yaw);
}

#ifdef TEST_INTEROP
TEST(sense_interop, SENSE_STATE_VECTOR)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sense_state_vector_t packet_c {
         93372036854775807ULL, 963497880, 963498088, 963498296, { 157.0, 158.0, 159.0, 160.0 }, 269.0, 297.0, 325.0, 149, 216
    };

    mavlink::sense::msg::SENSE_STATE_VECTOR packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.target_system = 149;
    packet_in.target_component = 216;
    packet_in.longitude = 963497880;
    packet_in.latitude = 963498088;
    packet_in.altitude = 963498296;
    packet_in.quaternion = {{ 157.0, 158.0, 159.0, 160.0 }};
    packet_in.roll = 269.0;
    packet_in.pitch = 297.0;
    packet_in.yaw = 325.0;

    mavlink::sense::msg::SENSE_STATE_VECTOR packet2{};

    mavlink_msg_sense_state_vector_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.longitude, packet2.longitude);
    EXPECT_EQ(packet_in.latitude, packet2.latitude);
    EXPECT_EQ(packet_in.altitude, packet2.altitude);
    EXPECT_EQ(packet_in.quaternion, packet2.quaternion);
    EXPECT_EQ(packet_in.roll, packet2.roll);
    EXPECT_EQ(packet_in.pitch, packet2.pitch);
    EXPECT_EQ(packet_in.yaw, packet2.yaw);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(sense, SENSE_AV_MAN)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::sense::msg::SENSE_AV_MAN packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.target_system = 209;
    packet_in.target_component = 20;
    packet_in.waypoint_x = {{ 73.0, 74.0, 75.0, 76.0, 77.0 }};
    packet_in.waypoint_y = {{ 213.0, 214.0, 215.0, 216.0, 217.0 }};
    packet_in.waypoint_z = {{ 353.0, 354.0, 355.0, 356.0, 357.0 }};

    mavlink::sense::msg::SENSE_AV_MAN packet1{};
    mavlink::sense::msg::SENSE_AV_MAN packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.target_component, packet2.target_component);
    EXPECT_EQ(packet1.waypoint_x, packet2.waypoint_x);
    EXPECT_EQ(packet1.waypoint_y, packet2.waypoint_y);
    EXPECT_EQ(packet1.waypoint_z, packet2.waypoint_z);
}

#ifdef TEST_INTEROP
TEST(sense_interop, SENSE_AV_MAN)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_sense_av_man_t packet_c {
         93372036854775807ULL, { 73.0, 74.0, 75.0, 76.0, 77.0 }, { 213.0, 214.0, 215.0, 216.0, 217.0 }, { 353.0, 354.0, 355.0, 356.0, 357.0 }, 209, 20
    };

    mavlink::sense::msg::SENSE_AV_MAN packet_in{};
    packet_in.time_unix_usec = 93372036854775807ULL;
    packet_in.target_system = 209;
    packet_in.target_component = 20;
    packet_in.waypoint_x = {{ 73.0, 74.0, 75.0, 76.0, 77.0 }};
    packet_in.waypoint_y = {{ 213.0, 214.0, 215.0, 216.0, 217.0 }};
    packet_in.waypoint_z = {{ 353.0, 354.0, 355.0, 356.0, 357.0 }};

    mavlink::sense::msg::SENSE_AV_MAN packet2{};

    mavlink_msg_sense_av_man_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_unix_usec, packet2.time_unix_usec);
    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.target_component, packet2.target_component);
    EXPECT_EQ(packet_in.waypoint_x, packet2.waypoint_x);
    EXPECT_EQ(packet_in.waypoint_y, packet2.waypoint_y);
    EXPECT_EQ(packet_in.waypoint_z, packet2.waypoint_z);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
