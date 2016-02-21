// Room: /d/wudang/road1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条官道，青石铺成。西面不远处便是成都府。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" :__DIR__"road2",
  "west":"/d/chengdu/tocd",
]));
        set("objects", ([
                __DIR__"npc/tufeitou" : 1]));
set("outdoors","/d/wudang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
