#pragma once
// MESSAGE SENSE_DAA PACKING

#define MAVLINK_MSG_ID_SENSE_DAA 50003


typedef struct __mavlink_sense_daa_t {
 uint64_t time_unix_usec; /*< [us] Timestamp (UNIX epoch time).*/
 uint32_t frame_num; /*<  Frame number*/
 float bbox[4]; /*< [pix] Bounding Box dimensions [top, left, height, width].*/
 float confidence; /*< [%] Confidence (probability).*/
 float target_range; /*< [m] Estimated distance to detected target.*/
 float target_relative_vector[3]; /*< [m] Estimated relative vector to detected target, defined in camera axes.*/
 uint16_t tracker_id; /*<  Tracker ID*/
 uint16_t threat_level; /*<  Threat level for detected object.*/
 uint8_t target_system; /*<  System ID*/
 uint8_t target_component; /*<  Component ID*/
} mavlink_sense_daa_t;

#define MAVLINK_MSG_ID_SENSE_DAA_LEN 54
#define MAVLINK_MSG_ID_SENSE_DAA_MIN_LEN 54
#define MAVLINK_MSG_ID_50003_LEN 54
#define MAVLINK_MSG_ID_50003_MIN_LEN 54

#define MAVLINK_MSG_ID_SENSE_DAA_CRC 185
#define MAVLINK_MSG_ID_50003_CRC 185

#define MAVLINK_MSG_SENSE_DAA_FIELD_BBOX_LEN 4
#define MAVLINK_MSG_SENSE_DAA_FIELD_TARGET_RELATIVE_VECTOR_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSE_DAA { \
    50003, \
    "SENSE_DAA", \
    10, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_daa_t, time_unix_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_sense_daa_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_sense_daa_t, target_component) }, \
         { "frame_num", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sense_daa_t, frame_num) }, \
         { "tracker_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_sense_daa_t, tracker_id) }, \
         { "bbox", NULL, MAVLINK_TYPE_FLOAT, 4, 12, offsetof(mavlink_sense_daa_t, bbox) }, \
         { "confidence", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sense_daa_t, confidence) }, \
         { "target_range", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sense_daa_t, target_range) }, \
         { "target_relative_vector", NULL, MAVLINK_TYPE_FLOAT, 3, 36, offsetof(mavlink_sense_daa_t, target_relative_vector) }, \
         { "threat_level", NULL, MAVLINK_TYPE_UINT16_T, 0, 50, offsetof(mavlink_sense_daa_t, threat_level) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSE_DAA { \
    "SENSE_DAA", \
    10, \
    {  { "time_unix_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sense_daa_t, time_unix_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_sense_daa_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_sense_daa_t, target_component) }, \
         { "frame_num", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_sense_daa_t, frame_num) }, \
         { "tracker_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 48, offsetof(mavlink_sense_daa_t, tracker_id) }, \
         { "bbox", NULL, MAVLINK_TYPE_FLOAT, 4, 12, offsetof(mavlink_sense_daa_t, bbox) }, \
         { "confidence", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_sense_daa_t, confidence) }, \
         { "target_range", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_sense_daa_t, target_range) }, \
         { "target_relative_vector", NULL, MAVLINK_TYPE_FLOAT, 3, 36, offsetof(mavlink_sense_daa_t, target_relative_vector) }, \
         { "threat_level", NULL, MAVLINK_TYPE_UINT16_T, 0, 50, offsetof(mavlink_sense_daa_t, threat_level) }, \
         } \
}
#endif

/**
 * @brief Pack a sense_daa message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param frame_num  Frame number
 * @param tracker_id  Tracker ID
 * @param bbox [pix] Bounding Box dimensions [top, left, height, width].
 * @param confidence [%] Confidence (probability).
 * @param target_range [m] Estimated distance to detected target.
 * @param target_relative_vector [m] Estimated relative vector to detected target, defined in camera axes.
 * @param threat_level  Threat level for detected object.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_daa_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, uint32_t frame_num, uint16_t tracker_id, const float *bbox, float confidence, float target_range, const float *target_relative_vector, uint16_t threat_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_DAA_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, frame_num);
    _mav_put_float(buf, 28, confidence);
    _mav_put_float(buf, 32, target_range);
    _mav_put_uint16_t(buf, 48, tracker_id);
    _mav_put_uint16_t(buf, 50, threat_level);
    _mav_put_uint8_t(buf, 52, target_system);
    _mav_put_uint8_t(buf, 53, target_component);
    _mav_put_float_array(buf, 12, bbox, 4);
    _mav_put_float_array(buf, 36, target_relative_vector, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_DAA_LEN);
#else
    mavlink_sense_daa_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.frame_num = frame_num;
    packet.confidence = confidence;
    packet.target_range = target_range;
    packet.tracker_id = tracker_id;
    packet.threat_level = threat_level;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.bbox, bbox, sizeof(float)*4);
    mav_array_memcpy(packet.target_relative_vector, target_relative_vector, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_DAA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_DAA;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SENSE_DAA_MIN_LEN, MAVLINK_MSG_ID_SENSE_DAA_LEN, MAVLINK_MSG_ID_SENSE_DAA_CRC);
}

/**
 * @brief Pack a sense_daa message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param frame_num  Frame number
 * @param tracker_id  Tracker ID
 * @param bbox [pix] Bounding Box dimensions [top, left, height, width].
 * @param confidence [%] Confidence (probability).
 * @param target_range [m] Estimated distance to detected target.
 * @param target_relative_vector [m] Estimated relative vector to detected target, defined in camera axes.
 * @param threat_level  Threat level for detected object.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sense_daa_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_unix_usec,uint8_t target_system,uint8_t target_component,uint32_t frame_num,uint16_t tracker_id,const float *bbox,float confidence,float target_range,const float *target_relative_vector,uint16_t threat_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_DAA_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, frame_num);
    _mav_put_float(buf, 28, confidence);
    _mav_put_float(buf, 32, target_range);
    _mav_put_uint16_t(buf, 48, tracker_id);
    _mav_put_uint16_t(buf, 50, threat_level);
    _mav_put_uint8_t(buf, 52, target_system);
    _mav_put_uint8_t(buf, 53, target_component);
    _mav_put_float_array(buf, 12, bbox, 4);
    _mav_put_float_array(buf, 36, target_relative_vector, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSE_DAA_LEN);
#else
    mavlink_sense_daa_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.frame_num = frame_num;
    packet.confidence = confidence;
    packet.target_range = target_range;
    packet.tracker_id = tracker_id;
    packet.threat_level = threat_level;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.bbox, bbox, sizeof(float)*4);
    mav_array_memcpy(packet.target_relative_vector, target_relative_vector, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSE_DAA_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSE_DAA;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSE_DAA_MIN_LEN, MAVLINK_MSG_ID_SENSE_DAA_LEN, MAVLINK_MSG_ID_SENSE_DAA_CRC);
}

/**
 * @brief Encode a sense_daa struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sense_daa C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_daa_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sense_daa_t* sense_daa)
{
    return mavlink_msg_sense_daa_pack(system_id, component_id, msg, sense_daa->time_unix_usec, sense_daa->target_system, sense_daa->target_component, sense_daa->frame_num, sense_daa->tracker_id, sense_daa->bbox, sense_daa->confidence, sense_daa->target_range, sense_daa->target_relative_vector, sense_daa->threat_level);
}

/**
 * @brief Encode a sense_daa struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sense_daa C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sense_daa_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sense_daa_t* sense_daa)
{
    return mavlink_msg_sense_daa_pack_chan(system_id, component_id, chan, msg, sense_daa->time_unix_usec, sense_daa->target_system, sense_daa->target_component, sense_daa->frame_num, sense_daa->tracker_id, sense_daa->bbox, sense_daa->confidence, sense_daa->target_range, sense_daa->target_relative_vector, sense_daa->threat_level);
}

/**
 * @brief Send a sense_daa message
 * @param chan MAVLink channel to send the message
 *
 * @param time_unix_usec [us] Timestamp (UNIX epoch time).
 * @param target_system  System ID
 * @param target_component  Component ID
 * @param frame_num  Frame number
 * @param tracker_id  Tracker ID
 * @param bbox [pix] Bounding Box dimensions [top, left, height, width].
 * @param confidence [%] Confidence (probability).
 * @param target_range [m] Estimated distance to detected target.
 * @param target_relative_vector [m] Estimated relative vector to detected target, defined in camera axes.
 * @param threat_level  Threat level for detected object.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sense_daa_send(mavlink_channel_t chan, uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, uint32_t frame_num, uint16_t tracker_id, const float *bbox, float confidence, float target_range, const float *target_relative_vector, uint16_t threat_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSE_DAA_LEN];
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, frame_num);
    _mav_put_float(buf, 28, confidence);
    _mav_put_float(buf, 32, target_range);
    _mav_put_uint16_t(buf, 48, tracker_id);
    _mav_put_uint16_t(buf, 50, threat_level);
    _mav_put_uint8_t(buf, 52, target_system);
    _mav_put_uint8_t(buf, 53, target_component);
    _mav_put_float_array(buf, 12, bbox, 4);
    _mav_put_float_array(buf, 36, target_relative_vector, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_DAA, buf, MAVLINK_MSG_ID_SENSE_DAA_MIN_LEN, MAVLINK_MSG_ID_SENSE_DAA_LEN, MAVLINK_MSG_ID_SENSE_DAA_CRC);
#else
    mavlink_sense_daa_t packet;
    packet.time_unix_usec = time_unix_usec;
    packet.frame_num = frame_num;
    packet.confidence = confidence;
    packet.target_range = target_range;
    packet.tracker_id = tracker_id;
    packet.threat_level = threat_level;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.bbox, bbox, sizeof(float)*4);
    mav_array_memcpy(packet.target_relative_vector, target_relative_vector, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_DAA, (const char *)&packet, MAVLINK_MSG_ID_SENSE_DAA_MIN_LEN, MAVLINK_MSG_ID_SENSE_DAA_LEN, MAVLINK_MSG_ID_SENSE_DAA_CRC);
#endif
}

/**
 * @brief Send a sense_daa message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sense_daa_send_struct(mavlink_channel_t chan, const mavlink_sense_daa_t* sense_daa)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sense_daa_send(chan, sense_daa->time_unix_usec, sense_daa->target_system, sense_daa->target_component, sense_daa->frame_num, sense_daa->tracker_id, sense_daa->bbox, sense_daa->confidence, sense_daa->target_range, sense_daa->target_relative_vector, sense_daa->threat_level);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_DAA, (const char *)sense_daa, MAVLINK_MSG_ID_SENSE_DAA_MIN_LEN, MAVLINK_MSG_ID_SENSE_DAA_LEN, MAVLINK_MSG_ID_SENSE_DAA_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSE_DAA_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sense_daa_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_unix_usec, uint8_t target_system, uint8_t target_component, uint32_t frame_num, uint16_t tracker_id, const float *bbox, float confidence, float target_range, const float *target_relative_vector, uint16_t threat_level)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_unix_usec);
    _mav_put_uint32_t(buf, 8, frame_num);
    _mav_put_float(buf, 28, confidence);
    _mav_put_float(buf, 32, target_range);
    _mav_put_uint16_t(buf, 48, tracker_id);
    _mav_put_uint16_t(buf, 50, threat_level);
    _mav_put_uint8_t(buf, 52, target_system);
    _mav_put_uint8_t(buf, 53, target_component);
    _mav_put_float_array(buf, 12, bbox, 4);
    _mav_put_float_array(buf, 36, target_relative_vector, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_DAA, buf, MAVLINK_MSG_ID_SENSE_DAA_MIN_LEN, MAVLINK_MSG_ID_SENSE_DAA_LEN, MAVLINK_MSG_ID_SENSE_DAA_CRC);
#else
    mavlink_sense_daa_t *packet = (mavlink_sense_daa_t *)msgbuf;
    packet->time_unix_usec = time_unix_usec;
    packet->frame_num = frame_num;
    packet->confidence = confidence;
    packet->target_range = target_range;
    packet->tracker_id = tracker_id;
    packet->threat_level = threat_level;
    packet->target_system = target_system;
    packet->target_component = target_component;
    mav_array_memcpy(packet->bbox, bbox, sizeof(float)*4);
    mav_array_memcpy(packet->target_relative_vector, target_relative_vector, sizeof(float)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSE_DAA, (const char *)packet, MAVLINK_MSG_ID_SENSE_DAA_MIN_LEN, MAVLINK_MSG_ID_SENSE_DAA_LEN, MAVLINK_MSG_ID_SENSE_DAA_CRC);
#endif
}
#endif

#endif

// MESSAGE SENSE_DAA UNPACKING


/**
 * @brief Get field time_unix_usec from sense_daa message
 *
 * @return [us] Timestamp (UNIX epoch time).
 */
static inline uint64_t mavlink_msg_sense_daa_get_time_unix_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_system from sense_daa message
 *
 * @return  System ID
 */
static inline uint8_t mavlink_msg_sense_daa_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Get field target_component from sense_daa message
 *
 * @return  Component ID
 */
static inline uint8_t mavlink_msg_sense_daa_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  53);
}

/**
 * @brief Get field frame_num from sense_daa message
 *
 * @return  Frame number
 */
static inline uint32_t mavlink_msg_sense_daa_get_frame_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field tracker_id from sense_daa message
 *
 * @return  Tracker ID
 */
static inline uint16_t mavlink_msg_sense_daa_get_tracker_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  48);
}

/**
 * @brief Get field bbox from sense_daa message
 *
 * @return [pix] Bounding Box dimensions [top, left, height, width].
 */
static inline uint16_t mavlink_msg_sense_daa_get_bbox(const mavlink_message_t* msg, float *bbox)
{
    return _MAV_RETURN_float_array(msg, bbox, 4,  12);
}

/**
 * @brief Get field confidence from sense_daa message
 *
 * @return [%] Confidence (probability).
 */
static inline float mavlink_msg_sense_daa_get_confidence(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field target_range from sense_daa message
 *
 * @return [m] Estimated distance to detected target.
 */
static inline float mavlink_msg_sense_daa_get_target_range(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field target_relative_vector from sense_daa message
 *
 * @return [m] Estimated relative vector to detected target, defined in camera axes.
 */
static inline uint16_t mavlink_msg_sense_daa_get_target_relative_vector(const mavlink_message_t* msg, float *target_relative_vector)
{
    return _MAV_RETURN_float_array(msg, target_relative_vector, 3,  36);
}

/**
 * @brief Get field threat_level from sense_daa message
 *
 * @return  Threat level for detected object.
 */
static inline uint16_t mavlink_msg_sense_daa_get_threat_level(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  50);
}

/**
 * @brief Decode a sense_daa message into a struct
 *
 * @param msg The message to decode
 * @param sense_daa C-struct to decode the message contents into
 */
static inline void mavlink_msg_sense_daa_decode(const mavlink_message_t* msg, mavlink_sense_daa_t* sense_daa)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sense_daa->time_unix_usec = mavlink_msg_sense_daa_get_time_unix_usec(msg);
    sense_daa->frame_num = mavlink_msg_sense_daa_get_frame_num(msg);
    mavlink_msg_sense_daa_get_bbox(msg, sense_daa->bbox);
    sense_daa->confidence = mavlink_msg_sense_daa_get_confidence(msg);
    sense_daa->target_range = mavlink_msg_sense_daa_get_target_range(msg);
    mavlink_msg_sense_daa_get_target_relative_vector(msg, sense_daa->target_relative_vector);
    sense_daa->tracker_id = mavlink_msg_sense_daa_get_tracker_id(msg);
    sense_daa->threat_level = mavlink_msg_sense_daa_get_threat_level(msg);
    sense_daa->target_system = mavlink_msg_sense_daa_get_target_system(msg);
    sense_daa->target_component = mavlink_msg_sense_daa_get_target_component(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSE_DAA_LEN? msg->len : MAVLINK_MSG_ID_SENSE_DAA_LEN;
        memset(sense_daa, 0, MAVLINK_MSG_ID_SENSE_DAA_LEN);
    memcpy(sense_daa, _MAV_PAYLOAD(msg), len);
#endif
}
