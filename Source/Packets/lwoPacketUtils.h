#pragma once
#include "lwoServerPackets.h"
#include <vector>

namespace lwoPacketUtils {
	void ServerSendPacket(RakPeerInterface* rakServer, char* data, unsigned int len, const SystemAddress& address);
	void ServerSendPacket(RakPeerInterface* rakServer, const std::vector<unsigned char>& msg, const SystemAddress& address);
	std::string RawDataToString(unsigned char* data, unsigned int size, bool onlyraw);
	void createPacketHeader(unsigned char uPacketID, unsigned short sConnectionType, unsigned int iInternalPacketID, RakNet::BitStream* bitStream);
	void writeStringToPacket(std::string sString, int maxSize, RakNet::BitStream* bitStream);
	int readInt(int startLoc, int endLoc, Packet* packet);
	unsigned long readLong(int startLoc, int endLoc, Packet* packet);
	unsigned long long readLongLong(int startLoc, int endLoc, Packet* packet);
	std::string readWStringAsString(unsigned int iStrStartLoc, Packet* packet);
	bool savePacket(const std::string& sFileName, const char* cData, int iLength);
	std::wstring StringToWString(const std::string& string, int size);
	std::string WStringToString(const std::wstring& string, int size);
}