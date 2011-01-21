/*
 * Copyright (C) 2008-2011 Trinity <http://www.trinitycore.org/>
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

#ifndef __BattlegroundTP_H
#define __BattlegroundTP_H

class Battleground;

class BattlegroundTPScore : public BattlegroundScore
{
    public:
        BattlegroundTPScore() {};
        virtual ~BattlegroundTPScore() {};
};

class BattlegroundTP : public Battleground
{
    friend class BattlegroundMgr;

    public:
        BattlegroundTP();
        ~BattlegroundTP();
        void Update(uint32 diff);

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player *plr);
        virtual void StartingEventCloseDoors();
        virtual void StartingEventOpenDoors();

        void RemovePlayer(Player *plr, uint64 guid);
        void HandleAreaTrigger(Player *Source, uint32 Trigger);
        bool SetupBattleground();
        void EndBattleground(uint32 winner);

        /* Scorekeeping */
        void UpdatePlayerScore(Player *Source, uint32 type, uint32 value, bool doAddHonor = true);

    private:
};
#endif
