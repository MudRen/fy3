// Room: /u/xizhen/room/chufang.c

inherit ROOM;

void create()
{
	set("short","密道");
	set("long", @LONG
这是条连接金风庄与参合山庄的密道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"south":__DIR__"midao1",
	"out":__DIR__"canhe/dating",
]));

	setup();
	replace_program(ROOM);
}
