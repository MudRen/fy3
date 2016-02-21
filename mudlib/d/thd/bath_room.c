// thd:bath_room.c

inherit ROOM;

void create()
{
      set("short", "桃花池");
	set("long", @LONG
这是个十分干净的水池。它的源头就是弹指峰上的龙云泉，所以才有
怎么洁净。在水池边甚至能看的到水池底的鹅卵石。水池边还有一个挂衣
服的木架子。你看着这水，忍不住就想下水洗个澡。但如果你是女孩子，
可要当心别人偷窥喔！:-)
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
          "northwest" : __DIR__"in_road5",
	]));

	set("no_fight", 1);
	set("bath_room", 1);
	set("bath_equipment", "桃花池");
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

