// Room: /d/lingjiu/daban.c

inherit ROOM;

void create()
{
	set("short", "缀锦阁");
	set("long", @LONG
这是日常梳妆打扮的地方，放着一张红木梳妆台 ， 正对着你的是一
面光润的铜镜(jingzi)，梳妆台上散落着一些胭脂花粉。台旁摆着斗大的
一个汝瓷花囊，插着满满的水晶球儿般的白菊。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
//  "jingzi" : (: look_jingzi :),
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"changl14",
]));

	setup();
	replace_program(ROOM);
}
