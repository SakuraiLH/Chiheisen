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

	std::string ChiheisenTrueCXX =
#ifdef __clang__
	"Clang++";
#else
	"GNU GCC";
#endif

	std::string ChiheisenBuildOS =
#ifdef __WIN32
	"Windows";
#elif __unix__ && !__linux__
	"Unix";
#elif __APPLE__
	"MacOS";
#elif __linux__
	"Linux";
#elif __FreeBSD__
	"FreeBSD";
#else
	"Unknown";
#endif
	std::string ChiheisenCompileTime = __TIMESTAMP__;

const std::string ChiheisenAuthorship = "SakuraiLH";
const unsigned short MinChiheisenSoftwareVersion = 100;
const std::string ChiheisenSoftwareDistributionCodename = "Alexanderite";
const std::string ChiheisenSoftwareName = "Chihensen";
inline const std::string ChiheisenSoftwareVersionMainline = "1.0.0";
const std::string FullChiheisenSoftwareVersion = ChiheisenSoftwareName + ' '
                                               + ChiheisenSoftwareDistributionCodename + ' '
                                               + ChiheisenSoftwareVersionMainline + '/'
                                               + std::to_string(MinChiheisenSoftwareVersion) + ' ' 
                                               + "by" + ' ' + ChiheisenAuthorship + '\n'
                                               + '[' + ChiheisenTrueCXX + ']'
                                               + '(' + "Compiled with" + ' ' + ChiheisenBuildOS + ' ' + "at" + ' '
                                               + ChiheisenCompileTime + ')';
                                               // Info:
                                               // Chihensen Alexanderite 1.0.0/100 by SakuraiLH
                                               // [GNU GCC] (Compiled with Linux at Sat Mar  5 16:53:08 2022)
                                               // 