#pragma once
// MESSAGE KEYEXCHANGEGCSACK PACKING

#define MAVLINK_MSG_ID_KEYEXCHANGEGCSACK 10420


typedef struct __mavlink_keyexchangegcsack_t {
 uint8_t seq; /*<  Sequence Number.*/
 uint8_t seq_ack; /*<  Sequence Number ACK.*/
 uint8_t chunk_start; /*<  Read from.*/
 uint8_t chunk_end; /*<  Read to.*/
 uint8_t more_data; /*<  More data to read.*/
 uint8_t data[250]; /*<  Data*/
} mavlink_keyexchangegcsack_t;

#define MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN 255
#define MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_MIN_LEN 255
#define MAVLINK_MSG_ID_10420_LEN 255
#define MAVLINK_MSG_ID_10420_MIN_LEN 255

#define MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_CRC 84
#define MAVLINK_MSG_ID_10420_CRC 84

#define MAVLINK_MSG_KEYEXCHANGEGCSACK_FIELD_DATA_LEN 250

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_KEYEXCHANGEGCSACK { \
    10420, \
    "KEYEXCHANGEGCSACK", \
    6, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_keyexchangegcsack_t, seq) }, \
         { "seq_ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_keyexchangegcsack_t, seq_ack) }, \
         { "chunk_start", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_keyexchangegcsack_t, chunk_start) }, \
         { "chunk_end", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_keyexchangegcsack_t, chunk_end) }, \
         { "more_data", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_keyexchangegcsack_t, more_data) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 250, 5, offsetof(mavlink_keyexchangegcsack_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_KEYEXCHANGEGCSACK { \
    "KEYEXCHANGEGCSACK", \
    6, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_keyexchangegcsack_t, seq) }, \
         { "seq_ack", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_keyexchangegcsack_t, seq_ack) }, \
         { "chunk_start", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_keyexchangegcsack_t, chunk_start) }, \
         { "chunk_end", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_keyexchangegcsack_t, chunk_end) }, \
         { "more_data", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_keyexchangegcsack_t, more_data) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 250, 5, offsetof(mavlink_keyexchangegcsack_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a keyexchangegcsack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  Sequence Number.
 * @param seq_ack  Sequence Number ACK.
 * @param chunk_start  Read from.
 * @param chunk_end  Read to.
 * @param more_data  More data to read.
 * @param data  Data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_keyexchangegcsack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t seq, uint8_t seq_ack, uint8_t chunk_start, uint8_t chunk_end, uint8_t more_data, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN];
    _mav_put_uint8_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 1, seq_ack);
    _mav_put_uint8_t(buf, 2, chunk_start);
    _mav_put_uint8_t(buf, 3, chunk_end);
    _mav_put_uint8_t(buf, 4, more_data);
    _mav_put_uint8_t_array(buf, 5, data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN);
#else
    mavlink_keyexchangegcsack_t packet;
    packet.seq = seq;
    packet.seq_ack = seq_ack;
    packet.chunk_start = chunk_start;
    packet.chunk_end = chunk_end;
    packet.more_data = more_data;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_KEYEXCHANGEGCSACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_CRC);
}

/**
 * @brief Pack a keyexchangegcsack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  Sequence Number.
 * @param seq_ack  Sequence Number ACK.
 * @param chunk_start  Read from.
 * @param chunk_end  Read to.
 * @param more_data  More data to read.
 * @param data  Data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_keyexchangegcsack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t seq,uint8_t seq_ack,uint8_t chunk_start,uint8_t chunk_end,uint8_t more_data,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN];
    _mav_put_uint8_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 1, seq_ack);
    _mav_put_uint8_t(buf, 2, chunk_start);
    _mav_put_uint8_t(buf, 3, chunk_end);
    _mav_put_uint8_t(buf, 4, more_data);
    _mav_put_uint8_t_array(buf, 5, data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN);
#else
    mavlink_keyexchangegcsack_t packet;
    packet.seq = seq;
    packet.seq_ack = seq_ack;
    packet.chunk_start = chunk_start;
    packet.chunk_end = chunk_end;
    packet.more_data = more_data;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_KEYEXCHANGEGCSACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_CRC);
}

/**
 * @brief Encode a keyexchangegcsack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param keyexchangegcsack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_keyexchangegcsack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_keyexchangegcsack_t* keyexchangegcsack)
{
    return mavlink_msg_keyexchangegcsack_pack(system_id, component_id, msg, keyexchangegcsack->seq, keyexchangegcsack->seq_ack, keyexchangegcsack->chunk_start, keyexchangegcsack->chunk_end, keyexchangegcsack->more_data, keyexchangegcsack->data);
}

/**
 * @brief Encode a keyexchangegcsack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param keyexchangegcsack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_keyexchangegcsack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_keyexchangegcsack_t* keyexchangegcsack)
{
    return mavlink_msg_keyexchangegcsack_pack_chan(system_id, component_id, chan, msg, keyexchangegcsack->seq, keyexchangegcsack->seq_ack, keyexchangegcsack->chunk_start, keyexchangegcsack->chunk_end, keyexchangegcsack->more_data, keyexchangegcsack->data);
}

/**
 * @brief Send a keyexchangegcsack message
 * @param chan MAVLink channel to send the message
 *
 * @param seq  Sequence Number.
 * @param seq_ack  Sequence Number ACK.
 * @param chunk_start  Read from.
 * @param chunk_end  Read to.
 * @param more_data  More data to read.
 * @param data  Data
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_keyexchangegcsack_send(mavlink_channel_t chan, uint8_t seq, uint8_t seq_ack, uint8_t chunk_start, uint8_t chunk_end, uint8_t more_data, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN];
    _mav_put_uint8_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 1, seq_ack);
    _mav_put_uint8_t(buf, 2, chunk_start);
    _mav_put_uint8_t(buf, 3, chunk_end);
    _mav_put_uint8_t(buf, 4, more_data);
    _mav_put_uint8_t_array(buf, 5, data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK, buf, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_CRC);
#else
    mavlink_keyexchangegcsack_t packet;
    packet.seq = seq;
    packet.seq_ack = seq_ack;
    packet.chunk_start = chunk_start;
    packet.chunk_end = chunk_end;
    packet.more_data = more_data;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK, (const char *)&packet, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_CRC);
#endif
}

/**
 * @brief Send a keyexchangegcsack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_keyexchangegcsack_send_struct(mavlink_channel_t chan, const mavlink_keyexchangegcsack_t* keyexchangegcsack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_keyexchangegcsack_send(chan, keyexchangegcsack->seq, keyexchangegcsack->seq_ack, keyexchangegcsack->chunk_start, keyexchangegcsack->chunk_end, keyexchangegcsack->more_data, keyexchangegcsack->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK, (const char *)keyexchangegcsack, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_keyexchangegcsack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t seq, uint8_t seq_ack, uint8_t chunk_start, uint8_t chunk_end, uint8_t more_data, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, seq);
    _mav_put_uint8_t(buf, 1, seq_ack);
    _mav_put_uint8_t(buf, 2, chunk_start);
    _mav_put_uint8_t(buf, 3, chunk_end);
    _mav_put_uint8_t(buf, 4, more_data);
    _mav_put_uint8_t_array(buf, 5, data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK, buf, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_CRC);
#else
    mavlink_keyexchangegcsack_t *packet = (mavlink_keyexchangegcsack_t *)msgbuf;
    packet->seq = seq;
    packet->seq_ack = seq_ack;
    packet->chunk_start = chunk_start;
    packet->chunk_end = chunk_end;
    packet->more_data = more_data;
    mav_array_memcpy(packet->data, data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK, (const char *)packet, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_MIN_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_CRC);
#endif
}
#endif

#endif

// MESSAGE KEYEXCHANGEGCSACK UNPACKING


/**
 * @brief Get field seq from keyexchangegcsack message
 *
 * @return  Sequence Number.
 */
static inline uint8_t mavlink_msg_keyexchangegcsack_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field seq_ack from keyexchangegcsack message
 *
 * @return  Sequence Number ACK.
 */
static inline uint8_t mavlink_msg_keyexchangegcsack_get_seq_ack(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field chunk_start from keyexchangegcsack message
 *
 * @return  Read from.
 */
static inline uint8_t mavlink_msg_keyexchangegcsack_get_chunk_start(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field chunk_end from keyexchangegcsack message
 *
 * @return  Read to.
 */
static inline uint8_t mavlink_msg_keyexchangegcsack_get_chunk_end(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field more_data from keyexchangegcsack message
 *
 * @return  More data to read.
 */
static inline uint8_t mavlink_msg_keyexchangegcsack_get_more_data(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field data from keyexchangegcsack message
 *
 * @return  Data
 */
static inline uint16_t mavlink_msg_keyexchangegcsack_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 250,  5);
}

/**
 * @brief Decode a keyexchangegcsack message into a struct
 *
 * @param msg The message to decode
 * @param keyexchangegcsack C-struct to decode the message contents into
 */
static inline void mavlink_msg_keyexchangegcsack_decode(const mavlink_message_t* msg, mavlink_keyexchangegcsack_t* keyexchangegcsack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    keyexchangegcsack->seq = mavlink_msg_keyexchangegcsack_get_seq(msg);
    keyexchangegcsack->seq_ack = mavlink_msg_keyexchangegcsack_get_seq_ack(msg);
    keyexchangegcsack->chunk_start = mavlink_msg_keyexchangegcsack_get_chunk_start(msg);
    keyexchangegcsack->chunk_end = mavlink_msg_keyexchangegcsack_get_chunk_end(msg);
    keyexchangegcsack->more_data = mavlink_msg_keyexchangegcsack_get_more_data(msg);
    mavlink_msg_keyexchangegcsack_get_data(msg, keyexchangegcsack->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN? msg->len : MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN;
        memset(keyexchangegcsack, 0, MAVLINK_MSG_ID_KEYEXCHANGEGCSACK_LEN);
    memcpy(keyexchangegcsack, _MAV_PAYLOAD(msg), len);
#endif
}
