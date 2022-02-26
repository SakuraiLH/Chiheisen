#pragma once
#include <iostream>
#include <MiraiCP.hpp>
#include <json.hpp>
#include <typeinfo>

class CommandJudge
{
public:
    bool CommandSelector(std::string ReceivedMessage, std::string CommandTrigger)
    {
        if (ReceivedMessage == CommandTrigger) return true;
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
};