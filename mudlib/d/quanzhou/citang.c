// Room: /d/quanzhou/citang.c

inherit ROOM;

void create()
{
	set("short", "郭家祠堂");
	set("long", @LONG
郭家祠堂是一间很大的房子,里面的柱子都有两人合抱粗细,神台上
摆满了大大小小郭家列祖列宗的灵牌,一张长供桌上香烟缭绕,上面摆的
供品却只剩下半个吃剩发黄的馒头.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/gaibang/lu.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"nstreet1",
]));

	setup();
	replace_program(ROOM);
}
