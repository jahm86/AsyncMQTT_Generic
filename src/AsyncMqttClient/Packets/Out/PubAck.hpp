/****************************************************************************************************************************
  PubAck.hpp
  
  AsyncMqttClient_Generic is a library for ESP32, ESP8266, Protenta_H7, STM32F7, etc. with current AsyncTCP support
  
  Based on and modified from :
  
  1) async-mqtt-client (https://github.com/marvinroger/async-mqtt-client)
  
  Built by Khoi Hoang https://github.com/khoih-prog/AsyncMqttClient_Generic
 
  Version: 1.0.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0    K Hoang     10/03/2022 Initial coding to support only ESP32 (with SSL) and ESP8266 (without SSL)
 *****************************************************************************************************************************/

#pragma once

#ifndef PUB_ACK_HPP
#define PUB_ACK_HPP

#include "OutPacket.hpp"
#include "../../Flags.hpp"
#include "../../Helpers.hpp"
#include "../../Storage.hpp"

namespace AsyncMqttClientInternals 
{
	class PubAckOutPacket : public OutPacket 
	{
		public:
			explicit PubAckOutPacket(PendingAck pendingAck);
			const uint8_t* data(size_t index = 0) const;
			size_t size() const;

		private:
			uint8_t _data[4];
};
}  // namespace AsyncMqttClientInternals

#endif		// PUB_ACK_HPP
