#pragma once
// MESSAGE SENSE_TIME PACKING

#define MAVLINK_MSG_ID_SENSE_TIME 50001


typedef struct __mavlink_sense_time_t {
 uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time).*/
 uint8_t status; /*<  See the SENSE_STATE enum.*/
} mavlink_sense_time_t;

#define MAVLINK_MSG_ID_SENSE_TIME_LEN 9
#define MAVLINK_MSG_ID_SENSE_TIME_MIN_LEN 9
#define MAVLINK_MSG_ID_50001_LEN 9
#define MAVLINK_MSG_ID_50001_MIN_LEN 9

#define MAVLINK_MSG_ID_SENSE_TIME_CRC 241
#define MAVLINK_MSG_ID_50001_CRC 241



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSE_TIME { \
    50001, \
    "SENSE_TIME", \
    2, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_time_t, time_unix_usec) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_sense_time_t, status) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSE_TIME { \
    "SENSE_TIME", \
    2, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_time_t, time_unix_usec) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_sense_time_t, status) }, \
         } \
}
#endif

/**
 * @brief Pack a sense_time message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param status  See the SENSE_STATE enum.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_time_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_unix_usec, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_TIME_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 8, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_TIME_LEN);
#else
    mavlink_sense_time_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_TIME_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_TIME;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSE_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSE_TIME_LEN, MAVLINK_MSG_ID_SENSE_TIME_CRC);
}

/**
 * @brief Pack a sense_time message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param status  See the SENSE_STATE enum.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_time_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_unix_usec,uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_TIME_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 8, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_TIME_LEN);
#else
    mavlink_sense_time_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_TIME_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_TIME;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSE_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSE_TIME_LEN, MAVLINK_MSG_ID_SENSE_TIME_CRC);
}

/**
 * @brief Encode a sense_time struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sense_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_time_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sense_time_t* sense_time)
{
    return mavlink_msg_sense_time_pack(system_id, component_id, msg, sense_time->time_unix_usec, sense_time->status);
}

/**
 * @brief Encode a sense_time struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sense_time C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_time_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sense_time_t* sense_time)
{
    return mavlink_msg_sense_time_pack_chan(system_id, component_id, chan, msg, sense_time->time_unix_usec, sense_time->status);
}

/**
 * @brief Send a sense_time message
 * @param chan MAVLink channel to send the message
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param status  See the SENSE_STATE enum.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sense_time_send(mavlink_channel_t chan, uint64_t time_unix_usec, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_TIME_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 8, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_TIME, buf, MAVLINK_MSG_ID_SENSE_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSE_TIME_LEN, MAVLINK_MSG_ID_SENSE_TIME_CRC);
#else
    mavlink_sense_time_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_TIME, (const char *)&packet, MAVLINK_MSG_ID_SENSE_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSE_TIME_LEN, MAVLINK_MSG_ID_SENSE_TIME_CRC);
#endif
}

/**
 * @brief Send a sense_time message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sense_time_send_struct(mavlink_channel_t chan, const mavlink_sense_time_t* sense_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sense_time_send(chan, sense_time->time_unix_usec, sense_time->status);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_TIME, (const char *)sense_time, MAVLINK_MSG_ID_SENSE_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSE_TIME_LEN, MAVLINK_MSG_ID_SENSE_TIME_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSE_TIME_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sense_time_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_unix_usec, uint8_t status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 8, status);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_TIME, buf, MAVLINK_MSG_ID_SENSE_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSE_TIME_LEN, MAVLINK_MSG_ID_SENSE_TIME_CRC);
#else
    mavlink_sense_time_t *packet = (mavlink_sense_time_t *)msgbuf;
    packet->time_unix_usec = time_unix_usec;
    packet->status = status;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_TIME, (const char *)packet, MAVLINK_MSG_ID_SENSE_TIME_MIN_LEN, MAVLINK_MSG_ID_SENSE_TIME_LEN, MAVLINK_MSG_ID_SENSE_TIME_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSE_TIME UNPACKING


/**
 * @brief Get field time_unix_usec from sense_time message
 *
 * @return [us] Timestamp (UNIX epoch time).
 */
static inline uint64_t mavlink_msg_sense_time_get_time_unix_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field status from sense_time message
 *
 * @return  See the SENSE_STATE enum.
 */
static inline uint8_t mavlink_msg_sense_time_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Decode a sense_time message into a struct
 *
 * @param msg The message to decode
 * @param sense_time C-struct to decode the message contents into
 */
static inline void mavlink_msg_sense_time_decode(const mavlink_message_t* msg, mavlink_sense_time_t* sense_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sense_time->time_unix_usec = mavlink_msg_sense_time_get_time_unix_usec(msg);
    sense_time->status = mavlink_msg_sense_time_get_status(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSE_TIME_LEN? msg->len : MAVLINK_MSG_ID_SENSE_TIME_LEN;
        memset(sense_time, 0, MAVLINK_MSG_ID_SENSE_TIME_LEN);
    memcpy(sense_time, _MAV_PAYLOAD(msg), len);
#endif
}
