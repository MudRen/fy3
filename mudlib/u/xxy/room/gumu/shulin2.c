// shulin2.c 树林
// By Lgg,1998.9

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
	你走在一条林间的小道上，四周都是树。远处似乎有一角建筑的
飞檐从树丛中露了出来，也许附近的山上有一座道观之类。这些树你大都
叫不出名字来，树龄都已经很长了。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"shulin3",
		"northeast" : __DIR__"shulin1",
	]));
	
	setup();
	replace_program(ROOM);
}

