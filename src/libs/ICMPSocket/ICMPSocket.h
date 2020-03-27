/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of pingnoo (https://github.com/fizzyade/pingnoo)
 * An open source ping path analyser
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FIZZYADE_ICMPSOCKET_ICMPSOCKET_H
#define FIZZYADE_ICMPSOCKET_ICMPSOCKET_H

#include <QtGlobal>
#include <chrono>
#if defined(Q_OS_UNIX)
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <poll.h>
#elif defined(Q_OS_WIN)
#define NOMINMAX
#include <WinSock2.h>
#include <WS2tcpip.h>
#endif
#include <QByteArray>
#include <QHostAddress>

#if (defined(FIZZYADE_LIBRARY_ICMPSOCKET_EXPORT))
#define FIZZYADE_ICMPSOCKET_DLLSPEC Q_DECL_EXPORT
#else
#define FIZZYADE_ICMPSOCKET_DLLSPEC Q_DECL_IMPORT
#endif

namespace FizzyAde::ICMPSocket
{
    enum IPVersion
    {
        V4 = 4,
        V6 = 6
    };
    /**
     * ICMP Socket Abstraction
     *
     * Provides functions for sending and receiving ICMP packets
     * indepentently of the host platform.
     *
     */
    class FIZZYADE_ICMPSOCKET_DLLSPEC ICMPSocket
    {
    private:
#if defined(Q_OS_WIN)
        typedef SOCKET socket_t;
#else
        typedef int socket_t;
#endif
    private:
        /**
         * ICMPSocket constructor is private, instances are created
         * by calling either createReadSocket or createWriteSocket
         *
         * @param socket platform socket
         */
        ICMPSocket(ICMPSocket::socket_t socket, IPVersion version=FizzyAde::ICMPSocket::V4);

        /**
         * Checks whether the given platform socket is valid
         *
         * @param socket platform socket
         */
        static bool isValid(ICMPSocket::socket_t socket);

        /**
         * Called by socket creation to ensure underlying networking
         * subsystem is initialised.
         */
        static void initialiseSockets();

    public:
        ~ICMPSocket();

        /**
         * Create a socket for reading ALL incoming ICMP packets
         *
         * @return an instance of this class
         */
        static ICMPSocket *createReadSocket(FizzyAde::ICMPSocket::IPVersion version=FizzyAde::ICMPSocket::V4);

        /**
         * Create a socket for writing ICMP packets with the given ttl
         *
         * @return an instance of this class
         */
        static ICMPSocket *createWriteSocket(int ttl = 0, FizzyAde::ICMPSocket::IPVersion version=FizzyAde::ICMPSocket::V4);

        /**
         * Receives data from a read or write socket
         *
         * @param buffer the buffer to receive data
         * @param receiveAddress the address that the packet was received from
         * @param timeout read timeout
         * @return -1 on timeout or error, otherwise the number of bytes read
         */
        int recvfrom(QByteArray &buffer, QHostAddress &receiveAddress, std::chrono::milliseconds timeout);

        /**
         * Sends data to a write socket
         *
         * @param buffer the data to send
         * @param hostAddress the address that the packet was received from
         * @return -1 on error, otherwise the number of bytes written
         */
        int sendto(QByteArray &buffer, const QHostAddress &hostAddress);

        /**
         * Sets the TTL on a write socket
         *
         * @param ttl the ttl to set
         */
        void setTTL(int ttl);

        /**
         * Sets the Hop Limit on a V6 write socket
         *
         * @param hopLimit the hop limit to set
         */
        void setHopLimit(int hopLimit);

        /**
         * Returns the IP version of the socket
         *
         * @return V4 or V6
         */
        FizzyAde::ICMPSocket::IPVersion version();

    private:

        ICMPSocket::socket_t m_socketDescriptor;
        FizzyAde::ICMPSocket::IPVersion m_version;
    };
}

#endif // FIZZYADE_ICMPSOCKET_ICMPSOCKET_H