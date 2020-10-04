//
// utility.h
//
// mt32-pi - A bare-metal Roland MT-32 emulator for Raspberry Pi
// Copyright (C) 2020  Dale Whinham <daleyo@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef _utility_h
#define _utility_h

// Macro to extract the string representation of an enum
#define CONFIG_ENUM_VALUE(VALUE, STRING) VALUE,

// Macro to extract the enum value
#define CONFIG_ENUM_STRING(VALUE, STRING) #STRING,

// Macro to declare the enum itself
#define CONFIG_ENUM(NAME, VALUES) enum class NAME { VALUES(CONFIG_ENUM_VALUE) }

// Macro to declare an array of string representations for an enum
#define CONFIG_ENUM_STRINGS(NAME, DATA) static const char* NAME##Strings[] = {DATA(CONFIG_ENUM_STRING)}

// Templated function for clamping a value between a minimum and a maximum
namespace Utility
{
	template <class T>
	static inline T Clamp(T value, T min, T max)
	{
		return (value < min) ? min : (value > max) ? max : value;
	}

	// Return number of elements in an array
	template<class T, size_t N>
	constexpr size_t ArraySize(const T(&)[N]) { return N; }
}

#endif