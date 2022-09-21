#pragma once
// MESSAGE SENSE_AR PACKING

#define MAVLINK_MSG_ID_SENSE_AR 50002


typedef struct __mavlink_sense_ar_t {
 uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time).*/
 uint8_t request; /*<  Request flag*/
 uint8_t maneuver_type; /*<  See the MANEUVER_TYPE enum.*/
} mavlink_sense_ar_t;

#define MAVLINK_MSG_ID_SENSE_AR_LEN 10
#define MAVLINK_MSG_ID_SENSE_AR_MIN_LEN 10
#define MAVLINK_MSG_ID_50002_LEN 10
#define MAVLINK_MSG_ID_50002_MIN_LEN 10

#define MAVLINK_MSG_ID_SENSE_AR_CRC 224
#define MAVLINK_MSG_ID_50002_CRC 224



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSE_AR { \
    50002, \
    "SENSE_AR", \
    3, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_ar_t, time_unix_usec) }, \
         { "request", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_sense_ar_t, request) }, \
         { "maneuver_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_sense_ar_t, maneuver_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSE_AR { \
    "SENSE_AR", \
    3, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_ar_t, time_unix_usec) }, \
         { "request", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_sense_ar_t, request) }, \
         { "maneuver_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_sense_ar_t, maneuver_type) }, \
         } \
}
#endif

/**
 * @brief Pack a sense_ar message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param request  Request flag
 * @param maneuver_type  See the MANEUVER_TYPE enum.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_ar_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_unix_usec, uint8_t request, uint8_t maneuver_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_AR_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 8, request);
    _mav_put_uint8_t(buf, 9, maneuver_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_AR_LEN);
#else
    mavlink_sense_ar_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.request = request;
    packet.maneuver_type = maneuver_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_AR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_AR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSE_AR_MIN_LEN, MAVLINK_MSG_ID_SENSE_AR_LEN, MAVLINK_MSG_ID_SENSE_AR_CRC);
}

/**
 * @brief Pack a sense_ar message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param request  Request flag
 * @param maneuver_type  See the MANEUVER_TYPE enum.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_ar_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_unix_usec,uint8_t request,uint8_t maneuver_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_AR_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 8, request);
    _mav_put_uint8_t(buf, 9, maneuver_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_AR_LEN);
#else
    mavlink_sense_ar_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.request = request;
    packet.maneuver_type = maneuver_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_AR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_AR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSE_AR_MIN_LEN, MAVLINK_MSG_ID_SENSE_AR_LEN, MAVLINK_MSG_ID_SENSE_AR_CRC);
}

/**
 * @brief Encode a sense_ar struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sense_ar C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_ar_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sense_ar_t* sense_ar)
{
    return mavlink_msg_sense_ar_pack(system_id, component_id, msg, sense_ar->time_unix_usec, sense_ar->request, sense_ar->maneuver_type);
}

/**
 * @brief Encode a sense_ar struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sense_ar C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_ar_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sense_ar_t* sense_ar)
{
    return mavlink_msg_sense_ar_pack_chan(system_id, component_id, chan, msg, sense_ar->time_unix_usec, sense_ar->request, sense_ar->maneuver_type);
}

/**
 * @brief Send a sense_ar message
 * @param chan MAVLink channel to send the message
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param request  Request flag
 * @param maneuver_type  See the MANEUVER_TYPE enum.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sense_ar_send(mavlink_channel_t chan, uint64_t time_unix_usec, uint8_t request, uint8_t maneuver_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_AR_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 8, request);
    _mav_put_uint8_t(buf, 9, maneuver_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AR, buf, MAVLINK_MSG_ID_SENSE_AR_MIN_LEN, MAVLINK_MSG_ID_SENSE_AR_LEN, MAVLINK_MSG_ID_SENSE_AR_CRC);
#else
    mavlink_sense_ar_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.request = request;
    packet.maneuver_type = maneuver_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AR, (const char *)&packet, MAVLINK_MSG_ID_SENSE_AR_MIN_LEN, MAVLINK_MSG_ID_SENSE_AR_LEN, MAVLINK_MSG_ID_SENSE_AR_CRC);
#endif
}

/**
 * @brief Send a sense_ar message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sense_ar_send_struct(mavlink_channel_t chan, const mavlink_sense_ar_t* sense_ar)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sense_ar_send(chan, sense_ar->time_unix_usec, sense_ar->request, sense_ar->maneuver_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AR, (const char *)sense_ar, MAVLINK_MSG_ID_SENSE_AR_MIN_LEN, MAVLINK_MSG_ID_SENSE_AR_LEN, MAVLINK_MSG_ID_SENSE_AR_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSE_AR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sense_ar_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_unix_usec, uint8_t request, uint8_t maneuver_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint8_t(buf, 8, request);
    _mav_put_uint8_t(buf, 9, maneuver_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AR, buf, MAVLINK_MSG_ID_SENSE_AR_MIN_LEN, MAVLINK_MSG_ID_SENSE_AR_LEN, MAVLINK_MSG_ID_SENSE_AR_CRC);
#else
    mavlink_sense_ar_t *packet = (mavlink_sense_ar_t *)msgbuf;
    packet->time_unix_usec = time_unix_usec;
    packet->request = request;
    packet->maneuver_type = maneuver_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_AR, (const char *)packet, MAVLINK_MSG_ID_SENSE_AR_MIN_LEN, MAVLINK_MSG_ID_SENSE_AR_LEN, MAVLINK_MSG_ID_SENSE_AR_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSE_AR UNPACKING


/**
 * @brief Get field time_unix_usec from sense_ar message
 *
 * @return [us] Timestamp (UNIX epoch time).
 */
static inline uint64_t mavlink_msg_sense_ar_get_time_unix_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field request from sense_ar message
 *
 * @return  Request flag
 */
static inline uint8_t mavlink_msg_sense_ar_get_request(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field maneuver_type from sense_ar message
 *
 * @return  See the MANEUVER_TYPE enum.
 */
static inline uint8_t mavlink_msg_sense_ar_get_maneuver_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Decode a sense_ar message into a struct
 *
 * @param msg The message to decode
 * @param sense_ar C-struct to decode the message contents into
 */
static inline void mavlink_msg_sense_ar_decode(const mavlink_message_t* msg, mavlink_sense_ar_t* sense_ar)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sense_ar->time_unix_usec = mavlink_msg_sense_ar_get_time_unix_usec(msg);
    sense_ar->request = mavlink_msg_sense_ar_get_request(msg);
    sense_ar->maneuver_type = mavlink_msg_sense_ar_get_maneuver_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSE_AR_LEN? msg->len : MAVLINK_MSG_ID_SENSE_AR_LEN;
        memset(sense_ar, 0, MAVLINK_MSG_ID_SENSE_AR_LEN);
    memcpy(sense_ar, _MAV_PAYLOAD(msg), len);
#endif
}
