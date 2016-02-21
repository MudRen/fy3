// Room: /d/hangzhou/dadao2.c

inherit ROOM;

void create()
{
	set("short", "武林大道");
	set("long", @LONG
一条横贯南北的大道.可容十马并驾齐驱.道旁遍植柳树.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youke.c" : 2,
]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"dadao3",
  "west" : __DIR__"shuangf",
  "north" : __DIR__"wuchang.c",
]));
	set("outdoors", "/d/hangzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
