// Room: /d/quanzhou/estreet1.c

inherit ROOM;

void create()
{
	set("short", "东街");
	set("long", @LONG
东街是泉州府最热闹的一条街道.路上不时有满载着货物的车辆来
往,两边的店铺不断,街道北面是一座高大的衙门,就是泉州府了.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nstreet3",
  "east" : __DIR__"estreet2",
  "north" : __DIR__"yamen",
]));
	set("outdoors", "/d/quanzhou");

	setup();
	replace_program(ROOM);
}
