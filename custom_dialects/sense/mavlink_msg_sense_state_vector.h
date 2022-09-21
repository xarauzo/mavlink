#pragma once
// MESSAGE SENSE_STATE_VECTOR PACKING

#define MAVLINK_MSG_ID_SENSE_STATE_VECTOR 50004


typedef struct __mavlink_sense_state_vector_t {
 uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time).*/
 uint32_t longitude; /*< [degE7] Longitude*/
 uint32_t latitude; /*< [degE7] Geodetic Latitude*/
 uint32_t altitude; /*< [degE7] Ellipsoidal Altitude*/
 float quaternion[4]; /*<  Quaternion defining UAS orientation.*/
 float roll; /*< [rad] Roll attitude angle.*/
 float pitch; /*< [rad] Pitch attitude angle.*/
 float yaw; /*< [rad] Yaw attitude angle.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_sense_state_vector_t;

#define MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN 50
#define MAVLINK_MSG_ID_SENSE_STATE_VECTOR_MIN_LEN 50
#define MAVLINK_MSG_ID_50004_LEN 50
#define MAVLINK_MSG_ID_50004_MIN_LEN 50

#define MAVLINK_MSG_ID_SENSE_STATE_VECTOR_CRC 59
#define MAVLINK_MSG_ID_50004_CRC 59

#define MAVLINK_MSG_SENSE_STATE_VECTOR_FIELD_QUATERNION_LEN 4

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSE_STATE_VECTOR { \
    50004, \
    "SENSE_STATE_VECTOR", \
    10, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_state_vector_t, time_unix_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_sense_state_vector_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_sense_state_vector_t, target_component) }, \
         { "longitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sense_state_vector_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_sense_state_vector_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_sense_state_vector_t, altitude) }, \
         { "quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 20, offsetof(mavlink_sense_state_vector_t, quaternion) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sense_state_vector_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sense_state_vector_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sense_state_vector_t, yaw) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSE_STATE_VECTOR { \
    "SENSE_STATE_VECTOR", \
    10, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_state_vector_t, time_unix_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 48, offsetof(mavlink_sense_state_vector_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 49, offsetof(mavlink_sense_state_vector_t, target_component) }, \
         { "longitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sense_state_vector_t, longitude) }, \
         { "latitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_sense_state_vector_t, latitude) }, \
         { "altitude", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_sense_state_vector_t, altitude) }, \
         { "quaternion", NULL, MAVLINK_TYPE_FLOAT, 4, 20, offsetof(mavlink_sense_state_vector_t, quaternion) }, \
         { "roll", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_sense_state_vector_t, roll) }, \
         { "pitch", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_sense_state_vector_t, pitch) }, \
         { "yaw", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_sense_state_vector_t, yaw) }, \
         } \
}
#endif

/**
 * @brief Pack a sense_state_vector message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param longitude [degE7] Longitude
 * @param latitude [degE7] Geodetic Latitude
 * @param altitude [degE7] Ellipsoidal Altitude
 * @param quaternion  Quaternion defining UAS orientation.
 * @param roll [rad] Roll attitude angle.
 * @param pitch [rad] Pitch attitude angle.
 * @param yaw [rad] Yaw attitude angle.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_state_vector_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, uint32_t longitude, uint32_t latitude, uint32_t altitude, const float *quaternion, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, longitude);
    _mav_put_uint32_t(buf, 12, latitude);
    _mav_put_uint32_t(buf, 16, altitude);
    _mav_put_float(buf, 36, roll);
    _mav_put_float(buf, 40, pitch);
    _mav_put_float(buf, 44, yaw);
    _mav_put_uint8_t(buf, 48, target_system);
    _mav_put_uint8_t(buf, 49, target_component);
    _mav_put_float_array(buf, 20, quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN);
#else
    mavlink_sense_state_vector_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_STATE_VECTOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_MIN_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_CRC);
}

/**
 * @brief Pack a sense_state_vector message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param longitude [degE7] Longitude
 * @param latitude [degE7] Geodetic Latitude
 * @param altitude [degE7] Ellipsoidal Altitude
 * @param quaternion  Quaternion defining UAS orientation.
 * @param roll [rad] Roll attitude angle.
 * @param pitch [rad] Pitch attitude angle.
 * @param yaw [rad] Yaw attitude angle.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_state_vector_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_unix_usec,uint8_t target_system,uint8_t target_component,uint32_t longitude,uint32_t latitude,uint32_t altitude,const float *quaternion,float roll,float pitch,float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, longitude);
    _mav_put_uint32_t(buf, 12, latitude);
    _mav_put_uint32_t(buf, 16, altitude);
    _mav_put_float(buf, 36, roll);
    _mav_put_float(buf, 40, pitch);
    _mav_put_float(buf, 44, yaw);
    _mav_put_uint8_t(buf, 48, target_system);
    _mav_put_uint8_t(buf, 49, target_component);
    _mav_put_float_array(buf, 20, quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN);
#else
    mavlink_sense_state_vector_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_STATE_VECTOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_MIN_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_CRC);
}

/**
 * @brief Encode a sense_state_vector struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sense_state_vector C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_state_vector_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sense_state_vector_t* sense_state_vector)
{
    return mavlink_msg_sense_state_vector_pack(system_id, component_id, msg, sense_state_vector->time_unix_usec, sense_state_vector->target_system, sense_state_vector->target_component, sense_state_vector->longitude, sense_state_vector->latitude, sense_state_vector->altitude, sense_state_vector->quaternion, sense_state_vector->roll, sense_state_vector->pitch, sense_state_vector->yaw);
}

/**
 * @brief Encode a sense_state_vector struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sense_state_vector C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_state_vector_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sense_state_vector_t* sense_state_vector)
{
    return mavlink_msg_sense_state_vector_pack_chan(system_id, component_id, chan, msg, sense_state_vector->time_unix_usec, sense_state_vector->target_system, sense_state_vector->target_component, sense_state_vector->longitude, sense_state_vector->latitude, sense_state_vector->altitude, sense_state_vector->quaternion, sense_state_vector->roll, sense_state_vector->pitch, sense_state_vector->yaw);
}

/**
 * @brief Send a sense_state_vector message
 * @param chan MAVLink channel to send the message
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param longitude [degE7] Longitude
 * @param latitude [degE7] Geodetic Latitude
 * @param altitude [degE7] Ellipsoidal Altitude
 * @param quaternion  Quaternion defining UAS orientation.
 * @param roll [rad] Roll attitude angle.
 * @param pitch [rad] Pitch attitude angle.
 * @param yaw [rad] Yaw attitude angle.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sense_state_vector_send(mavlink_channel_t chan, uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, uint32_t longitude, uint32_t latitude, uint32_t altitude, const float *quaternion, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, longitude);
    _mav_put_uint32_t(buf, 12, latitude);
    _mav_put_uint32_t(buf, 16, altitude);
    _mav_put_float(buf, 36, roll);
    _mav_put_float(buf, 40, pitch);
    _mav_put_float(buf, 44, yaw);
    _mav_put_uint8_t(buf, 48, target_system);
    _mav_put_uint8_t(buf, 49, target_component);
    _mav_put_float_array(buf, 20, quaternion, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_STATE_VECTOR, buf, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_MIN_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_CRC);
#else
    mavlink_sense_state_vector_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.longitude = longitude;
    packet.latitude = latitude;
    packet.altitude = altitude;
    packet.roll = roll;
    packet.pitch = pitch;
    packet.yaw = yaw;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.quaternion, quaternion, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_STATE_VECTOR, (const char *)&packet, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_MIN_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_CRC);
#endif
}

/**
 * @brief Send a sense_state_vector message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sense_state_vector_send_struct(mavlink_channel_t chan, const mavlink_sense_state_vector_t* sense_state_vector)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sense_state_vector_send(chan, sense_state_vector->time_unix_usec, sense_state_vector->target_system, sense_state_vector->target_component, sense_state_vector->longitude, sense_state_vector->latitude, sense_state_vector->altitude, sense_state_vector->quaternion, sense_state_vector->roll, sense_state_vector->pitch, sense_state_vector->yaw);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_STATE_VECTOR, (const char *)sense_state_vector, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_MIN_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sense_state_vector_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, uint32_t longitude, uint32_t latitude, uint32_t altitude, const float *quaternion, float roll, float pitch, float yaw)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, longitude);
    _mav_put_uint32_t(buf, 12, latitude);
    _mav_put_uint32_t(buf, 16, altitude);
    _mav_put_float(buf, 36, roll);
    _mav_put_float(buf, 40, pitch);
    _mav_put_float(buf, 44, yaw);
    _mav_put_uint8_t(buf, 48, target_system);
    _mav_put_uint8_t(buf, 49, target_component);
    _mav_put_float_array(buf, 20, quaternion, 4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_STATE_VECTOR, buf, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_MIN_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_CRC);
#else
    mavlink_sense_state_vector_t *packet = (mavlink_sense_state_vector_t *)msgbuf;
    packet->time_unix_usec = time_unix_usec;
    packet->longitude = longitude;
    packet->latitude = latitude;
    packet->altitude = altitude;
    packet->roll = roll;
    packet->pitch = pitch;
    packet->yaw = yaw;
    packet->target_system = target_system;
    packet->target_component = target_component;
    mav_array_memcpy(packet->quaternion, quaternion, sizeof(float)*4);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_STATE_VECTOR, (const char *)packet, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_MIN_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSE_STATE_VECTOR UNPACKING


/**
 * @brief Get field time_unix_usec from sense_state_vector message
 *
 * @return [us] Timestamp (UNIX epoch time).
 */
static inline uint64_t mavlink_msg_sense_state_vector_get_time_unix_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from sense_state_vector message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_sense_state_vector_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  48);
}

/**
 * @brief Get field target_component from sense_state_vector message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_sense_state_vector_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  49);
}

/**
 * @brief Get field longitude from sense_state_vector message
 *
 * @return [degE7] Longitude
 */
static inline uint32_t mavlink_msg_sense_state_vector_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field latitude from sense_state_vector message
 *
 * @return [degE7] Geodetic Latitude
 */
static inline uint32_t mavlink_msg_sense_state_vector_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field altitude from sense_state_vector message
 *
 * @return [degE7] Ellipsoidal Altitude
 */
static inline uint32_t mavlink_msg_sense_state_vector_get_altitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field quaternion from sense_state_vector message
 *
 * @return  Quaternion defining UAS orientation.
 */
static inline uint16_t mavlink_msg_sense_state_vector_get_quaternion(const mavlink_message_t* msg, float *quaternion)
{
    return _MAV_RETURN_float_array(msg, quaternion, 4,  20);
}

/**
 * @brief Get field roll from sense_state_vector message
 *
 * @return [rad] Roll attitude angle.
 */
static inline float mavlink_msg_sense_state_vector_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field pitch from sense_state_vector message
 *
 * @return [rad] Pitch attitude angle.
 */
static inline float mavlink_msg_sense_state_vector_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field yaw from sense_state_vector message
 *
 * @return [rad] Yaw attitude angle.
 */
static inline float mavlink_msg_sense_state_vector_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Decode a sense_state_vector message into a struct
 *
 * @param msg The message to decode
 * @param sense_state_vector C-struct to decode the message contents into
 */
static inline void mavlink_msg_sense_state_vector_decode(const mavlink_message_t* msg, mavlink_sense_state_vector_t* sense_state_vector)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sense_state_vector->time_unix_usec = mavlink_msg_sense_state_vector_get_time_unix_usec(msg);
    sense_state_vector->longitude = mavlink_msg_sense_state_vector_get_longitude(msg);
    sense_state_vector->latitude = mavlink_msg_sense_state_vector_get_latitude(msg);
    sense_state_vector->altitude = mavlink_msg_sense_state_vector_get_altitude(msg);
    mavlink_msg_sense_state_vector_get_quaternion(msg, sense_state_vector->quaternion);
    sense_state_vector->roll = mavlink_msg_sense_state_vector_get_roll(msg);
    sense_state_vector->pitch = mavlink_msg_sense_state_vector_get_pitch(msg);
    sense_state_vector->yaw = mavlink_msg_sense_state_vector_get_yaw(msg);
    sense_state_vector->target_system = mavlink_msg_sense_state_vector_get_target_system(msg);
    sense_state_vector->target_component = mavlink_msg_sense_state_vector_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN? msg->len : MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN;
        memset(sense_state_vector, 0, MAVLINK_MSG_ID_SENSE_STATE_VECTOR_LEN);
    memcpy(sense_state_vector, _MAV_PAYLOAD(msg), len);
#endif
}
