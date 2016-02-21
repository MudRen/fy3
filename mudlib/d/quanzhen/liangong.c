// liangong.c 练功房


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
	这里是全真教弟子练功的房间。这座房间形状甚是奇特，前窄
後宽，成为梯形，东边半圆，西边却作三角形状，原来这是全真教独有
的练功室，前窄练掌，後宽使拳，东圆研剑，西角发镖。房间中央立着
几个练功用的木人。
LONG
	);

	set("exits", ([
		"south" : __DIR__"houtang2",
		"north" : __DIR__"chanfang2",
	]));

	set("objects", ([
		__DIR__"npc/mu-ren" : 2,
	]));

	setup();
	replace_program(ROOM);
}