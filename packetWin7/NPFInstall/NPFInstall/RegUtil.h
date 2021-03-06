/***********************IMPORTANT NPCAP LICENSE TERMS***********************
 *                                                                         *
 * Npcap is a Windows packet sniffing driver and library and is copyright  *
 * (c) 2013-2016 by Insecure.Com LLC ("The Nmap Project").  All rights     *
 * reserved.                                                               *
 *                                                                         *
 * Even though Npcap source code is publicly available for review, it is   *
 * not open source software and may not be redistributed or incorporated   *
 * into other software without special permission from the Nmap Project.   *
 * We fund the Npcap project by selling a commercial license which allows  *
 * companies to redistribute Npcap with their products and also provides   *
 * for support, warranty, and indemnification rights.  For details on      *
 * obtaining such a license, please contact:                               *
 *                                                                         *
 * sales@nmap.com                                                          *
 *                                                                         *
 * Free and open source software producers are also welcome to contact us  *
 * for redistribution requests.  However, we normally recommend that such  *
 * authors instead ask your users to download and install Npcap            *
 * themselves.                                                             *
 *                                                                         *
 * Since the Npcap source code is available for download and review,       *
 * users sometimes contribute code patches to fix bugs or add new          *
 * features.  By sending these changes to the Nmap Project (including      *
 * through direct email or our mailing lists or submitting pull requests   *
 * through our source code repository), it is understood unless you        *
 * specify otherwise that you are offering the Nmap Project the            *
 * unlimited, non-exclusive right to reuse, modify, and relicence your     *
 * code contribution so that we may (but are not obligated to)             *
 * incorporate it into Npcap.  If you wish to specify special license      *
 * conditions or restrictions on your contributions, just say so when you  *
 * send them.                                                              *
 *                                                                         *
 * This software is distributed in the hope that it will be useful, but    *
 * WITHOUT ANY WARRANTY; without even the implied warranty of              *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                    *
 *                                                                         *
 * Other copyright notices and attribution may appear below this license   *
 * header. We have kept those for attribution purposes, but any license    *
 * terms granted by those notices apply only to their original work, and   *
 * not to any changes made by the Nmap Project or to this entire file.     *
 *                                                                         *
 * This header summarizes a few important aspects of the Npcap license,    *
 * but is not a substitute for the full Npcap license agreement, which is  *
 * in the LICENSE file included with Npcap and also available at           *
 * https://github.com/nmap/npcap/blob/master/LICENSE.                      *
 *                                                                         *
 ***************************************************************************/
/*++

Module Name:

RegUtil.h

Abstract:

This is used for operating on registry.

--*/

#include <vector>
using namespace std;

#include "..\..\Common\WpcapNames.h"

#define		NPF_SOFT_REGISTRY_NAME_T			_T(NPF_SOFT_REGISTRY_NAME)
#define		NPF_DRIVER_NAME_SMALL_T				_T(NPF_DRIVER_NAME_SMALL)
#define		NPCAP_REG_KEY_NAME					_T("SOFTWARE\\") NPF_SOFT_REGISTRY_NAME_T
#define		NPCAP_SERVICE_REG_KEY_NAME			_T("SYSTEM\\CurrentControlSet\\Services\\") NPF_DRIVER_NAME_SMALL_T
#define		NPCAP_REG_LOOPBACK_VALUE_NAME		_T("LoopbackAdapter")
#define		NPCAP_REG_DOT11_VALUE_NAME		_T("Dot11Adapters")

typedef std::basic_string<TCHAR> tstring;

BOOL WriteStrToRegistry(LPCTSTR strSubKey, LPCTSTR strValueName, LPCTSTR strDeviceName, DWORD dwSamDesired);
BOOL DeleteValueFromRegistry(LPCTSTR strSubKey, LPCTSTR strValueName);
BOOL IncrementRegistryDword(LPCTSTR strSubKey, LPCTSTR strValueName, DWORD maxValue);

tstring printAdapterNames(vector<tstring> nstr);

BOOL addNpcapFolderToPath();
BOOL removeNpcapFolderFromPath();
