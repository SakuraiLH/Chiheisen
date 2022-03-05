// Copyright <C> 2020-2022 SakuraiLH, All rights reserved.
/*   ____ _   _ ___ _   _ _____ ___ ____  _____ _   _ 
 *  / ___| | | |_ _| | | | ____|_ _/ ___|| ____| \ | |
 * | |   | |_| || || |_| |  _|  | |\___ \|  _| |  \| |
 * | |___|  _  || ||  _  | |___ | | ___) | |___| |\  |
 *  \____|_| |_|___|_| |_|_____|___|____/|_____|_| \_|
 *
 *  Published using AGPLv3 license.
 *  If your software can interact with users remotely through a computer
 * network, you should also make sure that it provides a way for users to
 * get its source.  For example, if your program is a web application, its
 * interface could display a "Source" link that leads users to an archive
 * of the code.  There are many ways you could offer source, and different
 * solutions will be better for different programs; see section 13 for the
 * specific requirements.
 *
 * You should also get your employer (if you work as a programmer) or school,
 * if any, to sign a "copyright disclaimer" for the program, if necessary.
 * For more information on this, and how to apply and follow the GNU AGPL, see
 * <https://www.gnu.org/licenses/>.
 *
 */
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
    std::string CommandParameterPasseer(std::string ReceivedMessage, std::string CommandTrigger)
    {
        std::string CommandParameter = ReceivedMessage;
        CommandParameter.substr(CommandTrigger.length());
        while (CommandParameter[0] == ' ')
        {
            CommandParameter.substr(1);
        }
        return CommandParameter;
    }
}