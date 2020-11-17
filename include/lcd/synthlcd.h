//
// synthlcd.h
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

#ifndef _synthlcd_h
#define _synthlcd_h

#include <circle/types.h>

#include "lcd/clcd.h"

class CMT32Synth;

class CSynthLCD : public CCharacterLCD
{
public:
	enum class TSystemState
	{
		None,
		DisplayingMessage,
	};

	enum class TMT32State
	{
		DisplayingPartStates,
		DisplayingTimbreName,
		DisplayingMessage,
	};

	CSynthLCD();

	void OnSystemMessage(const char* pMessage);

	void OnMT32Message(const char* pMessage);
	void OnProgramChanged(u8 nPartNum, const char* pSoundGroupName, const char* pPatchName);

	virtual void Update(const CMT32Synth& Synth) = 0;

protected:
	void UpdatePartStateText(const CMT32Synth& Synth);
	void UpdatePartLevels(const CMT32Synth& Synth);
	void UpdatePeakLevels();

	// 20 characters plus null terminator
	static constexpr size_t TextBufferLength = 20 + 1;

	static constexpr unsigned SystemMessageDisplayTimeMillis = 3000;
	static constexpr unsigned MT32MessageDisplayTimeMillis = 200;
	static constexpr unsigned TimbreDisplayTimeMillis = 1200;

	static constexpr float BarFalloff  = 1.0f / 16.0f;
	static constexpr float PeakFalloff = 1.0f / 64.0f;

	// System state
	TSystemState m_SystemState;
	unsigned m_nSystemStateTime;
	char m_SystemMessageTextBuffer[TextBufferLength];

	// MT-32 state
	TMT32State m_MT32State;
	unsigned m_nMT32StateTime;
	char m_MT32TextBuffer[TextBufferLength];
	u8 m_nPreviousMasterVolume;
	float m_PartLevels[9];
	float m_PeakLevels[9];
	u8 m_PeakTimes[9];
};

#endif