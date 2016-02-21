// Room: /d/hangzhou/erlou.c

inherit ROOM;

void create()
{
	set("short", "二楼");
	set("long", @LONG
楼外楼的二层人声鼎沸,在座的除了许多王孙公子,商贾富吏之外,
最多的还数文人墨客,诗兴来了,就在墙(wall)上即时而作.看一下,上面
佳作还不少.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/gaibang/hong.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"louwai",
]));

	setup();
set("item_desc",([
"wall":"山外青山楼外楼,西湖歌舞几时休,... ...\n",
]));
"/obj/board/hz_louboard"->foo();
	replace_program(ROOM);
}
