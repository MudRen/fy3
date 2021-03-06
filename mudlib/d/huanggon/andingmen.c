// Room: /d/huanggon/andingmen.c

inherit ROOM;

void create()
{
	set("short", "安定门");
	set("long", @LONG
安定门是京城的北门,出了安定门,就是漠北的苦寒之地,高大的城楼.
来往的人并不多,只有一些图暴利的商人,才出此门到蒙古.南边是地安门
广场,人潮阵阵.
LONG
	);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/menggu/huanglu1",
  "south" : __DIR__"guangchang1",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chengweibin.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
