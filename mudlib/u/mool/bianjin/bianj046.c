// Room: bianj046.c
// mike.99.3.1
inherit ROOM;

void create()
{
	set("short", "�꾩���ô���");
	set("long",@LONG
LONG
);
       set("exits", ([ /* sizeof() == 2 */
            "north"  : __DIR__"bianj045",
            "south"  : __DIR__"bianj047",
       ]));
       set("outdoors", "city");
	setup();
       replace_program(ROOM);
}
