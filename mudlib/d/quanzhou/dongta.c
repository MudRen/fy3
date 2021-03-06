// Room: /d/quanzhou/dongta.c

inherit ROOM;

void create()
{
	set("short", "镇国塔");
	set("long", @LONG
一座八角五层攒顶式石塔,塔座为须弥座,通用白色花岗石筑成.每层
八面四门,塔身雕刻佛像,菩萨,金刚,天神,高僧和帝王,太子,居士及佛教
人物,檐间雕刻80尊守望神像,须弥座雕刻佛传图37方,台阶,扶栏各有不
同图案装饰.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jietai",
]));
	set("outdoors", "/d/quanzhou");

	setup();
	replace_program(ROOM);
}
