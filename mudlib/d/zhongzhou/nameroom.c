// Room: /d/zhongzhou/nameroom.c

inherit ROOM;

void create()
{
        set("short", "改名馆");
	set("long", @LONG
改名馆里空空荡荡，只有一个老头在昏昏欲睡.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wendingnan3",
]));
	set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/name" : 1,
]));

	setup();
	replace_program(ROOM);
}
