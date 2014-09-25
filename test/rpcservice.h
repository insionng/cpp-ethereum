/*
 This file is part of cpp-ethereum.
 
 cpp-ethereum is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 cpp-ethereum is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
 */
/** @file rpcservice.h
 * @author Alex Leverington <nessence@gmail.com>
 * @date 2014
 */

#pragma once

#include <libethereum/Interface.h>
#include <libwebthree/NetService.h>
#include <libwebthree/Common.h>

namespace dev
{

class EthereumRPCServer;
class EthereumRPCService: public NetService<EthereumRPCServer>
{
public:
	EthereumRPCService(eth::Interface* _ethereum): m_ethereum(_ethereum) { }
	
	eth::Interface* ethereum() { return m_ethereum; }
	
protected:
	eth::Interface* m_ethereum;
};
	

class TestCoreTypesInterface
{
	std::string string() { return "string"; }
	u256 u256() { return (uint64_t)1 << 63; }
	h256 h256() { return FixedHash<32>(fromHex("FFFFFFFFFFFFFFFF")); }
	h256s h256s() { return std::vector<FixedHash<32>>({FixedHash<32>(fromHex("FFFFFFFFFFFFFFFF"))}); }
};

class TestProtocol;
class TestService: public NetService<TestProtocol>
{
public:
	TestService(TestCoreTypesInterface* _interface): m_interface(_interface) {}
	
	std::string protocolServiceString() { return "protocolServiceString"; }
	
	TestCoreTypesInterface* interface() { return m_interface; }
protected:
	TestCoreTypesInterface* m_interface;
};
	
}
