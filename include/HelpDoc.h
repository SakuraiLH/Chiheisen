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
#include <json.hpp>
#include "SoftwareString.h"

namespace Chiheisen
{
    // 默认主页词条
    const std::string BotMsgHelpInfo = "输入 /help 来查看帮助信息。";
    const std::string HelpMsgMainPage = std::string("输入 /help 来查看帮助信息。") + '\n'
                                    + std::string("输入 /help list 来查看命令列表。") + '\n'
                                    + std::string("输入 /help 命令 来查看具体命令的帮助信息。") + '\n'
                                    + std::string("输入 /version 来查看版本信息。") + '\n';

    // 默认词条

    const std::string HelpMsgVer = "Chiheisen 帮助档案 版本 " + std::to_string(MinChiheisenSoftwareVersion);
    const std::string HelpDocNotExist = "Chiheisen 没有找到请求的帮助档案。";
    nlohmann::json DefaultHelpMsgDB = {
        "Version", HelpMsgVer + '\n' + "Version 帮助词条:" + '\n' + "显示Chiheisen实例的版本。"
        "author", HelpMsgVer + '\n' + "Author: SakuraiLH <C> 2020-2022" + '\n' + "Chiheisen(地平线)基于 AGPLv3 开源。"
    };
}