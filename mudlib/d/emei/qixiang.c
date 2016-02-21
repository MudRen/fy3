// Room: /d/emei/qixiang.c

inherit ROOM;

void create()
{
	set("short", "七香轩");
	set("long", @LONG
这是该寺方丈的居处,轩中仅摆了一个蒲团,一个香炉,插的几支香
正冒着缕缕青烟,俞添一种肃穆的神色,有个老尼姑正在打坐,看到你
进来,便站了起来.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huizong",
]));
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/feng.c" : 1,
]));
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
