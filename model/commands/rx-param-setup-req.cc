/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2011 The Boeing Company
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Brecht Reynders <brecht.reynders@esat.kuleuven.be>
 */

#include "rx-param-setup-req.h"
#include <ns3/lora-mac-command.h>
#include <ns3/address.h>

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (RxParamSetupReq);

RxParamSetupReq::RxParamSetupReq(void)
{
	
	m_cid = RX_PARAM_SETUP;
	m_direction = FROMBASE;
}

RxParamSetupReq::~RxParamSetupReq (void)
{
}

TypeId
RxParamSetupReq::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::RxParamSetupReq")
    .SetParent<LoRaMacCommand> ();
  return tid;
}



TypeId
RxParamSetupReq::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

uint32_t
RxParamSetupReq::GetSerializedSize (void) const
{
  return 1;
}


void
RxParamSetupReq::Serialize (Buffer::Iterator start) const
{
  Buffer::Iterator i = start;
  i.WriteU8 (m_cid);
}


uint32_t
RxParamSetupReq::Deserialize (Buffer::Iterator start)
{
  return 0;
}

void
RxParamSetupReq::Execute (Ptr<LoRaNetDevice> nd,Address address)
{
	//nd->GetSNR();
	//Ptr<LoRaMacCommand> command = CreateObject<LinkCheckAns>(margin,count);
	//nd->SetMacAnswer (command);
}

} //namespace ns3
