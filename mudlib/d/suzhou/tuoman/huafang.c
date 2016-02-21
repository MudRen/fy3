// Room: /d/suzhou/tuoman/huafang.c

inherit ROOM;

void create()
{
	set("short", "花肥房");
	set("long", @LONG
一进石屋，便见角落内的铁柱子上绑着个人，口中塞了什么东西，眼泪汪汪
的，却说不出话来。只见一个弓腰曲背的老婆子手中拿着一柄雪亮的长刀，身旁
一锅沸水，煮得直冒水气。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east":__DIR__"ru2",
]));
	set("objects",([
		__DIR__"npc/yan":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
