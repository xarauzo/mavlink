#pragma once
// MESSAGE SENSE_AV_MAN PACKING

#define MAVLINK_MSG_ID_SENSE_AV_MAN 50005


typedef struct __mavlink_sense_av_man_t {
 uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time).*/
 float waypoint_x[5]; /*< [degE7] X-coordinate of waypoint in sphericals state type (Longitude)*/
 float waypoint_y[5]; /*< [degE7] Y-coordinate of waypoint in sphericals state type (Latitude)*/
 float waypoint_z[5]; /*< [degE7] Z-coordinate of waypoint in sphericals state type (Altitude)*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_sense_av_man_t;

#define MAVLINK_MSG_ID_SENSE_AV_MAN_LEN 70
#define MAVLINK_MSG_ID_SENSE_AV_MAN_MIN_LEN 70
#define MAVLINK_MSG_ID_50005_LEN 70
#define MAVLINK_MSG_ID_50005_MIN_LEN 70

#define MAVLINK_MSG_ID_SENSE_AV_MAN_CRC 198
#define MAVLINK_MSG_ID_50005_CRC 198

#define MAVLINK_MSG_SENSE_AV_MAN_FIELD_WAYPOINT_X_LEN 5
#define MAVLINK_MSG_SENSE_AV_MAN_FIELD_WAYPOINT_Y_LEN 5
#define MAVLINK_MSG_SENSE_AV_MAN_FIELD_WAYPOINT_Z_LEN 5

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSE_AV_MAN { \
    50005, \
    "SENSE_AV_MAN", \
    6, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_av_man_t, time_unix_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_sense_av_man_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 69, offsetof(mavlink_sense_av_man_t, target_component) }, \
         { "waypoint_x", NULL, MAVLINK_TYPE_FLOAT, 5, 8, offsetof(mavlink_sense_av_man_t, waypoint_x) }, \
         { "waypoint_y", NULL, MAVLINK_TYPE_FLOAT, 5, 28, offsetof(mavlink_sense_av_man_t, waypoint_y) }, \
         { "waypoint_z", NULL, MAVLINK_TYPE_FLOAT, 5, 48, offsetof(mavlink_sense_av_man_t, waypoint_z) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSE_AV_MAN { \
    "SENSE_AV_MAN", \
    6, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_av_man_t, time_unix_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 68, offsetof(mavlink_sense_av_man_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 69, offsetof(mavlink_sense_av_man_t, target_component) }, \
         { "waypoint_x", NULL, MAVLINK_TYPE_FLOAT, 5, 8, offsetof(mavlink_sense_av_man_t, waypoint_x) }, \
         { "waypoint_y", NULL, MAVLINK_TYPE_FLOAT, 5, 28, offsetof(mavlink_sense_av_man_t, waypoint_y) }, \
         { "waypoint_z", NULL, MAVLINK_TYPE_FLOAT, 5, 48, offsetof(mavlink_sense_av_man_t, waypoint_z) }, \
         } \
}
#endif

/**
 * @brief Pack a sense_av_man message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param waypoint_x [degE7] X-coordinate of waypoint in sphericals state type (Longitude)
 * @param waypoint_y [degE7] Y-coordinate of waypoint in sphericals state type (Latitude)
 * @param waypoint_z [degE7] Z-coordinate of waypoint in sphericals state type (Altitude)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_av_man_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, const float *waypoint_x, const float *waypoint_y, const float *waypoint_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_AV_MAN_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 68, target_system);
    _mav_put_uint8_t(buf, 69, target_component);
    _mav_put_float_array(buf, 8, waypoint_x, 5);
    _mav_put_float_array(buf, 28, waypoint_y, 5);
    _mav_put_float_array(buf, 48, waypoint_z, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN);
#else
    mavlink_sense_av_man_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.waypoint_x, waypoint_x, sizeof(float)*5);
    mav_array_memcpy(packet.waypoint_y, waypoint_y, sizeof(float)*5);
    mav_array_memcpy(packet.waypoint_z, waypoint_z, sizeof(float)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_AV_MAN;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSE_AV_MAN_MIN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_CRC);
}

/**
 * @brief Pack a sense_av_man message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param waypoint_x [degE7] X-coordinate of waypoint in sphericals state type (Longitude)
 * @param waypoint_y [degE7] Y-coordinate of waypoint in sphericals state type (Latitude)
 * @param waypoint_z [degE7] Z-coordinate of waypoint in sphericals state type (Altitude)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_av_man_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_unix_usec,uint8_t target_system,uint8_t target_component,const float *waypoint_x,const float *waypoint_y,const float *waypoint_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_AV_MAN_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 68, target_system);
    _mav_put_uint8_t(buf, 69, target_component);
    _mav_put_float_array(buf, 8, waypoint_x, 5);
    _mav_put_float_array(buf, 28, waypoint_y, 5);
    _mav_put_float_array(buf, 48, waypoint_z, 5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN);
#else
    mavlink_sense_av_man_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.waypoint_x, waypoint_x, sizeof(float)*5);
    mav_array_memcpy(packet.waypoint_y, waypoint_y, sizeof(float)*5);
    mav_array_memcpy(packet.waypoint_z, waypoint_z, sizeof(float)*5);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_AV_MAN;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSE_AV_MAN_MIN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_CRC);
}

/**
 * @brief Encode a sense_av_man struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sense_av_man C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_av_man_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sense_av_man_t* sense_av_man)
{
    return mavlink_msg_sense_av_man_pack(system_id, component_id, msg, sense_av_man->time_unix_usec, sense_av_man->target_system, sense_av_man->target_component, sense_av_man->waypoint_x, sense_av_man->waypoint_y, sense_av_man->waypoint_z);
}

/**
 * @brief Encode a sense_av_man struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sense_av_man C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_av_man_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sense_av_man_t* sense_av_man)
{
    return mavlink_msg_sense_av_man_pack_chan(system_id, component_id, chan, msg, sense_av_man->time_unix_usec, sense_av_man->target_system, sense_av_man->target_component, sense_av_man->waypoint_x, sense_av_man->waypoint_y, sense_av_man->waypoint_z);
}

/**
 * @brief Send a sense_av_man message
 * @param chan MAVLink channel to send the message
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param waypoint_x [degE7] X-coordinate of waypoint in sphericals state type (Longitude)
 * @param waypoint_y [degE7] Y-coordinate of waypoint in sphericals state type (Latitude)
 * @param waypoint_z [degE7] Z-coordinate of waypoint in sphericals state type (Altitude)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sense_av_man_send(mavlink_channel_t chan, uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, const float *waypoint_x, const float *waypoint_y, const float *waypoint_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_AV_MAN_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 68, target_system);
    _mav_put_uint8_t(buf, 69, target_component);
    _mav_put_float_array(buf, 8, waypoint_x, 5);
    _mav_put_float_array(buf, 28, waypoint_y, 5);
    _mav_put_float_array(buf, 48, waypoint_z, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AV_MAN, buf, MAVLINK_MSG_ID_SENSE_AV_MAN_MIN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_CRC);
#else
    mavlink_sense_av_man_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.waypoint_x, waypoint_x, sizeof(float)*5);
    mav_array_memcpy(packet.waypoint_y, waypoint_y, sizeof(float)*5);
    mav_array_memcpy(packet.waypoint_z, waypoint_z, sizeof(float)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AV_MAN, (const char *)&packet, MAVLINK_MSG_ID_SENSE_AV_MAN_MIN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_CRC);
#endif
}

/**
 * @brief Send a sense_av_man message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sense_av_man_send_struct(mavlink_channel_t chan, const mavlink_sense_av_man_t* sense_av_man)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sense_av_man_send(chan, sense_av_man->time_unix_usec, sense_av_man->target_system, sense_av_man->target_component, sense_av_man->waypoint_x, sense_av_man->waypoint_y, sense_av_man->waypoint_z);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AV_MAN, (const char *)sense_av_man, MAVLINK_MSG_ID_SENSE_AV_MAN_MIN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSE_AV_MAN_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sense_av_man_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, const float *waypoint_x, const float *waypoint_y, const float *waypoint_z)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 68, target_system);
    _mav_put_uint8_t(buf, 69, target_component);
    _mav_put_float_array(buf, 8, waypoint_x, 5);
    _mav_put_float_array(buf, 28, waypoint_y, 5);
    _mav_put_float_array(buf, 48, waypoint_z, 5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AV_MAN, buf, MAVLINK_MSG_ID_SENSE_AV_MAN_MIN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_CRC);
#else
    mavlink_sense_av_man_t *packet = (mavlink_sense_av_man_t *)msgbuf;
    packet->time_unix_usec = time_unix_usec;
    packet->target_system = target_system;
    packet->target_component = target_component;
    mav_array_memcpy(packet->waypoint_x, waypoint_x, sizeof(float)*5);
    mav_array_memcpy(packet->waypoint_y, waypoint_y, sizeof(float)*5);
    mav_array_memcpy(packet->waypoint_z, waypoint_z, sizeof(float)*5);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AV_MAN, (const char *)packet, MAVLINK_MSG_ID_SENSE_AV_MAN_MIN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN, MAVLINK_MSG_ID_SENSE_AV_MAN_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSE_AV_MAN UNPACKING


/**
 * @brief Get field time_unix_usec from sense_av_man message
 *
 * @return [us] Timestamp (UNIX epoch time).
 */
static inline uint64_t mavlink_msg_sense_av_man_get_time_unix_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from sense_av_man message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_sense_av_man_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  68);
}

/**
 * @brief Get field target_component from sense_av_man message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_sense_av_man_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  69);
}

/**
 * @brief Get field waypoint_x from sense_av_man message
 *
 * @return [degE7] X-coordinate of waypoint in sphericals state type (Longitude)
 */
static inline uint16_t mavlink_msg_sense_av_man_get_waypoint_x(const mavlink_message_t* msg, float *waypoint_x)
{
    return _MAV_RETURN_float_array(msg, waypoint_x, 5,  8);
}

/**
 * @brief Get field waypoint_y from sense_av_man message
 *
 * @return [degE7] Y-coordinate of waypoint in sphericals state type (Latitude)
 */
static inline uint16_t mavlink_msg_sense_av_man_get_waypoint_y(const mavlink_message_t* msg, float *waypoint_y)
{
    return _MAV_RETURN_float_array(msg, waypoint_y, 5,  28);
}

/**
 * @brief Get field waypoint_z from sense_av_man message
 *
 * @return [degE7] Z-coordinate of waypoint in sphericals state type (Altitude)
 */
static inline uint16_t mavlink_msg_sense_av_man_get_waypoint_z(const mavlink_message_t* msg, float *waypoint_z)
{
    return _MAV_RETURN_float_array(msg, waypoint_z, 5,  48);
}

/**
 * @brief Decode a sense_av_man message into a struct
 *
 * @param msg The message to decode
 * @param sense_av_man C-struct to decode the message contents into
 */
static inline void mavlink_msg_sense_av_man_decode(const mavlink_message_t* msg, mavlink_sense_av_man_t* sense_av_man)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sense_av_man->time_unix_usec = mavlink_msg_sense_av_man_get_time_unix_usec(msg);
    mavlink_msg_sense_av_man_get_waypoint_x(msg, sense_av_man->waypoint_x);
    mavlink_msg_sense_av_man_get_waypoint_y(msg, sense_av_man->waypoint_y);
    mavlink_msg_sense_av_man_get_waypoint_z(msg, sense_av_man->waypoint_z);
    sense_av_man->target_system = mavlink_msg_sense_av_man_get_target_system(msg);
    sense_av_man->target_component = mavlink_msg_sense_av_man_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSE_AV_MAN_LEN? msg->len : MAVLINK_MSG_ID_SENSE_AV_MAN_LEN;
        memset(sense_av_man, 0, MAVLINK_MSG_ID_SENSE_AV_MAN_LEN);
    memcpy(sense_av_man, _MAV_PAYLOAD(msg), len);
#endif
}
