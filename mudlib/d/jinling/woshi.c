// Room: /d/suzhou/woshi.c

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
这儿是个休息的好地方。
LONG
	);
	set("no_magic", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"kezhan",
]));
	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}
