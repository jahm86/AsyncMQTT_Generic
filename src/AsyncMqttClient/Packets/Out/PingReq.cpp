/****************************************************************************************************************************
  PingReq.cpp
  
  AsyncMqttClient_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc. with current AsyncTCP support
  
  Based on and modified from :
  
  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMqttClient_Generic
 
  Version: 1.0.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0    K Hoang     10/03/2022 Initial coding to support only ESP32 (with SSL) and ESP8266 (without SSL)
 *****************************************************************************************************************************/

#include "PingReq.hpp"

using AsyncMqttClientInternals::PingReqOutPacket;

PingReqOutPacket::PingReqOutPacket() 
{
  _data[0] = AsyncMqttClientInternals::PacketType.PINGREQ;
  _data[0] = _data[0] << 4;
  _data[0] = _data[0] | AsyncMqttClientInternals::HeaderFlag.PINGREQ_RESERVED;
  _data[1] = 0;
}

const uint8_t* PingReqOutPacket::data(size_t index) const 
{
  return &_data[index];;
}

size_t PingReqOutPacket::size() const 
{
  return 2;
}
