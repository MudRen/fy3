// Room: /d/taiwan/midao1.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
一条漆黑的密道,耳边隐隐听到老鼠跑过的声音,你不敢大意,小心地
摸着粗糙的石壁向前走.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/lengtanyue.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"midao2",
  "up" : __DIR__"midao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
