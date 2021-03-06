// Room: /d/quanzhou/nstreet3.c

inherit ROOM;

void create()
{
	set("short", "市中心");
	set("long", @LONG
市中心是泉州府最热闹的地方,来往的行人,卖花的女孩,叫喊的小 
贩,人圈围着的是卖杂耍的,吆五喝六闲逛的泼皮无赖,冷眼旁观的巡捕 
差役,组成了泉州的中心. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/quanzhou");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"nstreet2",
  "east" : __DIR__"estreet1",
  "west" : __DIR__"wstreet1",
]));
	set("valid_startroom", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yiren.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
