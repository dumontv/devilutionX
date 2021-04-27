/**
 * @file msg.h
 *
 * Interface of function for sending and reciving network messages.
 */
#pragma once

#include <cstdint>

#include "quests.h"
#include "objects.h"
#include "monster.h"
#include "portal.h"
#include "items.h"
#include "utils/endian_int.h"

namespace devilution {

#define MAX_SEND_STR_LEN 80
#define MAXMULTIQUESTS 10

enum _cmd_id : uint8_t {
	CMD_STAND,
	CMD_WALKXY,
	CMD_ACK_PLRINFO,
	CMD_ADDSTR,
	CMD_ADDMAG,
	CMD_ADDDEX,
	CMD_ADDVIT,
	CMD_SBSPELL,
	CMD_GETITEM,
	CMD_AGETITEM,
	CMD_PUTITEM,
	CMD_RESPAWNITEM,
	CMD_ATTACKXY,
	CMD_RATTACKXY,
	CMD_SPELLXY,
	CMD_TSPELLXY,
	CMD_OPOBJXY,
	CMD_DISARMXY,
	CMD_ATTACKID,
	CMD_ATTACKPID,
	CMD_RATTACKID,
	CMD_RATTACKPID,
	CMD_SPELLID,
	CMD_SPELLPID,
	CMD_TSPELLID,
	CMD_TSPELLPID,
	CMD_RESURRECT,
	CMD_OPOBJT,
	CMD_KNOCKBACK,
	CMD_TALKXY,
	CMD_NEWLVL,
	CMD_WARP,
	CMD_CHEAT_EXPERIENCE,
	CMD_CHEAT_SPELL_LEVEL,
	CMD_DEBUG,
	CMD_SYNCDATA,
	CMD_MONSTDEATH,
	CMD_MONSTDAMAGE,
	CMD_PLRDEAD,
	CMD_REQUESTGITEM,
	CMD_REQUESTAGITEM,
	CMD_GOTOGETITEM,
	CMD_GOTOAGETITEM,
	CMD_OPENDOOR,
	CMD_CLOSEDOOR,
	CMD_OPERATEOBJ,
	CMD_PLROPOBJ,
	CMD_BREAKOBJ,
	CMD_CHANGEPLRITEMS,
	CMD_DELPLRITEMS,
	CMD_PLRDAMAGE,
	CMD_PLRLEVEL,
	CMD_DROPITEM,
	CMD_PLAYER_JOINLEVEL,
	CMD_SEND_PLRINFO,
	CMD_SATTACKXY,
	CMD_ACTIVATEPORTAL,
	CMD_DEACTIVATEPORTAL,
	CMD_DLEVEL_0,
	CMD_DLEVEL_1,
	CMD_DLEVEL_2,
	CMD_DLEVEL_3,
	CMD_DLEVEL_4,
	CMD_DLEVEL_5,
	CMD_DLEVEL_6,
	CMD_DLEVEL_7,
	CMD_DLEVEL_8,
	CMD_DLEVEL_9,
	CMD_DLEVEL_10,
	CMD_DLEVEL_11,
	CMD_DLEVEL_12,
	CMD_DLEVEL_13,
	CMD_DLEVEL_14,
	CMD_DLEVEL_15,
	CMD_DLEVEL_16,
	CMD_DLEVEL_17,
	CMD_DLEVEL_18,
	CMD_DLEVEL_19,
	CMD_DLEVEL_20,
	CMD_DLEVEL_21,
	CMD_DLEVEL_22,
	CMD_DLEVEL_23,
	CMD_DLEVEL_24,
	CMD_DLEVEL_JUNK,
	CMD_DLEVEL_END,
	CMD_HEALOTHER,
	CMD_STRING,
	CMD_SETSTR,
	CMD_SETMAG,
	CMD_SETDEX,
	CMD_SETVIT,
	CMD_RETOWN,
	CMD_SPELLXYD,
	CMD_ITEMEXTRA,
	CMD_SYNCPUTITEM,
	CMD_KILLGOLEM,
	CMD_SYNCQUEST,
	CMD_ENDSHIELD,
	CMD_AWAKEGOLEM,
	CMD_NOVA,
	CMD_SETSHIELD,
	CMD_REMSHIELD,
	CMD_REFLECT,
	CMD_NAKRUL,
	CMD_OPENHIVE,
	CMD_OPENCRYPT,
	FAKE_CMD_SETID,
	FAKE_CMD_DROPID,
	NUM_CMDS,
	CMD_INVALID = 0xFF,
};

#pragma pack(push, 1)
struct TCmd {
	_cmd_id bCmd;
};

struct TCmdLoc {
	_cmd_id bCmd;
	uint8_t x;
	uint8_t y;
};

struct TCmdLocParam1 {
	_cmd_id bCmd;
	uint8_t x;
	uint8_t y;
	uint16_net_t wParam1;
};

struct TCmdLocParam2 {
	_cmd_id bCmd;
	uint8_t x;
	uint8_t y;
	uint16_net_t wParam1;
	uint16_net_t wParam2;
};

struct TCmdLocParam3 {
	_cmd_id bCmd;
	uint8_t x;
	uint8_t y;
	uint16_net_t wParam1;
	uint16_net_t wParam2;
	uint16_net_t wParam3;
};

struct TCmdParam1 {
	_cmd_id bCmd;
	uint16_net_t wParam1;
};

struct TCmdParam2 {
	_cmd_id bCmd;
	uint16_net_t wParam1;
	uint16_net_t wParam2;
};

struct TCmdParam3 {
	_cmd_id bCmd;
	uint16_net_t wParam1;
	uint16_net_t wParam2;
	uint16_net_t wParam3;
};

struct TCmdGolem {
	_cmd_id bCmd;
	uint8_t _mx;
	uint8_t _my;
	direction _mdir;
	int8_t _menemy;
	int32_net_t _mhitpoints;
	uint8_t _currlevel;
};

struct TCmdQuest {
	_cmd_id bCmd;
	uint8_t q;
	quest_state qstate;
	uint8_t qlog;
	uint8_t qvar1;
};

struct TCmdGItem {
	_cmd_id bCmd;
	uint8_t bMaster;
	uint8_t bPnum;
	uint8_t bCursitem;
	uint8_t bLevel;
	uint8_t x;
	uint8_t y;
	uint16_net_t wIndx;
	uint16_net_t wCI;
	int32_net_t dwSeed;
	uint8_t bId;
	uint8_t bDur;
	uint8_t bMDur;
	uint8_t bCh;
	uint8_t bMCh;
	uint16_net_t wValue;
	uint32_net_t dwBuff;
	int32_net_t dwTime;
	uint16_net_t wToHit;
	uint16_net_t wMaxDam;
	uint8_t bMinStr;
	uint8_t bMinMag;
	uint8_t bMinDex;
	int16_net_t bAC;
};

struct TCmdPItem {
	_cmd_id bCmd;
	uint8_t x;
	uint8_t y;
	uint16_net_t wIndx;
	uint16_net_t wCI;
	int32_net_t dwSeed;
	uint8_t bId;
	uint8_t bDur;
	uint8_t bMDur;
	uint8_t bCh;
	uint8_t bMCh;
	uint16_net_t wValue;
	uint32_net_t dwBuff;
	uint16_net_t wToHit;
	uint16_net_t wMaxDam;
	uint8_t bMinStr;
	uint8_t bMinMag;
	uint8_t bMinDex;
	int16_net_t bAC;
};

struct TCmdChItem {
	_cmd_id bCmd;
	uint8_t bLoc;
	uint16_net_t wIndx;
	uint16_net_t wCI;
	int32_net_t dwSeed;
	uint8_t bId;
	uint32_net_t dwBuff;
};

struct TCmdDelItem {
	_cmd_id bCmd;
	uint8_t bLoc;
};

struct TCmdDamage {
	_cmd_id bCmd;
	uint8_t bPlr;
	uint32_net_t dwDam;
};

struct TCmdMonDamage {
	_cmd_id bCmd;
	uint16_net_t wMon;
	uint32_net_t dwDam;
};

struct TCmdPlrInfoHdr {
	_cmd_id bCmd;
	uint16_net_t wOffset;
	uint16_net_t wBytes;
};

struct TCmdString {
	_cmd_id bCmd;
	char str[MAX_SEND_STR_LEN];
};

struct TFakeCmdPlr {
	_cmd_id bCmd;
	uint8_t bPlr;
};

struct TFakeDropPlr {
	_cmd_id bCmd;
	uint8_t bPlr;
	uint32_net_t dwReason;
};

struct TSyncHeader {
	_cmd_id bCmd;
	uint8_t bLevel;
	uint16_net_t wLen;
	uint8_t bObjId;
	uint8_t bObjCmd;
	uint8_t bItemI;
	uint8_t bItemX;
	uint8_t bItemY;
	uint16_net_t wItemIndx;
	uint16_net_t wItemCI;
	uint32_net_t dwItemSeed;
	uint8_t bItemId;
	uint8_t bItemDur;
	uint8_t bItemMDur;
	uint8_t bItemCh;
	uint8_t bItemMCh;
	uint16_net_t wItemVal;
	uint32_net_t dwItemBuff;
	uint8_t bPInvLoc;
	uint16_net_t wPInvIndx;
	uint16_net_t wPInvCI;
	uint32_net_t dwPInvSeed;
	uint8_t bPInvId;
	uint16_net_t wToHit;
	uint16_net_t wMaxDam;
	uint8_t bMinStr;
	uint8_t bMinMag;
	uint8_t bMinDex;
	uint8_t bAC;
};

struct TSyncMonster {
	uint8_t _mndx;
	uint8_t _mx;
	uint8_t _my;
	uint8_t _menemy;
	uint8_t _mdelta;
};

struct TPktHdr {
	uint8_t px;
	uint8_t py;
	uint8_t targx;
	uint8_t targy;
	int32_net_t php;
	int32_net_t pmhp;
	uint8_t bstr;
	uint8_t bmag;
	uint8_t bdex;
	uint16_net_t wCheck;
	uint16_net_t wLen;
};

struct TPkt {
	TPktHdr hdr;
	uint8_t body[493];
};

struct DMonsterStr {
	uint8_t _mx;
	uint8_t _my;
	direction _mdir;
	uint8_t _menemy;
	uint8_t _mactive;
	int32_net_t _mhitpoints;
};

struct DObjectStr {
	_cmd_id bCmd;
};

struct DLevel {
	TCmdPItem item[MAXITEMS];
	DObjectStr object[MAXOBJECTS];
	DMonsterStr monster[MAXMONSTERS];
};

struct LocalLevel {
	uint8_t automapsv[DMAXX][DMAXY];
};

struct DPortal {
	uint8_t x;
	uint8_t y;
	uint8_t level;
	uint8_t ltype;
	uint8_t setlvl;
};

struct MultiQuests {
	quest_state qstate;
	uint8_t qlog;
	uint8_t qvar1;
};

struct DJunk {
	DPortal portal[MAXPORTAL];
	MultiQuests quests[MAXMULTIQUESTS];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TMegaPkt {
	struct TMegaPkt *pNext;
	uint32_net_t dwSpaceLeft;
	uint8_t data[32000];
};
#pragma pack(pop)

struct TBuffer {
	uint32_t dwNextWriteOffset;
	uint8_t bData[4096];
};

extern bool deltaload;
extern BYTE gbBufferMsgs;
extern int dwRecCount;

void msg_send_drop_pkt(int pnum, int reason);
bool msg_wait_resync();
void run_delta_info();
void DeltaExportData(int pnum);
void delta_init();
void delta_kill_monster(int mi, BYTE x, BYTE y, BYTE bLevel);
void delta_monster_hp(int mi, int hp, BYTE bLevel);
void delta_sync_monster(const TSyncMonster *pSync, BYTE bLevel);
bool delta_portal_inited(int i);
bool delta_quest_inited(int i);
void DeltaAddItem(int ii);
void DeltaSaveLevel();
void DeltaLoadLevel();
void NetSendCmd(bool bHiPri, _cmd_id bCmd);
void NetSendCmdGolem(BYTE mx, BYTE my, direction dir, BYTE menemy, int hp, BYTE cl);
void NetSendCmdLoc(int playerId, bool bHiPri, _cmd_id bCmd, BYTE x, BYTE y);
void NetSendCmdLocParam1(bool bHiPri, _cmd_id bCmd, BYTE x, BYTE y, WORD wParam1);
void NetSendCmdLocParam2(bool bHiPri, _cmd_id bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2);
void NetSendCmdLocParam3(bool bHiPri, _cmd_id bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2, WORD wParam3);
void NetSendCmdParam1(bool bHiPri, _cmd_id bCmd, WORD wParam1);
void NetSendCmdParam2(bool bHiPri, _cmd_id bCmd, WORD wParam1, WORD wParam2);
void NetSendCmdParam3(bool bHiPri, _cmd_id bCmd, WORD wParam1, WORD wParam2, WORD wParam3);
void NetSendCmdQuest(bool bHiPri, BYTE q);
void NetSendCmdGItem(bool bHiPri, _cmd_id bCmd, BYTE mast, BYTE pnum, BYTE ii);
void NetSendCmdPItem(bool bHiPri, _cmd_id bCmd, BYTE x, BYTE y);
void NetSendCmdChItem(bool bHiPri, BYTE bLoc);
void NetSendCmdDelItem(bool bHiPri, BYTE bLoc);
void NetSendCmdDItem(bool bHiPri, int ii);
void NetSendCmdDamage(bool bHiPri, BYTE bPlr, DWORD dwDam);
void NetSendCmdMonDmg(bool bHiPri, WORD bMon, DWORD dwDam);
void NetSendCmdString(uint32_t pmask, const char *pszStr);
void delta_close_portal(int pnum);
DWORD ParseCmd(int pnum, TCmd *pCmd);

} // namespace devilution
