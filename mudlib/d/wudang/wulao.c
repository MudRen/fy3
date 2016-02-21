// tyroad6.c 崎岖山路
// by Marz 

inherit ROOM;
//#include "feng.h"
void create()
{
	set("short", "五老峰");
	set("long", @LONG
	你走在五老峰的山路上，一边是峭壁，一边是悬崖。高高的天柱峰(feng)
笼罩在云雾中，隐约可见。可是身旁的进香客和游人都仔细地町着自己的脚下，不敢
抬头望一眼，惟恐一不小心摔下去。更有强人趁机打劫，行人无不噤声闭气，只求快
点敢路。
LONG
	);
	set("exits", ([
		"northup" : __DIR__"hutou",
		"southdown" : __DIR__"sanlao",
	]));

    set("objects", ([
    __DIR__"npc/ying" : 1,	
    ]));

	setup();
}

int valid_leave(object me,string dir)
{
	string fam;
	object npc;

	fam=(string)me->query("family/family_name");
	npc=present("yin litin",this_object());
	if(( !fam || fam!="武当派")&& dir=="northup"
	&& objectp(npc))
	return notify_fail("殷梨亭喝道：武当重地，闲人莫入！\n");
	return ::valid_leave(me,dir);
}

