// Room: /d/quanzhou/nstreet1.c

inherit ROOM;

void create()
{
	set("short", "北街");
	set("long", @LONG
泉州城的北街拥挤着各色各样的人群,乡下的老农赶着牛车悠悠的 
走过,卖草鞋的后生大声地吆喝.整个街道热闹无比. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/quanzhou");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"citang",
  "south" : __DIR__"nstreet2",
  "north" : __DIR__"bei-door",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiangshi.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
