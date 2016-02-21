// Room: /d/new/huanhua/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
花木中的一条小路,两边是层层的藤蔓和花草,在头顶交织而成一道平
滑的空中绿廊,向西去是大厅,东面不远有一间房传来叮叮当当的声音.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/new");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaolu",
  "east" : __DIR__"river_room",
]));

	setup();
	replace_program(ROOM);
}
