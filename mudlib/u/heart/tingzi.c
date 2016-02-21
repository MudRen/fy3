// Room: /u/viviran/tingzi.c

inherit ROOM;

void create()
{
	set("short", "流芳亭");
	set("long", @LONG
这是北方著名的流芳亭。这里既有南方的植物又
有北方的。这里也有一个小池塘。池塘中各种金鱼嬉
戏游水。池塘边盛开着牡丹，刺梅和月季。回游些不
知名的小花，招来几只蝴蝶翩翩起舞。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"huayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
