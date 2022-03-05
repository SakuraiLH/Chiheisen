#pragma once
#include <iostream>
#include <MiraiCP.hpp>
#include <json.hpp>
#include <typeinfo>

namespace Chiheisen
{
    bool CommandSelector(std::string ReceivedMessage, std::string CommandTrigger)
    {
        std::string SubStrTrigger = ReceivedMessage;
        if (ReceivedMessage.length() > CommandTrigger.length())
        {
            return false;
        }
        SubStrTrigger.substr(0, CommandTrigger.length());
        if (SubStrTrigger == CommandTrigger) return true;
        return false;
    }
    bool CommandLengthFilter(std::string ReceivedMessage)
    {
        if (ReceivedMessage.length() >= 1024)
        {
            return false;
        }
        return true;
    }
}