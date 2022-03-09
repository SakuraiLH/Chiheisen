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

#include <iostream>
#include <json.hpp>
#include <MiraiCP.hpp>
#include "CHSBotMsg.cpp"
#include "CHSCommandJudge.cpp"
#include "CHSHelpDoc.cpp"
#ifdef CHIHEISENDEBUG
#include "CHSDebug.cpp"
#endif

#define ReplyJudger(JudgeCondition) if(Chiheisen::CommandSelector(IncomingMessage, JudgeCondition))

using json = nlohmann::json;
using namespace MiraiCP;

class Main : public CPPPlugin {
public:
  Main() : CPPPlugin(PluginConfig("com.chiheisen.chip", "Chiheisen", "1", "SakuraiLH", "地平线!", "2022-02-26")) {}
  void onEnable() override {
    Event::processor.registerEvent<GroupMessageEvent>([](GroupMessageEvent e){
      using namespace Chiheisen;
      auto IncomingMessage = e.message.toMiraiCode();
      if (!Chiheisen::CommandLengthFilter(IncomingMessage))
      {
        return 0;
      }
      ReplyJudger ("/version")
      {
        Chiheisen::DisplaySoftwareVersion(e);
      }
      ReplyJudger ("/help")
      {
        std::string HelpParameter = Chiheisen::CommandParameterPasseer(IncomingMessage, "/help");
        HelpMainPage(e, HelpParameter);
      }
      #ifdef CHIHEISENDEBUG
      ReplyJudger ("/printoutdatabase")
      {
        Printouthelpdb(e, DefaultHelpMsgDB);
      }
      #endif
      return 0;
    }
    );
  }

  void onDisable() override {
  }
};

void MiraiCP::enrollPlugin() {
  MiraiCP::enrollPlugin0(new Main());
}

