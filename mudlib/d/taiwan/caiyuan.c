// Room: /d/taiwan/caiyuan.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
一间下人居住的房间,里面只有一张小床,其余的地方摆满了各类杂 
物,不过各种东西都摆放得整整齐齐,看来主人是个爱清洁的人. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huayuan",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/huajian.c" : 1,
  __DIR__"obj/penghu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
