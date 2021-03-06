/**
 * libdaijoubu
 * Copyright (C) 2015 David Jolly
 * ----------------------
 *
 * libdaijoubu is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libdaijoubu is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DAIJOUBU_DEFINES_H_
#define DAIJOUBU_DEFINES_H_

#include <cstdint>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>

namespace DAIJOUBU {

#ifndef _WIN32
	#define __in
	#define __in_opt
	#define __out
	#define __out_opt
	#define __inout
	#define __inout_opt
#endif // _WIN32

	#define EMPTY L"EMPTY"
	#define INVALID L"INVALID"
	#define UNKNOWN L"UNKNOWN"

	#define BUILD_VERSION_MAJOR 0
	#define BUILD_VERSION_MINOR 1
	#define BUILD_VERSION_REVISION 2
	#define BUILD_VERSION_WEEK 1532

	#define REFERENCE_INIT 1

	#define CHECK_STRING(_STRING_) \
		((_STRING_).empty() ? EMPTY : (_STRING_).c_str())

	#define _CONCAT_STRING(_STRING_) L ## # _STRING_
	#define CONCAT_STRING(_STRING_) _CONCAT_STRING(_STRING_)

	#define INVALID_TYPE(_TYPE_) ((_TYPE_) -1)

	#define _SERIALIZE_CALL(_TYPE_, _MUTEX_) \
		std::lock_guard<_TYPE_> __lock ## _MUTEX_(_MUTEX_)
	#define SERIALIZE_CALL(_MUTEX_) \
		_SERIALIZE_CALL(std::mutex, _MUTEX_)
	#define SERIALIZE_CALL_RECUR(_MUTEX_) \
		_SERIALIZE_CALL(std::recursive_mutex, _MUTEX_)

	#define UNREFERENCE_PARAMETER(_PARAM_) (void) _PARAM_

	#define VALUE_AS_HEX(_TYPE_, _VALUE_) \
		std::setw(sizeof(_TYPE_) * 2) << std::setfill(L'0') << std::hex \
		<< (uintmax_t) ((_TYPE_) (_VALUE_)) << std::dec

	#define VERSION_STRING \
		CONCAT_STRING(BUILD_VERSION_MAJOR) L"." CONCAT_STRING(BUILD_VERSION_MINOR) \
		L"." CONCAT_STRING(BUILD_VERSION_WEEK) L"." CONCAT_STRING(BUILD_VERSION_REVISION)
}

#endif // DAIJOUBU_DEFINES_H_
