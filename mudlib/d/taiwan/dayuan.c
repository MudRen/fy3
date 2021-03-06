// Room: /d/taiwan/dayuan.c

inherit ROOM;

void create()
{
	set("short", "财主大院");
	set("long", @LONG
财主大院是个四方的院子,两边是厢房,正面是大厅,现在的院子里挤 
满了许多衣衫破烂的人,大多肩挑手抗着各种筐筐罐罐. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dianhu.c" : 1,
  __DIR__"npc/yuming.c" : 1,
]));
	set("outdoors", "/d/taiwan");
	set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"house3",
  "north" : __DIR__"zhangfang",
  "east" : __DIR__"ting.c",
]));

	setup();
	replace_program(ROOM);
}
