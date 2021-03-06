// Room: /d/new/huanhua/whitefeng.c

inherit ROOM;

void create()
{
	set("short", "白云峰");
	set("long", @LONG
白云峰是大娄山最高的山峰.举目望去,一片茫茫,乃是身在云海之中.
云层之中,一条小山道蜿蜒从南而北隐没在云层中.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tiewan-mo.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"road6",
  "northdown" : __DIR__"road5",
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/new");

	setup();
	replace_program(ROOM);
}
