//////////////////////////////////////////////////////////////////////////
// Message.h
//
// 
//
// Copyright (C) 2014 Microsoft Corp.  All Rights Reserved
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "Buffer.h"

XTOOLS_NAMESPACE_BEGIN

class Message : public AtomicRefCounted
{
public:
	Message(SocketID socketID);
	Message(SocketID socketID, PeerID peerID, const RakNet::SystemAddress& address, uint32 messageSize);

	// Returns false if the size is zero
	bool			IsValid() const;
	
	SocketID		GetSocketID() const;
	PeerID			GetPeerID() const;

	const RakNet::SystemAddress& GetSystemAddress() const;

	const byte*		GetData() const;
	uint32			GetSize() const;
	void			SetData(const byte* buffer, uint32 size);
	void			AppendData(const byte* buffer, uint32 size);

	// Return the ID of the message, which is the first byte of the payload
	byte			GetMessageID() const;

private:
	Buffer					m_payload;
	SocketID				m_socketID;
	PeerID					m_peerID;
	RakNet::SystemAddress	m_address;
};

DECLARE_PTR(Message)

XTOOLS_NAMESPACE_END
