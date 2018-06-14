#pragma once

#include "RakNetTypes.h"
#include "PacketPriority.h"
#include "ReplicaEnums.h"
#include "Replica.h"

#include "Vector3.h"
#include "Quaternion.h"
#include "Packets/lwoPacketUtils.h"

#include <string>

namespace RakNet
{
	class BitStream;
};

// One way to use the replication system is derive from the Replica class
class Player : public Replica
{
public:
	Player();
	~Player();

	// These functions are all from the Replica interface in ReplicaManager.h
	// They are user defined pure virtual implementations that perform processing that the ReplicaManager system requests.
	ReplicaReturnResult SendConstruction( RakNetTime currentTime, SystemAddress systemAddress, unsigned int &flags, RakNet::BitStream *outBitStream, bool *includeTimestamp );
	ReplicaReturnResult SendDestruction(RakNet::BitStream *outBitStream, SystemAddress systemAddress, bool *includeTimestamp);
	ReplicaReturnResult ReceiveDestruction(RakNet::BitStream *inBitStream, SystemAddress systemAddress, RakNetTime timestamp);
	ReplicaReturnResult SendScopeChange(bool inScope, RakNet::BitStream *outBitStream, RakNetTime currentTime, SystemAddress systemAddress, bool *includeTimestamp);
	ReplicaReturnResult ReceiveScopeChange(RakNet::BitStream *inBitStream, SystemAddress systemAddress, RakNetTime timestamp);
	ReplicaReturnResult Serialize(bool *sendTimestamp, RakNet::BitStream *outBitStream, RakNetTime lastSendTime, PacketPriority *priority, PacketReliability *reliability, RakNetTime currentTime, SystemAddress systemAddress, unsigned int &flags);
	ReplicaReturnResult Deserialize(RakNet::BitStream *inBitStream, RakNetTime timestamp, RakNetTime lastDeserializeTime, SystemAddress systemAddress );
	int GetSortPriority(void) const {return 0;}

	// Game specific data
	unsigned long long objectID;
	unsigned int templateID = 1;
	std::wstring objectName = L"";
	unsigned int gmLevel;

	Vector3 position;
	Quaternion rotation;
	bool bIsOnGround = false;
	Vector3 velocity;
	Vector3 angularVelocity;
};
