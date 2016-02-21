// Room: /d/lingjiu/men2.c

inherit ROOM;

void create()
{
	set("short", "书房大门");
	set("long", @LONG
这是书房门口，只看见大门两旁贴着一副对联(duilian)，抬头上望。
门楣上一块大匾(bian)上写着几个大字。
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 2 */
  "bian" : "[1;36m任我逍遥
[2;37;0m",
  "duilian" : "行到水穷处，坐看云起时.
",
]));
	set("objects", ([ /* sizeof() == 2 */
  "/daemon/class/lingjiu/zhujian.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"changl12",
  "east" : __DIR__"shufang",
]));
	set("outdoors", "lingjiu");

	setup();
	replace_program(ROOM);
}
