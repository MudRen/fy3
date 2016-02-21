// thd:in_road5.c

inherit ROOM;

void create()
{
      set("short", "林间小路");
	set("long", @LONG
你走在一条小路上。四周静悄悄的，什么声音都没有，只是偶然传来
两、三声清脆的鸟鸣声。你甚至能听到桃花飘落的声响。到是南面传来轻
微的流水之声，停来十分悦耳。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 3 */
          "southeast" : __DIR__"bath_room",
	    "west" : __DIR__"square",
	    "east" : __DIR__"in_road6",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

