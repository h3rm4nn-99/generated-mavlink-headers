#pragma once
// MESSAGE CAPSULEACK PACKING

#define MAVLINK_MSG_ID_CAPSULEACK 10422


typedef struct __mavlink_capsuleack_t {
 uint8_t seq; /*<  Next Sequence Number.*/
} mavlink_capsuleack_t;

#define MAVLINK_MSG_ID_CAPSULEACK_LEN 1
#define MAVLINK_MSG_ID_CAPSULEACK_MIN_LEN 1
#define MAVLINK_MSG_ID_10422_LEN 1
#define MAVLINK_MSG_ID_10422_MIN_LEN 1

#define MAVLINK_MSG_ID_CAPSULEACK_CRC 179
#define MAVLINK_MSG_ID_10422_CRC 179



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAPSULEACK { \
    10422, \
    "CAPSULEACK", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_capsuleack_t, seq) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAPSULEACK { \
    "CAPSULEACK", \
    1, \
    {  { "seq", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_capsuleack_t, seq) }, \
         } \
}
#endif

/**
 * @brief Pack a capsuleack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param seq  Next Sequence Number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_capsuleack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAPSULEACK_LEN];
    _mav_put_uint8_t(buf, 0, seq);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAPSULEACK_LEN);
#else
    mavlink_capsuleack_t packet;
    packet.seq = seq;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAPSULEACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CAPSULEACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CAPSULEACK_MIN_LEN, MAVLINK_MSG_ID_CAPSULEACK_LEN, MAVLINK_MSG_ID_CAPSULEACK_CRC);
}

/**
 * @brief Pack a capsuleack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param seq  Next Sequence Number.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_capsuleack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAPSULEACK_LEN];
    _mav_put_uint8_t(buf, 0, seq);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAPSULEACK_LEN);
#else
    mavlink_capsuleack_t packet;
    packet.seq = seq;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAPSULEACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CAPSULEACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CAPSULEACK_MIN_LEN, MAVLINK_MSG_ID_CAPSULEACK_LEN, MAVLINK_MSG_ID_CAPSULEACK_CRC);
}

/**
 * @brief Encode a capsuleack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param capsuleack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_capsuleack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_capsuleack_t* capsuleack)
{
    return mavlink_msg_capsuleack_pack(system_id, component_id, msg, capsuleack->seq);
}

/**
 * @brief Encode a capsuleack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param capsuleack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_capsuleack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_capsuleack_t* capsuleack)
{
    return mavlink_msg_capsuleack_pack_chan(system_id, component_id, chan, msg, capsuleack->seq);
}

/**
 * @brief Send a capsuleack message
 * @param chan MAVLink channel to send the message
 *
 * @param seq  Next Sequence Number.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_capsuleack_send(mavlink_channel_t chan, uint8_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CAPSULEACK_LEN];
    _mav_put_uint8_t(buf, 0, seq);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAPSULEACK, buf, MAVLINK_MSG_ID_CAPSULEACK_MIN_LEN, MAVLINK_MSG_ID_CAPSULEACK_LEN, MAVLINK_MSG_ID_CAPSULEACK_CRC);
#else
    mavlink_capsuleack_t packet;
    packet.seq = seq;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAPSULEACK, (const char *)&packet, MAVLINK_MSG_ID_CAPSULEACK_MIN_LEN, MAVLINK_MSG_ID_CAPSULEACK_LEN, MAVLINK_MSG_ID_CAPSULEACK_CRC);
#endif
}

/**
 * @brief Send a capsuleack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_capsuleack_send_struct(mavlink_channel_t chan, const mavlink_capsuleack_t* capsuleack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_capsuleack_send(chan, capsuleack->seq);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAPSULEACK, (const char *)capsuleack, MAVLINK_MSG_ID_CAPSULEACK_MIN_LEN, MAVLINK_MSG_ID_CAPSULEACK_LEN, MAVLINK_MSG_ID_CAPSULEACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_CAPSULEACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_capsuleack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t seq)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, seq);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAPSULEACK, buf, MAVLINK_MSG_ID_CAPSULEACK_MIN_LEN, MAVLINK_MSG_ID_CAPSULEACK_LEN, MAVLINK_MSG_ID_CAPSULEACK_CRC);
#else
    mavlink_capsuleack_t *packet = (mavlink_capsuleack_t *)msgbuf;
    packet->seq = seq;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAPSULEACK, (const char *)packet, MAVLINK_MSG_ID_CAPSULEACK_MIN_LEN, MAVLINK_MSG_ID_CAPSULEACK_LEN, MAVLINK_MSG_ID_CAPSULEACK_CRC);
#endif
}
#endif

#endif

// MESSAGE CAPSULEACK UNPACKING


/**
 * @brief Get field seq from capsuleack message
 *
 * @return  Next Sequence Number.
 */
static inline uint8_t mavlink_msg_capsuleack_get_seq(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a capsuleack message into a struct
 *
 * @param msg The message to decode
 * @param capsuleack C-struct to decode the message contents into
 */
static inline void mavlink_msg_capsuleack_decode(const mavlink_message_t* msg, mavlink_capsuleack_t* capsuleack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    capsuleack->seq = mavlink_msg_capsuleack_get_seq(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CAPSULEACK_LEN? msg->len : MAVLINK_MSG_ID_CAPSULEACK_LEN;
        memset(capsuleack, 0, MAVLINK_MSG_ID_CAPSULEACK_LEN);
    memcpy(capsuleack, _MAV_PAYLOAD(msg), len);
#endif
}
