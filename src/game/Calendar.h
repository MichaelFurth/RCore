/*
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOSSERVER_CALENDAR_H
#define MANGOSSERVER_CALENDAR_H

#include "Common.h"

// TODO - Get correct values
enum CalendarEventType
{
	CALENDARTYPE_RAID = 0,
	CALENDARTYPE_DUNGEON,
	CALENDARTYPE_PVP,
	CALENDARTYPE_MEETING,
	CALENDARTYPE_OTHER,
};

// TODO - Get correct values
enum CalendarInviteStatus
{
	CALENDARSTATUS_INVITED = 0,
	CALENDARSTATUS_ACCEPTED,
	CALENDARSTATUS_DECLINED,
	CALENDARSTATUS_TENTATIVE,
	CALENDARSTATUS_OUT,
	CALENDARSTATUS_STANDBY,
	CALENDARSTATUS_CONFIRMED,
};

struct CalendarEvent
{
	uint64 id;
	uint64 creator_guid;
	std::string name;
	std::string description;
	uint8 type;
	uint8 unk;
	uint32 dungeonID;
	uint32 unkTime;
	uint32 time;
	uint32 flags;
	uint32 guildID;
};

struct CalendarInvite
{
	uint64 id;
	uint64 event;
	uint8 status;
	uint8 rank;
	uint8 unk1;
	uint8 unk2;
	uint8 unk3;
	std::string text;
	uint64 creator_guid;
	uint32 time;
};

typedef std::map<uint64, CalendarInvite *> CalendarInviteMap;
typedef std::map<uint64, CalendarEvent *> CalendarEventMap;

#endif
