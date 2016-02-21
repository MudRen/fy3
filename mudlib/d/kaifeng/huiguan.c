// Room: /d/kaifeng/huiguan.c

inherit ROOM;

void create()
{
	set("short", "山陕甘会馆");
	set("long", @LONG
山陕甘会馆是山西，陕西，甘肃的富商巨贾建造的，是旅汴同乡聚会
的场所，就是给这三地的人聚会的。当然也有在此商谈生意的。里面就
是关帝庙。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"eroad2",
  "east" : __DIR__"paifang",
]));
	set("outdoors", "/d/kaifeng");

	setup();
	replace_program(ROOM);
}
