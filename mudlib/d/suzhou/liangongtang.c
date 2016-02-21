// Room: /d/suzhou/liangongtang.c

inherit ROOM;

void create()
{
	set("short","防具铺");
	set("long", @LONG
这儿是苏州最有名的防具铺，你可以在这儿买到任何防具。此家铺子的老板
约四十出头，正在整理着什么。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"chengnanjie3",
]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/fang":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
