// Room: /d/huanhua/dalu1.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条人来人往的大路,来往人流,车辆不断.北边是条大驿道，通向成都府。
西面的一片竹林青翠，听说穿过竹林就是浣花剑派的所在地。向南去，一座大
山险峻无比，那就是大娄山了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : "/d/chengdu/yidao2",
  "south" : __DIR__"dalu",
  "west" : __DIR__"bamboo4",
]));
	set("outdoors", "/d/new");
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dahan.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
