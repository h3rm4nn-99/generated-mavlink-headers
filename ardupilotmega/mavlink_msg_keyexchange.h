#pragma once
// MESSAGE KEYEXCHANGE PACKING

#define MAVLINK_MSG_ID_KEYEXCHANGE 10000


typedef struct __mavlink_keyexchange_t {
 uint8_t seq; /*<  Sequence Number.*/
 uint8_t chunk_start; /*<  Read from.*/
 uint8_t chunk_end; /*<  Read to.*/
 uint8_t more_data; /*<  More data to read.*/
 uint8_t data[251]; /*<  Data*/
} mavlink_keyexchange_t;

#define MAVLINK_MSG_ID_KEYEXCHANGE_LEN 255
#define MAVLINK_MSG_ID_KEYEXCHANGE_MIN_LEN 255
#define MAVLINK_MSG_ID_10000_LEN 255
#define MAVLINK_MSG_ID_10000_MIN_LEN 255

#define MAVLINK_MSG_ID_KEYEXCHANGE_CRC 113
#define MAVLINK_MSG_ID_10000_CRC 113

#define MAVLINK_MSG_KEYEXCHANGE_FIELD_DATA_LEN 251

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_KEYEXCHANGE { \
    10000, \
    "KEYEXCHANGE", \
    5, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_keyexchange_t, seq) }, \
         { "chunk_start", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_keyexchange_t, chunk_start) }, \
         { "chunk_end", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_keyexchange_t, chunk_end) }, \
         { "more_data", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_keyexchange_t, more_data) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 251, 4, offsetof(mavlink_keyexchange_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_KEYEXCHANGE { \
    "KEYEXCHANGE", \
    5, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_keyexchange_t, seq) }, \
         { "chunk_start", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_keyexchange_t, chunk_start) }, \
         { "chunk_end", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_keyexchange_t, chunk_end) }, \
         { "more_data", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_keyexchange_t, more_data) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 251, 4, offsetof(mavlink_keyexchange_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a keyexchange message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  Sequence Number.
 * @param chunk_start  Read from.
 * @param chunk_end  Read to.
 * @param more_data  More data to read.
 * @param data  Data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_keyexchange_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t seq, uint8_t chunk_start, uint8_t chunk_end, uint8_t more_data, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KEYEXCHANGE_LEN];
    _mav_put_uint8_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 1, chunk_start);
    _mav_put_uint8_t(buf, 2, chunk_end);
    _mav_put_uint8_t(buf, 3, more_data);
    _mav_put_uint8_t_array(buf, 4, data, 251);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_KEYEXCHANGE_LEN);
#else
    mavlink_keyexchange_t packet;
    packet.seq = seq;
    packet.chunk_start = chunk_start;
    packet.chunk_end = chunk_end;
    packet.more_data = more_data;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*251);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_KEYEXCHANGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_KEYEXCHANGE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_KEYEXCHANGE_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_CRC);
}

/**
 * @brief Pack a keyexchange message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  Sequence Number.
 * @param chunk_start  Read from.
 * @param chunk_end  Read to.
 * @param more_data  More data to read.
 * @param data  Data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_keyexchange_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t seq,uint8_t chunk_start,uint8_t chunk_end,uint8_t more_data,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KEYEXCHANGE_LEN];
    _mav_put_uint8_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 1, chunk_start);
    _mav_put_uint8_t(buf, 2, chunk_end);
    _mav_put_uint8_t(buf, 3, more_data);
    _mav_put_uint8_t_array(buf, 4, data, 251);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_KEYEXCHANGE_LEN);
#else
    mavlink_keyexchange_t packet;
    packet.seq = seq;
    packet.chunk_start = chunk_start;
    packet.chunk_end = chunk_end;
    packet.more_data = more_data;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*251);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_KEYEXCHANGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_KEYEXCHANGE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_KEYEXCHANGE_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_CRC);
}

/**
 * @brief Encode a keyexchange struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param keyexchange C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_keyexchange_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_keyexchange_t* keyexchange)
{
    return mavlink_msg_keyexchange_pack(system_id, component_id, msg, keyexchange->seq, keyexchange->chunk_start, keyexchange->chunk_end, keyexchange->more_data, keyexchange->data);
}

/**
 * @brief Encode a keyexchange struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param keyexchange C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_keyexchange_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_keyexchange_t* keyexchange)
{
    return mavlink_msg_keyexchange_pack_chan(system_id, component_id, chan, msg, keyexchange->seq, keyexchange->chunk_start, keyexchange->chunk_end, keyexchange->more_data, keyexchange->data);
}

/**
 * @brief Send a keyexchange message
 * @param chan MAVLink channel to send the message
 *
 * @param seq  Sequence Number.
 * @param chunk_start  Read from.
 * @param chunk_end  Read to.
 * @param more_data  More data to read.
 * @param data  Data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_keyexchange_send(mavlink_channel_t chan, uint8_t seq, uint8_t chunk_start, uint8_t chunk_end, uint8_t more_data, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KEYEXCHANGE_LEN];
    _mav_put_uint8_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 1, chunk_start);
    _mav_put_uint8_t(buf, 2, chunk_end);
    _mav_put_uint8_t(buf, 3, more_data);
    _mav_put_uint8_t_array(buf, 4, data, 251);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGE, buf, MAVLINK_MSG_ID_KEYEXCHANGE_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_CRC);
#else
    mavlink_keyexchange_t packet;
    packet.seq = seq;
    packet.chunk_start = chunk_start;
    packet.chunk_end = chunk_end;
    packet.more_data = more_data;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*251);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGE, (const char *)&packet, MAVLINK_MSG_ID_KEYEXCHANGE_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_CRC);
#endif
}

/**
 * @brief Send a keyexchange message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_keyexchange_send_struct(mavlink_channel_t chan, const mavlink_keyexchange_t* keyexchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_keyexchange_send(chan, keyexchange->seq, keyexchange->chunk_start, keyexchange->chunk_end, keyexchange->more_data, keyexchange->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGE, (const char *)keyexchange, MAVLINK_MSG_ID_KEYEXCHANGE_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_CRC);
#endif
}

#if MAVLINK_MSG_ID_KEYEXCHANGE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_keyexchange_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t seq, uint8_t chunk_start, uint8_t chunk_end, uint8_t more_data, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 1, chunk_start);
    _mav_put_uint8_t(buf, 2, chunk_end);
    _mav_put_uint8_t(buf, 3, more_data);
    _mav_put_uint8_t_array(buf, 4, data, 251);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGE, buf, MAVLINK_MSG_ID_KEYEXCHANGE_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_CRC);
#else
    mavlink_keyexchange_t *packet = (mavlink_keyexchange_t *)msgbuf;
    packet->seq = seq;
    packet->chunk_start = chunk_start;
    packet->chunk_end = chunk_end;
    packet->more_data = more_data;
    mav_array_memcpy(packet->data, data, sizeof(uint8_t)*251);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGE, (const char *)packet, MAVLINK_MSG_ID_KEYEXCHANGE_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_LEN, MAVLINK_MSG_ID_KEYEXCHANGE_CRC);
#endif
}
#endif

#endif

// MESSAGE KEYEXCHANGE UNPACKING


/**
 * @brief Get field seq from keyexchange message
 *
 * @return  Sequence Number.
 */
static inline uint8_t mavlink_msg_keyexchange_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field chunk_start from keyexchange message
 *
 * @return  Read from.
 */
static inline uint8_t mavlink_msg_keyexchange_get_chunk_start(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field chunk_end from keyexchange message
 *
 * @return  Read to.
 */
static inline uint8_t mavlink_msg_keyexchange_get_chunk_end(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field more_data from keyexchange message
 *
 * @return  More data to read.
 */
static inline uint8_t mavlink_msg_keyexchange_get_more_data(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field data from keyexchange message
 *
 * @return  Data
 */
static inline uint16_t mavlink_msg_keyexchange_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 251,  4);
}

/**
 * @brief Decode a keyexchange message into a struct
 *
 * @param msg The message to decode
 * @param keyexchange C-struct to decode the message contents into
 */
static inline void mavlink_msg_keyexchange_decode(const mavlink_message_t* msg, mavlink_keyexchange_t* keyexchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    keyexchange->seq = mavlink_msg_keyexchange_get_seq(msg);
    keyexchange->chunk_start = mavlink_msg_keyexchange_get_chunk_start(msg);
    keyexchange->chunk_end = mavlink_msg_keyexchange_get_chunk_end(msg);
    keyexchange->more_data = mavlink_msg_keyexchange_get_more_data(msg);
    mavlink_msg_keyexchange_get_data(msg, keyexchange->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_KEYEXCHANGE_LEN? msg->len : MAVLINK_MSG_ID_KEYEXCHANGE_LEN;
        memset(keyexchange, 0, MAVLINK_MSG_ID_KEYEXCHANGE_LEN);
    memcpy(keyexchange, _MAV_PAYLOAD(msg), len);
#endif
}
