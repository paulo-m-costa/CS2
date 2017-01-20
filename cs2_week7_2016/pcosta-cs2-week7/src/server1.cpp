/**
@file server1.cpp
@author Ben Yuan
@date 2016
@copyright 2-clause BSD; see License section

@brief
A multi-user echo server to validate the network wrapper.

@section License

Copyright (c) 2012-2013 California Institute of Technology.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the California Institute of Technology.

*/

#include "server1.hpp"

using namespace CS2Net;

int main(int argc, char ** argv)
{

    REQUIRE(argc == 2, "usage: %s port", argv[0]);

    /* Accept incoming connections as they arrive.
     * In the meantime, rebroadcast anything you recv to all users.
     *
     */
    int poll_err;
    CS2Net::Socket listener;
    CS2Net::Socket * incoming_conn = NULL;
    std::vector<CS2Net::PollFD> poll_vec(0);
    std::vector<std::string> prev_strings;
    // Backlog of 3 connections allowed
    int err = listener.Bind(std::atoi(argv[1]), 3);
    REQUIRE(err == 0, "Failed to bind!");
    
    while (true)
    {
        std::vector<CS2Net::PollFD> temp_poll(1);
        temp_poll[0].sock = &listener;
        temp_poll[0].SetRead(true);
        poll_err = CS2Net::Poll(&temp_poll, 10);
        REQUIRE(poll_err >= 0, "error on poll!");
        if(temp_poll[0].HasHangup() || temp_poll[0].HasError())
        {
            ERROR("temp_poll hung up!");
        }
    
        if(temp_poll[0].CanRead())
        {
            INFO("Connection accepted.");
            PollFD push_poll(listener.Accept(), 0);
            push_poll.SetRead(true);
            poll_vec.push_back(push_poll);	
            // Place a connection on our list of pollvecs
            prev_strings.push_back("");
    }
      
    poll_err = CS2Net::Poll(&poll_vec, 10);
    int size = poll_vec.size();
      
    for (int i = 0; i< size; i++)
    {
        std::string * incoming;
        if(poll_vec[i].HasHangup() || poll_vec[i].HasError())
        {
            poll_vec[i].sock->Disconnect();
            poll_vec.erase(poll_vec.begin()+i);
            prev_strings.erase(prev_strings.begin()+i);
            i--;
            size--;
            INFO("Client poll %d hung up.", &i);
            continue;
        }
        if(poll_vec[i].CanRead())
        {
            incoming = poll_vec[i].sock->Recv(1024, false);
        }
        if(incoming == NULL)
        {
            INFO("Disconnected.");
        }
        else
        {
            for (int j = 0; j < size; j++)
            {
                if (prev_strings[j].compare(*incoming) == 0)
                {
                    continue;
                }
                int ret = poll_vec[j].sock->Send(incoming);
                prev_strings[j] = *incoming;
                if(ret < 0)
                {
                    if(ret == -1)
                    {
                        INFO("send error: %s", strerror(errno));
                        poll_vec[j].sock->Disconnect();
                        poll_vec.erase(poll_vec.begin()+j);
                        prev_strings.erase(prev_strings.begin()+j);
                        size--;
                    }
                    else
                    {
                        INFO("this error should never occur");
                        poll_vec[j].sock->Disconnect();
                        poll_vec.erase(poll_vec.begin()+j);
                        prev_strings.erase(prev_strings.begin()+j);
                        size--;
                    }
                }
                else
                {
                    // Do nothing!
                }
            j++;
            }
        }
    }
    return 0;
}