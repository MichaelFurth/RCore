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

#ifndef MANGOS_CALENDAR_H
#define MANGOS_CALENDAR_H

#include <ace/Singleton.h>
#include "Calendar.h"

typedef std::map<uint64, CalendarInviteMap> CalendarPlayerInviteMap;
typedef std::map<uint64, CalendarEventMap> CalendarPlayerEventMap;

class CalendarMgr
{
    friend class ACE_Singleton<CalendarMgr, ACE_Null_Mutex>;
	CalendarMgr();
	~CalendarMgr();

	 public:
		 uint64 GetNextEventID()
		 {
			 return ++m_nextEventID;
		 }

		 uint64 GetNextInviteID()
		 {
			 return ++m_nextInviteID;
		 }

		 uint32 GetInviteCountForEvent(uint64 eventID)
		 {
			 return m_PlayerInvites[eventID].size();
		 }

		 CalendarInviteMap GetInviteMapForEvent(uint64 eventID)
		 {
			 return m_PlayerInvites[eventID];
		 }

	private:
		uint64 m_nextEventID;
		uint64 m_nextInviteID;
		CalendarEventMap m_Events;
		CalendarPlayerInviteMap m_PlayerInvites;
		CalendarPlayerEventMap m_PlayerEvents;
};

#define sCalendarMgr (*ACE_Singleton<CalendarMgr, ACE_Null_Mutex>::instance())

#endif