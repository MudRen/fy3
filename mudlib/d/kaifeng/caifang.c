// Room: /d/kaifeng/caifang.c

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这间小柴房堆满了松柴，多是卖柴的汉子因为卖不出去而拿来换上一
餐的。也有些是穷苦人家上山砍了奉献给佛祖的，好在开封边的野猪林多
的是松树，所以倒也从没缺过柴禾。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/obj/chaihe1.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zoulang2",
  "east" : __DIR__"caidi3",
]));

	setup();
	replace_program(ROOM);
}
